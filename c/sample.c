/*
 * gcc sample.c -Iinclude list.o list-class.o btree.o -o sample.exe
 * Alternatives: gcc -Iinclude -lstructure -o sample.exe
 */
#define LIST_TEST
#define LIST_CLASS_TEST
#define STACK_TEST
#define BTREE_TEST

#include <stdio.h>
#include <stdlib.h>

#ifdef LIST_TEST
    #include "list.h"
#endif

#ifdef LIST_CLASS_TEST
    #include "list-class.h"
#endif

#ifdef STACK_TEST
    #include "stack.h"
#endif

#ifdef BTREE_TEST
    #include "btree.h"
#endif

int main(int argc, char **argv)
{
        /*
         * TODO: every test unit also have its self return value, it's
         * to be fixed
         */
#ifdef LIST_TEST
        /* test list */
        link_list_test_main(argc, argv);
#endif

#ifdef LIST_CLASS_TEST
        /* test list class */
        list_test_main(argc, argv);
#endif

#ifdef STACK_TEST
        /* test stack */
        stack_test_main(argc, argv);
#endif

#ifdef BTREE_TEST
        /* test binary tree */
        btree_test_main(argc, argv);
#endif
        return EXIT_SUCCESS;
}
