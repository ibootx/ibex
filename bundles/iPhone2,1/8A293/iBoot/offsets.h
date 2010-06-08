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

#define TARGET_PRINTF			(0x1F8D4 + 1)
#define TARGET_VPRINTF			(0x1F884 + 1)
#define TARGET_STRCMP			(0x1F908 + 1)
#define TARGET_ISSPACE			(0x20230 + 1)
#define TARGET_MALLOC			(0x0D8C4 + 1)
#define TARGET_FREE			(0x0CE6C + 1)
#define TARGET_AES_CRYPTO_CMD		(0x12FEC + 1)
#define TARGET_ENTER_CRITICAL_SECTION	(0x11850 + 1)
#define TARGET_EXIT_CRITICAL_SECTION	(0x11800 + 1)

#endif
