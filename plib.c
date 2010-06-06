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


#include "offsets.h"
#include "plib.h"


#ifdef TARGET_PRINTF
printf_t printf_ = (printf_t)(TARGET_BASEADDR + TARGET_PRINTF);
#endif

#ifdef TARGET_VPRINTF
vprintf_t vprintf_ = (vprintf_t)(TARGET_BASEADDR + TARGET_VPRINTF);
#endif

#ifdef TARGET_STRCMP
strcmp_t strcmp_ = (strcmp_t)(TARGET_BASEADDR + TARGET_STRCMP);
#endif

#ifdef TARGET_ISSPACE
isspace_t isspace_ = (isspace_t)(TARGET_BASEADDR + TARGET_ISSPACE);
#endif

#ifdef TARGET_MALLOC
malloc_t malloc_ = (malloc_t)(TARGET_BASEADDR + TARGET_MALLOC);
#endif

#ifdef TARGET_FREE
free_t free_ = (free_t)(TARGET_BASEADDR + TARGET_FREE);
#endif

#ifdef TARGET_AES_CRYPTO_CMD
aes_crypto_cmd_t aes_crypto_cmd_ = (aes_crypto_cmd_t)(TARGET_BASEADDR + TARGET_AES_CRYPTO_CMD);
#endif

#ifdef TARGET_ENTER_CRITICAL_SECTION
enter_critical_section_t enter_critical_section_ = (enter_critical_section_t)(TARGET_BASEADDR + TARGET_ENTER_CRITICAL_SECTION);
#endif

#ifdef TARGET_EXIT_CRITICAL_SECTION
exit_critical_section_t exit_critical_section_ = (exit_critical_section_t)(TARGET_BASEADDR + TARGET_EXIT_CRITICAL_SECTION);
#endif
