/*
 *  ibex - device specific stuff
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


#ifndef DEVICE_H_included
#define DEVICE_H_included

#define AES_ENCRYPT		0x10
#define AES_DECRYPT		0x11

#define KBAG_IV_SIZE		0x10
#define KBAG_KEY_SIZE		0x20
#define KBAG_KEY_IV_SIZE	(KBAG_IV_SIZE + KBAG_KEY_SIZE)

#define GID_KEY			0x20000200
#define UID_KEY			0x20000201

#endif
