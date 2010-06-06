#  ibex - main makefile
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


.PHONY: all clean distclean

GNUARM_PREFIX ?= arm-elf-
TARGET ?= iPhone2,1/7D11/iBoot

CC = $(GNUARM_PREFIX)gcc
CFLAGS = -Wall -W -pedantic
CFLAGS += -O2
#CFLAGS = -mthumb-interwork

LD = $(GNUARM_PREFIX)gcc
LDFLAGS = -nostdlib
LDFLAGS += -Tscript.ld
LDLIBS =

OBJCOPY = $(GNUARM_PREFIX)objcopy

include bundles/$(TARGET)/target.mak

SOURCES = \
	plib.c \
	main.c

OBJECTS = $(SOURCES:.c=.o)

.S.o:
	$(CC) -o $@ $(CFLAGS) -c $<

.c.o:
	$(CC) -o $@ $(CFLAGS) -c $<

all: $(HOOKER) payload

hooker: bundles/$(TARGET)
	make -C $< GNUARM_PREFIX=$(GNUARM_PREFIX) DESTDIR=$(shell pwd)

payload: payload.elf
	$(OBJCOPY) -O binary $< $@

payload.elf: $(OBJECTS) | entry.o
	$(LD) -o $@ $(LDFLAGS) $^ $(LDLIBS)

clean:
	-$(RM) *.o *.elf

distclean: clean
	-$(RM) hooker payload
