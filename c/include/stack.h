/* stack.h --- 
 * 
 * Filename: stack.h
 * Description: stack header file
 * Author: bigclean
 * Created: Wed Aug 25 15:43
 * Last-Updated: Wed Aug 25 15:43
 */

/* Code: */

/**
 * @file stack.h
 * @brief stack header file
 */

#ifndef __STACK_H_
#define __STACK_H_

#ifdef __cplusplus
#extern "C" {
#endif

#include "structure.h"

#define STACK_INIT_SIZE 100     /**< initial size of stack */
#define STACK_INCREMENT 10      /**< increment size of stack */

/**
 * @li if base is NULL, then stack has not been initialized
 * @li if base is equal to top, so stack is empty
 * @todo draw a stack graph.
 */

/*
 * simple graph for stack.
 *        --------
 *        |      |
 *        --------
 *        |      |
 *        --------
 *        |      |
 *        --------
 *        |      |
 *        --------
 */
struct sq_stack_t {
        int length;            /**< stack current length, dynamic variable */
        int capacity;          /**< stack current capacity, relative static */
        elem_type *base;       /**< stack base address */
        elem_type *top;        /**< stack top address */
};
typedef struct sq_stack_t sq_stack;
typedef sq_stack *sq_stack_ptr;

typedef void (*sq_stack_element_callback)(elem_type elem);

/**
 * @brief just peek an element
 */
void sq_stack_peek_element(elem_type elem);

/**
 * @brief initial stack
 * @return initialized stack pointer
 */
sq_stack * stack_init(void);

/**
 * @brief add a value to the stack
 *
 * @param stk stack
 * @param elem element to be pushed to stack
 */
void stack_push(sq_stack *stk, elem_type elem);

/**
 * @brief retrieve top value from the stack and remove it
 *
 * @param stk stack
 * @return top value of stack
 */
elem_type stack_pop(sq_stack *stk);

/**
 * @brief only receive top value without removing it
 * @note  It's difference with stack_pop() is that it's immutable
 *
 * @param stk stack
 * @return top element of stack
 */
elem_type stack_get_top(const sq_stack *stk);

/**
 * @brief see if stack is empty
 * @param stk tested stack
 * @return @li \c TRUE  stack is empty
 *         @li \c FALSE stakck is not empty
 */
Bool stack_isempty(const sq_stack *stk);

/**
 * @brief see if stack is full
 * @param stk tested stack_isfull
 * @return @li \c TRUE  stack is full
 *         @li \c FALSE stack is not full
 */
Bool stack_isfull(const sq_stack *stk);

/**
 * @brief do a series action to each elememt of stack
 *
 * @param stk stack
 * @param callback callback function pointer for each element of stack
 */
void stack_foreach(sq_stack *stk, sq_stack_element_callback callback);

/**
 * @brief traverse stack
 * @note traversed function is sq_stack_peek_element()
 * @param stk traversed stack
 */
void stack_traverse(sq_stack *stk);

/**
 * @brief stack test unit
 * @param argc same as main()
 * @param argv same as main()
 */
int stack_test_main(int argc, char **argv);

#ifdef __cplusplus
}
#endif

#endif

/* stack.h ends here */
