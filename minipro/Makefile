# Install Configuration

# Your C compiler
CC=gcc
#CC=clang

# Compiler options
CFLAGS ?= -g -O0 -Wall -Wextra -W -Wno-sign-compare -Wno-unused-parameter
CPPFLAGS += -DSHARE_INSTDIR="\"$(SHARE_INSTDIR)\""
LDFLAGS ?=

# Normally minipro is installed to /usr/local.  If you want to put it
# somewhere else, define that location here.
PREFIX ?= /usr/local
MANDIR ?= $(PREFIX)/share/man

# Some older releases of MacOS need some extra library flags.
#EXTRA_LIBS += "-framework Foundation -framework IOKit"


#########################################################################
# This section is where minipro is actually built.
# Under normal circumstances, nothing below this point should be changed.
##########################################################################

NAME = minipro
VERSION = 0.7

# If we're working from git, we have access to proper variables. If
# not, make it clear that we're working from a release.
#
GIT_DIR ?= .git
ifneq ($(and $(wildcard $(GIT_DIR)),$(shell which git)),)
        GIT_BRANCH = $(shell git rev-parse --abbrev-ref HEAD)
        GIT_HASH = $(shell git rev-parse HEAD)
        GIT_HASH_SHORT = $(shell git rev-parse --short HEAD)
        GIT_DATE = $(shell git show -s --format=%ci)
else
        GIT_BRANCH = $(shell echo "$Format:%D$" | sed s/^.*\>\\s*//)
        GIT_HASH = "$Format:%H$"
        GIT_HASH_SHORT = "$Format:%h$"
        GIT_DATE = "$Format:%ci$"
endif
BUILD_DATE = $(shell date "+%Y-%m-%d %H:%M:%S %z")
VERSION_HEADER = version.h
VERSION_STRINGS = version.c
VERSION_OBJ = version.o

PKG_CONFIG := $(shell which pkg-config 2>/dev/null)
ifeq ($(PKG_CONFIG),)
        ERROR := $(error "pkg-config utility not found")
endif

ifeq ($(OS),Windows_NT)
    USB = usb_win.o
else
    USB = usb_nix.o
endif

COMMON_OBJECTS=xml.o jedec.o ihex.o srec.o database.o bitbang.o prom.o \
               minipro.o tl866a.o tl866iiplus.o t48.o t56.o version.o $(USB)
OBJECTS=$(COMMON_OBJECTS) main.o
PROGS=minipro
STATIC_LIB=libminipro.a
MINIPRO=minipro
INFOIC=infoic.xml
LOGICIC=logicic.xml
TESTS=$(wildcard tests/test_*.c);
OBJCOPY?=objcopy

DIST_DIR = $(MINIPRO)-$(VERSION)
BIN_INSTDIR=$(DESTDIR)$(PREFIX)/bin
LIB_INSTDIR=$(DESTDIR)$(PREFIX)/lib
SHARE_INSTDIR=$(DESTDIR)$(PREFIX)/share/minipro
INCLUDE_INSTDIR=$(DESTDIR)$(PREFIX)/include/libminipro
MAN_INSTDIR=$(DESTDIR)$(PREFIX)/share/man/man1

UDEV_DIR=$(shell $(PKG_CONFIG) --define-variable=prefix=$(PREFIX) --silence-errors --variable=udevdir udev)
UDEV_RULES_INSTDIR=$(DESTDIR)$(UDEV_DIR)/rules.d

COMPLETIONS_DIR=$(shell $(PKG_CONFIG) --define-variable=prefix=$(PREFIX) --silence-errors --variable=completionsdir bash-completion)
COMPLETIONS_INSTDIR=$(DESTDIR)$(COMPLETIONS_DIR)

ifneq ($(OS),Windows_NT)
    libusb_CFLAGS := $(shell $(PKG_CONFIG) --cflags libusb-1.0)
    libusb_LIBS := $(shell $(PKG_CONFIG) --libs libusb-1.0)

    ifeq ($(libusb_LIBS),)
        ERROR := $(error "libusb-1.0 not found")
    endif
    override CFLAGS += $(libusb_CFLAGS)
    override LIBS += $(libusb_LIBS) $(EXTRA_LIBS)
else
# Add Windows libs here
override LIBS += -lsetupapi \
                 -lwinusb
endif


all: $(PROGS)

$(VERSION_HEADER):
	@echo "Creating $@"
	@echo "/*" > $@
	@echo " * This file is automatically generated.  Do not edit." >> $@
	@echo " */" >> $@
	@echo "#define VERSION \"$(VERSION)\"" >> $@
	@echo "#define GIT_BRANCH \"$(GIT_BRANCH)\"" >> $@
	@echo "#define GIT_HASH \"$(GIT_HASH)\"" >> $@
	@echo "#define GIT_HASH_SHORT \"$(GIT_HASH_SHORT)\"" >> $@
	@echo "#define GIT_DATE \"$(GIT_DATE)\"" >> $@

$(VERSION_STRINGS):
	@echo "Creating $@"
	@echo "/*" > $@
	@echo " * This file is automatically generated.  Do not edit." >> $@
	@echo " */" >> $@
	@echo "#include \"minipro.h\"" >> $@
	@echo "#include \"version.h\"" >> $@

$(OBJECTS): $(VERSION_HEADER)

minipro: $(VERSION_STRINGS) $(COMMON_OBJECTS) main.o
	$(CC) $(LDFLAGS) $(COMMON_OBJECTS) main.o $(LIBS) -o $(MINIPRO)

library: $(VERSION_STRINGS) $(COMMON_OBJECTS)
	ar ru $(STATIC_LIB) $(VERSION_OBJ) $(COMMON_OBJECTS)
	ranlib $(STATIC_LIB)

clean:
	rm -f $(OBJECTS) $(PROGS)
	rm -f $(STATIC_LIB)
	rm -f version.h version.c version.o

distclean: clean
	rm -rf $(DIST_DIR)*

install:
	mkdir -p $(BIN_INSTDIR)
	mkdir -p $(MAN_INSTDIR)
	mkdir -p $(SHARE_INSTDIR)
	cp $(MINIPRO) $(BIN_INSTDIR)/
	cp $(INFOIC) $(SHARE_INSTDIR)/
	cp $(LOGICIC) $(SHARE_INSTDIR)/
	cp man/minipro.1 $(MAN_INSTDIR)/
	if [ -n "$(UDEV_DIR)" ]; then \
		mkdir -p $(UDEV_RULES_INSTDIR); \
		cp udev/60-minipro.rules $(UDEV_RULES_INSTDIR)/; \
		cp udev/61-minipro-plugdev.rules $(UDEV_RULES_INSTDIR)/; \
		cp udev/61-minipro-uaccess.rules $(UDEV_RULES_INSTDIR)/; \
	fi
	if [ -n "$(COMPLETIONS_DIR)" ]; then \
		mkdir -p $(COMPLETIONS_INSTDIR); \
		cp bash_completion.d/minipro $(COMPLETIONS_INSTDIR)/; \
	fi

uninstall:
	rm -f $(BIN_INSTDIR)/$(MINIPRO)
	rm -f $(SHARE_INSTDIR)/$(INFOIC)
	rm -f $(SHARE_INSTDIR)/$(LOGICIC)
	rm -f $(MAN_INSTDIR)/minipro.1
	if [ -n "$(UDEV_DIR)" ]; then rm -f $(UDEV_RULES_INSTDIR)/60-minipro.rules; fi
	if [ -n "$(UDEV_DIR)" ]; then rm -f $(UDEV_RULES_INSTDIR)/61-minipro-plugdev.rules; fi
	if [ -n "$(UDEV_DIR)" ]; then rm -f $(UDEV_RULES_INSTDIR)/61-minipro-uaccess.rules; fi
	if [ -n "$(COMPLETIONS_DIR)" ]; then rm -f $(COMPLETIONS_INSTDIR)/minipro; fi

install_library:
	mkdir -p $(LIB_INSTDIR)
	mkdir -p $(INCLUDE_INSTDIR)
	mkdir $(LIB_INSTDIR)/pkgconfig
	cp $(STATIC_LIB) $(LIB_INSTDIR)/
	cp *.h $(INCLUDE_INSTDIR)/
	cp libminipro.pc $(LIB_INSTDIR)/pkgconfig/
	sed -e "s#MINIPROPREFIX#$(DESTDIR)$(PREFIX)#" -i "" "$(LIB_INSTDIR)/pkgconfig/libminipro.pc"
	sed -e "s#MINIPROVERSION#$(VERSION)#" -i "" "$(LIB_INSTDIR)/pkgconfig/libminipro.pc"
	ln -s "$(LIB_INSTDIR)/pkgconfig/libminipro.pc" /usr/local/lib/pkgconfig/libminipro.pc

uninstall_library:
	rm /usr/local/lib/pkgconfig/libminipro.pc
	rm -f $(LIB_INSTDIR)/pkgconfig/libminipro.pc
	rm -f $(LIB_INSTDIR)/$(STATIC_LIB)
	rm -f $(INCLUDE_INSTDIR)/*.h
	rmdir $(INCLUDE_INSTDIR)

deb: distclean
	dpkg-buildpackage -b -rfakeroot -us -uc

dist:
ifneq ($(and $(wildcard $(GIT_DIR)),$(shell which git)),)
	git archive --format=tgz --prefix $(DIST_DIR)/ HEAD -o $(DIST_DIR).tar.gz
	@echo Created $(DIST_DIR).tar.gz
else
	@echo "Not in a git repository or git command not found.  Cannot make a tarball."
endif


.PHONY: all dist distclean clean install test version-info
