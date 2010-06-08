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


.set patch0, 0x4FF0DD20	@ 'PROD'
.set patch1, 0x4FF0DDB2	@ 'SEPO'
.set patch2, 0x4FF0DDD6	@ 'CEPO'
.set patch3, 0x4FF0DE18	@ 'ECID'
.set patch4, 0x4FF16240
.set patchval, 0x20002000

#ifdef ADD_COMMAND
.set ptr_cmd_list, 0x4FF11AB8
.set ptr_cmd_list_end, 0x4FF11ABC
#else
.set reset_cmd_nameadr, 0x4FF209B0
.set reset_cmd_handler, 0x4FF26340
#endif

.set payload_addr, 0x41000000

	.arm
	.text

	.global	_start
_start:
	@ pwn iBoot to accept untrusted images (if not pwned already)
@	[patch0] = 0x20002000
@	[patch1] = 0x20002000
@	[patch2] = 0x20002000
@	[patch3] = 0x20002000
@	[patch4] = 0x20002000

#ifdef ADD_COMMAND
	@ replace commands array to add a new command
@	[ptr_cmd_list] = cmd_list
@	[ptr_cmd_list_end] = cmd_list_end
#else
	@ replace reset command with pwn, set handler to payload_addr
@	[reset_cmd_nameadr] = 0x6E7770
@	[reset_cmd_handler] = payload_addr
#endif

#ifdef ADD_COMMAND
cmd_list:
	.word	pwn_cmd
	.word	0x4FF2634C	@ reboot
	.word	0x4FF2633C	@ reset
	.word	0x4FF2635C	@ go
	.word	0x4FF26F18	@ getenv
	.word	0x4FF26F08	@ setenv
	.word	0x4FF26EF8	@ saveenv
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
