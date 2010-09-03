/* stack.c --- 
 * 
 * Filename: stack.c
 * Description: stack implemention, now including sequence stack.
 * Author: bigclean
 * Created: Wed Aug 25 15:37
 * Last-Updated: Wed Aug 25 15:37
 */

/* Code: */

/**
 * @file stack.c
 * @brief stack implementation, now sequence stack only
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stack.h"

void
sq_stack_peek_element(elem_type elem)
{
        printf("element is %d\n", elem);
}

sq_stack *
stack_init(void)
{
        sq_stack *stk = (sq_stack *) malloc(sizeof(sq_stack));
        stk->base = (elem_type *) malloc(STACK_INIT_SIZE * sizeof(elem_type));
        if (!stk->base) {
                /* return OVERFLOW; */
                fprintf(stderr, "overflow error.\n");
        }
        stk->top = stk->base;
        stk->capacity = STACK_INIT_SIZE;
        stk->length = 0;
        return stk;
}

void
stack_push(sq_stack *stk, elem_type elem)
{
        if (stack_isfull(stk)) {
                /* if stack is full, so we should allocate spaces */
                stk->base = (elem_type *) realloc(
                                                  stk->base,
                                                  (stk->capacity + STACK_INCREMENT)
                                                  * sizeof(elem_type)
                                                  );
                if (!stk->base) {
                        fprintf(stderr, "overflow error.\n"); /* stack is full, causing overflow */
                }
                /* stack top address is shifting also */
                stk->top = stk->base + stk->capacity;
                stk->capacity += STACK_INCREMENT;
        }
        *stk->top++ = elem;
        stk->length++;
}

elem_type
stack_pop(sq_stack *stk)
{
        int top_element;
        if (stack_isempty(stk)) {
                fprintf(stderr, "stack is empty\n");
                /*
                 * XXX: macro EXIT_SUCCESS is only suitable for return type
                 *      is integer
                 */
                return (elem_type) EXIT_FAILURE;
        }
        top_element = *--stk->top;
        stk->top--;
        stk->length--;
        return top_element;
}

elem_type
stack_get_top(const sq_stack *stk)
{
        int top_element;
        if (stack_isempty(stk)) {
                fprintf(stderr, "stack is empty.\n");
                /*
                 * XXX: macro EXIT_SUCCESS is only suitable for return type
                 *      is integer 
                 */
                return (elem_type) EXIT_FAILURE;
        }
        top_element = *(stk->top - 1);
        return top_element;
}

Bool
stack_isempty(const sq_stack *stk)
{
        return (stk->base == stk->top);
}

Bool
stack_isfull(const sq_stack *stk)
{
        return (stk->length >= stk->capacity);
}

void stack_foreach(sq_stack *stk, sq_stack_element_callback callback)
{
        /* alternate implementation*/
        /*
        elem_type *current = stk->base;
        while (stk->top > current) {
                callback(*current++)
        }
        */
        elem_type *base_orig = stk->base; /* store original base address */
        while (stk->top > stk->base) {
                callback(*stk->base++);
        }
        stk->base = base_orig;
}

void
stack_traverse(sq_stack *stk)
{
        stack_foreach(stk, sq_stack_peek_element);
}

int
stack_test_main(int argc, char **argv)
{
        printf("-------------------------------------------------\n");
        printf("starts to have a test of sequence stack.\n");
        printf("-------------------------------------------------\n");
        printf("now will intial stack.\n");
        sq_stack *stack = stack_init();
        stack_push(stack, 4);
        stack_push(stack, 12);
        stack_push(stack, 18);
        stack_traverse(stack);
        stack_pop(stack);
        printf("top is %d\n", stack_get_top(stack));
        stack_traverse(stack);
        printf("-------------------------------------------------\n");
        printf("test is over, everything is gone be alright.\n");
        printf("-------------------------------------------------\n");
        printf("\n");

        return EXIT_SUCCESS;
}

/* stack.c ends here */
