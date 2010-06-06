#  ibex - payload setup makefile
#
#  Copyright (c) 2010 ibootx
#
#  Props: Dev-Team, p0sixninja, westbaer, msft.guy, DarkMalloc, et al.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA


GNUARM_PREFIX ?= arm-elf-
DESTDIR ?= .

CC = $(GNUARM_PREFIX)gcc
CFLAGS = -Wall -W -pedantic
CFLAGS += -O2

LD = $(GNUARM_PREFIX)gcc
LDFLAGS = -nostdlib
LDFLAGS += -Ttext=0x4FF000E0 -Wl,-e,_start
LDLIBS =

OBJCOPY = $(GNUARM_PREFIX)objcopy

SOURCES = \
	hooker.S

OBJECTS = $(SOURCES:.S=.o)

$(DESTDIR)/%.o: %.S
	$(CC) -o $@ $(CFLAGS) -c $<

$(DESTDIR)/hooker: $(DESTDIR)/hooker.elf
	$(OBJCOPY) -O binary $< $@

$(DESTDIR)/hooker.elf: $(addprefix $(DESTDIR)/,$(OBJECTS))
	$(LD) -o $@ $(LDFLAGS) $^ $(LDLIBS)
