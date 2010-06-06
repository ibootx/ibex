/*
 *  ibex - payload
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


#include "plib.h"
#include "device.h"


static void
hex2str(char *str, const unsigned char *buf, int len)
{
    static const char h2a[] = "0123456789ABCDEF";
    for (; len > 0; --len) {
	unsigned char byte = *buf++;
	*str++ = h2a[byte >> 4];
	*str++ = h2a[byte & 0xF];
    }
    *str = '\0';
}


static int
str2hex(int max, unsigned char *buf, const char *str)
{
    unsigned char *ptr = buf;
    int seq = -1;
    while (max > 0) {
	int nibble = *str++;
	if (nibble >= '0' && nibble <= '9') {
	    nibble -= '0';
	} else if (nibble >= 'a' && nibble <= 'f') {
	    nibble -= 'a' - 10;
	} else if (nibble >= 'A' && nibble <= 'F') {
	    nibble -= 'A' - 10;
	} else {
	    break;
	}
	if (seq >= 0) {
	    *buf++ = (seq << 4) | nibble;
	    max--;
	    seq = -1;
	} else {
	    seq = nibble;
	}
    }
    return buf - ptr;
}


int
_main(int argc, CmdArg *argv)
{
    int buflen;
    unsigned char tmpbuf[KBAG_KEY_IV_SIZE];
    unsigned char outbuf[KBAG_KEY_IV_SIZE];
    char strbuf[KBAG_KEY_IV_SIZE * 2 + 1];

    if (argc != 2) {
	printf_("%s <kbag>\n", argv[0].string);
	return 0;
    }

    buflen = str2hex(sizeof(tmpbuf), tmpbuf, argv[1].string);

    aes_crypto_cmd_(AES_DECRYPT, (void *)tmpbuf, (void *)outbuf, buflen, GID_KEY, 0, 0);

    hex2str(strbuf, outbuf, buflen);
    printf_("out: %s\n", strbuf);

    return 0;
}
