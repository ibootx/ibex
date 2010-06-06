@  ibex - payload setup: inject a new command which calls payload by request
@
@  Copyright (c) 2010 ibootx
@
@  Props: Dev-Team, p0sixninja, westbaer, msft.guy, DarkMalloc, et al.
@
@ This program is free software; you can redistribute it and/or modify
@ it under the terms of the GNU General Public License as published by
@ the Free Software Foundation; either version 2 of the License, or
@ (at your option) any later version.
@
@ This program is distributed in the hope that it will be useful,
@ but WITHOUT ANY WARRANTY; without even the implied warranty of
@ MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
@ GNU General Public License for more details.
@
@ You should have received a copy of the GNU General Public License
@ along with this program; if not, write to the Free Software
@ Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA


.set irq_vector, 0x00000038
.set irq_handler, 0x4FF1AB08

.set patch0, 0x4FF15978	@ 'PROD'
.set patch1, 0x4FF159EE	@ 'SEPO'
.set patch2, 0x4FF15A38	@ 'ECID'
.set patch3, 0x4FF1D8BC

#ifdef ADD_COMMAND
.set ptr_cmd_list, 0x4FF19970
.set ptr_cmd_list_end, 0x4FF19974
#else
.set reset_cmd_nameptr, 0x4FF21A04
.set reset_cmd_handler, 0x4FF26EE8
#endif

.set payload_addr, 0x41002000

	.arm
	.text

	.global	_start
_start:
	@ save registers
	stmfd	sp!, {r0-r1}

	@ restore irq vector
	ldr	r1, =irq_handler
	ldr	r0, =irq_vector
	str	r1, [r0]

	@ pwn iBoot to accept untrusted images (if not pwned already)
	ldr	r1, =0x20002000
	ldr	r0, =patch0
	str	r1, [r0]
	ldr	r0, =patch1
	str	r1, [r0]
	ldr	r0, =patch2
	str	r1, [r0]
	ldr	r0, =patch3
	str	r1, [r0]

#ifdef ADD_COMMAND
	@ replace commands array to add a new command
	adr	r1, cmd_list
	ldr	r0, =ptr_cmd_list
	str	r1, [r0]
	adr	r1, cmd_list_end
	ldr	r0, =ptr_cmd_list_end
	str	r1, [r0]
#else
	@ replace reset command with pwn, set handler to payload_addr
	ldr	r1, =0x6E7770
	ldr	r0, =reset_cmd_nameptr
	str	r1, [r0]
	ldr	r1, =payload_addr
	ldr	r0, =reset_cmd_handler
	str	r1, [r0]
#endif

	@ clear instruction cache
	mov	r0, #0
	mcr	p15, 0, r0, c7, c5
	nop
	nop
	nop
	nop

	@ restore registers
	ldmfd	sp!, {r0-r1}

	@ branch to original handler
	ldr	pc, =irq_handler

#ifdef ADD_COMMAND
cmd_list:
	.word	pwn_cmd
	.word	0x4FF26E9C	@ bootx
	.word	0x4FF26EF4	@ reboot
	.word	0x4FF26EE4	@ reset
	.word	0x4FF26ED4	@ bgcolor
	.word	0x4FF26EC4	@ setpicture
	.word	0x4FF26F04	@ go
	.word	0x4FF26F14	@ ramdisk
	.word	0x4FF28764	@ devicetree
	.word	0x4FF28D08	@ getenv
	.word	0x4FF28CF8	@ setenv
	.word	0x4FF28CE8	@ saveenv
cmd_list_end:

pwn_cmd:
	.word	pwn_cmd_name
	.word	payload_addr
	.word	pwn_cmd_help
	.word	0

pwn_cmd_name:
	.asciz	"pwn"
	.align	2
pwn_cmd_help:
	.asciz	"call payload_addr"
	.align	2
#endif
