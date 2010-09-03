### Makefile --- 
## 
## Filename: Makefile
## Description: Makefile for structure
## Author: bigclean
## Created: Aug 25 2010 16:36
## Last-Updated: Aug 30 2010 21:53
### Code:

SHELL    := /bin/sh
PROJECT  := structure
VERSION  := 0.1beta
DIRECTORY := $(PROJECT)-$(VERSION)
CC = gcc
AR = ar
ARFLAGS = -r
VPATH  = src
CFLAGS = -ansi -Wall -pedantic -Wstrict-prototypes
CPPFLAGS = -Iinclude
# SRCS is the source files list(*.c)
# literal way sources
#SOURCES    := btree.c list.c list-class.c stack.c
SOURCES  := $(sort                 \
		$(notdir           \
			$(shell find $(VPATH) -name '*.c')))

OBJS     := $(patsubst %.c, %.o, $(SOURCES))

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

# FIXME: should place binary file in binary directory
# XXX: in windows, output should be renamed be NAME.exe
all: $(OBJS)
	@echo "------------------------------------------------------------"
	@echo -e "\t$(HIGH) Building... $(LIGHT)"
	$(AR) -r lib$(PROJECT).a $(OBJS)
ifdef COMSPEC
	$(CC) sample.c $(CPPFLAGS) -l$(PROJECT) -L. -o sample.exe
else
	$(CC) sample.c $(CPPFLAGS) -l$(PROJECT) -L. -o sample
endif
	@echo "------------------------------------------------------------"


%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c  $< -o $@

doc:
	@echo "------------------------------------------------------------"
	@echo -e "\t$(HIGH) Generate docments via doxygen $(LIGHT)"
	$(DOXYGEN) $(DOXYFILE)
	@echo "------------------------------------------------------------"

clean:
	@echo "------------------------------------------------------------"
	@echo -e "\t$(HIGH) Clean $(LIGHT)"
	-$(RM) $(OBJS)
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
