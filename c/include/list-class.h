/* list-class.h --- 
 * 
 * Filename: list-class.h
 * Description: list class header using OOP perspect
 * Author: bigclean <potteryzero at gmail dot com>
 * Created: Wed Aug 25 15:41
 * Last-Updated: Wed Aug 25 15:41
 */

/* Code: */

/**
 * @file list-class.h
 * @brief list header file but use OOP perspect
 */

#ifndef __LIST_CLASS_H_
#define __LIST_CLASS_H_

#include "structure.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief simple and clean node class
 */
struct node {
        /* class data */
        void *data; /**< data */
        struct node *next; /**< next node */
        struct node *prev; /**< previous node */

        /* class functions */
        void (*free)(struct node *node); /**< free node */
        void (*visit)(struct node *node); /**< action when traversing node */
};
typedef struct node Node;

/* function pointer prototype */
/**
 * @brief callback function prototype to deliver to list_foreach()
 */
typedef void (*node_callback)(struct node *node);

/**
 * @brief list class implemented in ansi c, it's to be improved
 * @todo  add classical 'this' pointer to operate itself
 */
struct list {
        /* class data */
        struct node *head;           /**< head node of list */
        struct node *tail;           /**< tail node of list */
        int length;                  /**< list length */

        /*
         * class functions, use function pointer to simulate functions
         * in class.
         */
        /**
         * @note see list_insert_before()
         */
        void (*insert_before)(struct list *list, struct node *next, const void *elem);
        /**
         * @note see list_insert_after()
         */
        void (*insert_after)(struct list *list, struct node *prev, const void *elem);
        /**
         * @note see list_insert_first()
         */
        void (*insert_first)(struct list *list, const void *elem);
        /**
         * @note see list_append()
         */
        void (*append)(struct list *list, const void *elem);
        /**
         * @note see list_delete_from()
         */
        void (*delete_from)(struct list *list, struct node *node);
        /**
         * @note see list_foreach()
         */
        void (*foreach)(struct list *list, node_callback callback);
        /**
         * @note see list_traverse()
         */
        void (*traverse)(struct list *list);
        /**
         * @note see list_test_main()
         */
        int (*test_main)(int argc, char **argv);
};
typedef struct list List;

/**
 * @brief make node
 * @param elem maked node data domain
 * @return pointer of generated node
 */
struct node *node_make(const void *elem);

/**
 * @brief free node
 * @param node freed node
 */
void node_free(struct node *node);

/**
 * @brief visit node of list
 * @param node processed node
 */
void node_visit(struct node *node);

/*
 * list operations
 */
/**
 * @brief create double link list
 * @return pointer of link list
 * @note In the process of create link list, it would concatenate head
 *       and tail node to construct list.So it's convenient that insert
 *       after head or before tail node
 */
struct list* list_create(void);

/**
 * @brief insert before refered node
 * @param list processed list
 * @param next node after newly inserted generated node
 * @param elem data field of node inserted
 * @return status(success or error)
 * @note operation of inserting before head node is illegal, it would
 *       cause that program exit abnormally.
 * @note It's recommended that you shouldn't add new head node of list
 */
void list_insert_before(struct list *list, struct node *next, const void *elem);

/**
 * @brief insert before refered node
 * @param list processed list
 * @param prev node before newly inserted generated node
 * @param elem data filed of node inserted
 * @return status(success or error)
 * @note operation of inserting after tail node is illegal, it would
 *       cause that program exit abnormally
 */
void list_insert_after(struct list *list, struct node *prev, const void *elem);

/**
 * @brief insert before first node of link list.
 * @param list processed list.
 * @param elem data inserted to list
 */
void list_insert_first(struct list *list, const void *elem);

/**
 * @brief insert element after last node of link list.
 * @param list processed list.
 * @param elem date field of node appended to list
 * @return status(success or error)
 */
void list_append(struct list *list, const void *elem);

/**
 * @brief delete node from link list
 * @param list processed list
 * @param node pointer of deleted node
 * @note operation of deleting head or tail node is also illegal, program
 *       would justify position automatically, that's mean first or last 
 *       node would become new head or tail node of list
 */
void list_delete_from(struct list *list, struct node *node);

/**
 * @brief destroy list and free memory
 * @param list destroyed list
 * @return
 */
void list_destroy(struct list *list);

/**
 * @brief iterator for list
 * @param list iterated list
 * @param callback callback function of list, it's function pointer
 * @return
 */
void list_foreach(struct list *list, node_callback callback);

/**
 * @brief traverse list
 * @param list traversed list
 * @return
 */
void list_traverse(struct list *list);

int list_test_main(int argc, char **argv);

#ifdef __cplusplus
}
#endif

#endif

/* list-class.h ends here */
