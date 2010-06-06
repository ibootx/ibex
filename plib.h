/*
 *  ibex - pseudo-library
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


#ifndef PLIB_H_included
#define PLIB_H_included

#include <stdarg.h>

typedef struct CmdArg {
    signed int unk1;
    unsigned int uinteger;
    signed int integer;
    unsigned int type;
    char *string;
} CmdArg;

typedef int (*printf_t) (const char *fmt, ...);
extern printf_t printf_;

typedef int (*vprintf_t) (const char *fmt, va_list args);
extern vprintf_t vprintf_;

typedef int (*strcmp_t)(const char *s1, const char *s2);
extern strcmp_t strcmp_;

typedef int (*isspace_t)(int c);
extern isspace_t isspace_;

typedef void *(*malloc_t)(unsigned int size);
extern malloc_t malloc_;

typedef void *(*free_t)(unsigned int size);
extern free_t free_;

typedef void (*aes_crypto_cmd_t)(int crypt_type, void *inbuf, void *outbuf, unsigned int inbuf_len, unsigned int aes_key_type, char *key, char *iv);
extern aes_crypto_cmd_t aes_crypto_cmd_;

typedef void (*enter_critical_section_t)(void);
extern enter_critical_section_t enter_critical_section_;

typedef void (*exit_critical_section_t)(void);
extern exit_critical_section_t exit_critical_section_;

#endif
