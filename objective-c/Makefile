### Makefile --- 
## 
## Filename: Makefile
## Description: Makefile for structure
## Author: Bigclean Cheng
## Created: Aug 25 2010 16:36
## Last-Updated: Thu Dec 15, 23:59 2011
### Code:

SHELL    := /bin/sh
PROJECT  := structure
VERSION  := 0.1beta
DIRECTORY := $(PROJECT)-$(VERSION)
CC = gcc
AR = ar
ARFLAGS = -r
VPATH  = ./

# Physical path variable 'C:\GNUstep\GNUstep\System\Tools' and
# 'C:\GNUstep\mingw32\bin' should be appended to $PATH environment
# variable in Windows.
ifdef COMSPEC
    LIB_HDRS = /cygdrive/c/GNUstep/GNUstep/System/Library/Headers
    LIB_LIBS = /cygdrive/c/GNUstep/GNUstep/System/Library/Libraries
    #LIB_HDRS = /GNUstep/System/Library/Headers
    #LIB_LIBS = /GNUstep/System/Library/Libraries
else
    # FreeBSD only
    LIB_HDRS = /usr/local/GNUstep/System/Library/Headers
    LIB_LIBS = /usr/local/GNUstep/System/Library/Libraries
endif

CFLAGS = -Wall -fconstant-string-class=NSConstantString
CPPFLAGS = -I$(LIB_HDRS)
LDFLAGS = -L$(LIB_LIBS) -lobjc -lgnustep-base

# SRCS is the source files list(*.c)
# literal way sources
SOURCES    := NSLinkNode.m NSLinkList.m
OBJECTS    := $(patsubst %.m, %.o, $(SOURCES))
TARGET     := sample
ifdef COMSPEC
    EXECUTABLE := $(TARGET).exe
else
    EXECUTABLE := $(TARGET)
endif

DOXYGEN  := doxygen
DOXYFILE := $(PROJECT).Doxyfile
CP       := cp -ir
MV       := mv -if
RM       := rm -rf
MKDIR    := mkdir -p
TAR      := tar -cjf
FIND     := find
CTAGS    := ctags -R
CSCOPE   := cscope -Rb

# echo colorize output
HIGH     := \033[7m
LIGHT    := \033[0m

.PHONY: all clean distclean doc dist TAGS

all: $(OBJECTS)
	@echo "------------------------------------------------------------"
	@echo -e "\t$(HIGH) Building... $(LIGHT)"
	$(AR) -r lib$(PROJECT).a $(OBJECTS)
	$(CC) sample.m $(OBJECTS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -L. -l$(PROJECT) -o $(EXECUTABLE)
	@echo "------------------------------------------------------------"

# Be very careful about the -lobjc and -lgnustep-base switch,
# they must appear after file name "sample.m", otherwise linking will fail.
%.o: %.m
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

doc:
	@echo "------------------------------------------------------------"
	@echo -e "\t$(HIGH) Generate docments via doxygen $(LIGHT)"
	$(DOXYGEN) $(DOXYFILE)
	@echo "------------------------------------------------------------"

clean:
	@echo "------------------------------------------------------------"
	@echo -e "\t$(HIGH) Clean $(LIGHT)"
	-$(RM) $(OBJECTS)
	-$(RM) $(EXECUTABLE)
	@echo "------------------------------------------------------------"

distclean: clean
	@echo "------------------------------------------------------------"
	@echo -e "\t$(HIGH) Dist clean $(LIGHT)"
	-$(RM) doc/
	-$(RM) tags
	-$(RM) cscope.out
	@echo "------------------------------------------------------------"

dist: distclean
	@echo "------------------------------------------------------------"
	@echo -e "\t$(HIGH) Archive and ready to distrubute $(LIGHT)"
	$(MKDIR) ../$(DIRECTORY)
	$(CP) * ../$(DIRECTORY)
	$(TAR) $(DIRECTORY).tar.bz2 ../$(DIRECTORY)
	$(RM) ../$(DIRECTORY)
	$(MV) $(DIRECTORY).tar.bz2 ../
	@echo "------------------------------------------------------------"

# FIXME: in windows, somehow only 'ctags -R ../c" works, but '.'
#        and '../c' refer to same directory
TAGS:
	@echo "------------------------------------------------------------"
	@echo -e "\t$(HIGH) Generate tags for ctags and csopoe $(LIGHT)"
	-$(CTAGS) ./
	-$(FIND) ./ -type f > cscope.files && $(CSCOPE)
	@echo "------------------------------------------------------------"

help:
	@echo "------------------------------------------------------------"
	@echo -e "\t$(HIGH) Available targets: $(LIGHT)"
	@echo -e "available make targets"
	@echo "make help        : Display this help message"
	@echo "make all         : Compile the project"
	@echo "make clean       : Remove object files"
	@echo "make TAGS        : Generate ctags and cscope tags database"
	@echo "------------------------------------------------------------"

######################################################################
### Makefile ends here
