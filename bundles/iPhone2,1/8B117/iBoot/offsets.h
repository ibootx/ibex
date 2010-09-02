/*
 *  ibex - target specific addresses
 *
 *  Copyright (c) 2010 ibootx
 *
 *  Props: Dev-Team, p0sixninja, westbaer, msft.guy, DarkMalloc, et al.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */


#ifndef OFFSETS_H_included
#define OFFSETS_H_included

#define TARGET_BASEADDR			0x4FF00000

#define TARGET_PRINTF			(0x20538 + 1)
#define TARGET_VPRINTF			(0x204E8 + 1)
#define TARGET_STRCMP			(0x2056C + 1)
#define TARGET_ISSPACE			(0x20E94 + 1)
#define TARGET_MALLOC			(0x0DB30 + 1)
#define TARGET_FREE			(0x0D0D8 + 1)
#define TARGET_AES_CRYPTO_CMD		(0x132E0 + 1)
#define TARGET_ENTER_CRITICAL_SECTION	(0x11B04 + 1)
#define TARGET_EXIT_CRITICAL_SECTION	(0x11AB4 + 1)

#endif
