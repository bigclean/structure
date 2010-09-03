/* list.h --- 
 * 
 * Filename: list.h
 * Description:
 * Author: bigclean <potteryzero at gmail dot com>
 * Created: Wed Aug 25 15:40
 * Last-Updated: Wed Aug 25 15:40
 */

/* Code: */

/**
 * @file list.h
 * @brief list header file
 */

#ifndef __LIST_H_
#define __LIST_H_

#include "structure.h"

/* note: when use g++ compile source, __cplusplus is defined.
 *       usually used when linking objects.
 * Reference 《程序员的自我修养》 P90-91
 */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief lists length
 */
#define list_length(list) ((list)->length)

/**
 * @brief previous node
 */
#define link_list_prev(node) ((node) ? (((link_node *)(node))->next) : NULL)

/**
 * @brief next node
 */
#define link_list_next(node) ((node) ? (((link_node *)(node))->next): NULL)

/** @defgroup link_list double link list
 *
 * @{
 */

/**
 * @brief general node type of link list
 *
 * @note
 * @li Always remember that header pointer refers to header node.
 * @li In this version double list implementation, list has header node, which
 *       it means that you should use (list->next) to get pointer that 
 *       refers to first node of list.
 *
 * @todo use 'artist-mode' to draw an ascii figure.
 */
struct link_node_t {
        elem_type data;           /**< link list node data */
        struct link_node_t *next; /**< pointer refers to next node */
        struct link_node_t *prev;
};
typedef struct link_node_t link_node; /**< general node of link list */
typedef link_node *link_node_ptr; /**< general link node pointer */

/* function pointer prototype */
/**
 * @brief callback function prototype to deliver to link_list_foreach()
 */
typedef void (*link_node_callback)(link_node *node);

/**
 * @brief link list structure
 */
struct link_list_t {
        link_node *head;            /**< head node of list */
        link_node *tail;            /**< tail node of list */
        unsigned int length;        /**< list length, node counter */
};
typedef struct link_list_t link_list;
typedef link_list *link_list_ptr;

enum traverse_mode_t {
        FORWARD,
        REVERSE
};
typedef enum traverse_mode_t traverse_mode;

/*
 * link node operations
 */

/**
 * @brief make node
 * @param elem maked node data domain
 * @return pointer of link node
 */
link_node* link_node_make(elem_type elem);

/**
 * @brief free node
 * @param node freed node.
 */
void link_node_free(link_node *node);

/**
 * @brief traverse node of list.
 * @param node processed node
 */
void link_node_visit(link_node *node);

/*
 * linked list operations
 */
/**
 * @brief create double link list
 * @return pointer of link list
 * @note In the process of creta link list, it would concatenate head
 * and tail node to construct list.
 */
link_list *link_list_create(void);

/**
 * @brief insert element before refered node
 * @param list processed link list
 * @param next next node of new inserted node
 * @param elem date inserted to list
 * @return status(success or error)
 *
 * @note insert before head node is illegal.
 */
void link_list_insert_before(link_list *list, link_node *next, elem_type elem);

/**
 * @brief insert element before refered node
 * @param list processed link list
 * @param prev previous node of new inserted node
 * @param elem date inserted to list
 * @return status(success or error)
 *
 * @note insert after tail node is illegal.
 */
void link_list_insert_after(link_list *list, link_node *prev, elem_type elem);

/**
 * @brief insert element before first node of link list.
 * @param list processed link list
 * @param elem date inserted to list
 * @return status(success or error)
 */
void link_list_insert_first(link_list *list, elem_type elem);

/**
 * @brief insert element after last node of link list.
 * @param list processed link list
 * @param elem date inserted to list
 * @return status(success or error)
 */
void link_list_append(link_list *list, elem_type elem);

/**
 * @brief delete node from link list
 * @param list processed link list
 * @param node deleted node from link list
 * @return BOOL
 * @note delete head and tail node is illegal, and program will justify
 *       position automatically.
 */
void link_list_delete(link_list *list, link_node *node);

/**
 * @brief test if list is empty
 * @param list tested list
 * @return @li \c TRUE  list is empty
 *         @li \c FALSE list is not empty
 */
Bool link_list_isempty(const link_list *list);

/**
 * @brief destroy link list and free memory
 * @param list destroyed list
 * @return
 */
void link_list_destroy(link_list *list);

/**
 * @brief iterator for link list
 * @param list iterated link list
 * @param callback callback function for link list
 * @return
 */
void link_list_foreach(link_list *list, link_node_callback callback);

/**
 * @brief traverse link list
 * @param list processed link list
 * @return
 */
void link_list_traverse(link_list *list);

/**
 * @brief link class test sample
 */
int link_list_test_main(int argc, char **argv);

/*@}*/

/** @defgroup single_sq_list sequence list
 *
 * @{
 */
struct tag_sq_list {
        elem_type *elem;
        int length;
        int listsize;
};
typedef struct tag_sq_list sq_list;

/*@}*/

#ifdef __cplusplus
}
#endif

#endif

/* list.h ends here */
