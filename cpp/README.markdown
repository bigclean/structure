Introduction
==============

Simple data structures implementation in cpp.

What included
==============

* list(double link list), general implementation

How to build
=============

General
-------------

Now it support GNUmake and Cmake both, but out-of-source Cmake is more
suggested.  You can shoose 'Unix Makefiles' or 'MinGW Makefiles' as
well.

Build Steps
-------------

* Cmake cmake .. -G "Unix Makefiles" && make all

        or cmake .. -G "MinGW Makefiles" && make all

        Of course, you should in build directory(you should make it
        first) and use out-of-source building it.

* GNUmake make -f Makefile.GNU all

Enjoy yourself.
