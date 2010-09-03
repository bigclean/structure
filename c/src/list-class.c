/* list-class.c ---
 *
 * Filename: list-class.c
 * Description: list implementation file.
 * Author: bigclean
 * Created: Wed Aug 25 15:39
 * Last-Updated: Wed Aug 25 15:39
 */

/* Code: */

/**
 * @file list-class.c
 * @brief list implementation
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <setjmp.h>

#include "list-class.h"

/*
 *  node operations
 */
struct node *
node_make(const void *elem)
{
        struct node *node =(struct node *) malloc(sizeof(struct node));
        /* TODO: use macro assert() */
        if (!node) {
                printf("memory error.\n");
        }
        node->data = elem;
        node->prev = node->next = NULL;

        /* register function pointers */
        node->free = node_free;
        node->visit = node_visit;

        return node;
}

void
node_free(struct node *node)
{
        free(node);
        node = NULL;
}

/* callback function for list_foreach(), similar iterator */
void
node_visit(struct node *node)
{
        /* TODO: beautify output. */
        printf("%s.\n", (char *)node->data);
}

/*
 * list operations
 */

/*
 * create list
 */
struct list *
list_create(void)
{
        /* in this version,  list has head and tail node */
        struct list *list = (struct list *) malloc(sizeof(struct list));
        if (!list) {
                /* return ERROR; */
                printf("memory error.\n");
        }
        list->head = (struct node *) malloc(sizeof(struct node));
        list->tail = (struct node *) malloc(sizeof(struct node));
        list->head->prev = NULL;
        list->tail->next = NULL;
        /* concatenate head and tail node to construct list */
        list->head->next = list->tail;
        list->tail->prev = list->head;
        list->length = 0;

        /* register functions */
        list->insert_before = list_insert_before;
        list->insert_after = list_insert_after;
        list->insert_first = list_insert_first;
        list->append = list_append;
        list->delete_from = list_delete_from;
        list->foreach = list_foreach;
        list->traverse = list_traverse;
        list->test_main = list_test_main;

        return list;
}

/*
 * when next is NULL it would inserts after the tail
 */
void
list_insert_before(struct list *list, struct node *next, const void *elem)
{
        if (next->prev == NULL) {
                printf("inserts before head node, error.\n");
        }
        struct node *newnode = node_make(elem);
        struct node *prev = next->prev;

        newnode->prev = prev;
        newnode->next = next;

        prev->next = newnode;
        next->prev = newnode;

        list->length++;
}

/*
 * insert after
 */
void
list_insert_after(struct list *list, struct node *prev, const void *elem)
{
        if (prev->next == NULL) {
                printf("inserts after tail node, error.\n");
        }
        struct node *newnode = node_make(elem);
        struct node *next = prev->next;

        newnode->prev = prev;
        newnode->next = next;

        prev->next = newnode;
        next->prev = newnode;

        list->length++;
}

void
list_insert_first(struct list *list, const void *elem)
{
        /*
         * TODO: list->head->next is NULL when only head and tail node
         * exists in list(when create list only).
         * XXX: in create list function, you can concatenate head and
         * tail node together.
         */
        struct node *newnode = node_make(elem);
        struct node *next = list->head->next;
        newnode->next = next;
        newnode->prev = list->head;
        /* head node refers to newnode */
        list->head->next = newnode;
        next->prev = newnode;
        list->length++;
}

/*
 * insert node after tail of list
 */
void
list_append(struct list *list, const void *elem)
{
        struct node *newnode = node_make(elem);
        struct node *prev = list->tail->prev;
        newnode->next = list->tail;
        newnode->prev = prev;
        /* tail node refers to newnode */
        list->tail->prev = newnode;
        prev->next = newnode;
        list->length++;
}

void
list_delete_from(struct list *list, struct node *node)
{
        struct node *prev = node->prev;
        struct node *next = node->next;
        if (prev) {
                prev->next = next;
        } else {
                /*
                 * deleted node is head node, and 'next' node would be
                 * first node of  list, so it would place 'next' node
                 * as new head node of  list.
                 */
                list->head =next;
        }
        if (next) {
                next->prev = prev;
        } else {
                /*
                 * deleted node is tail node, and 'prev' node would be
                 * last node of  list, so it would place 'prev' node
                 * as new tail node of  list.
                 */
                list->tail = prev;
        }
        node_free(node);
        list->length--;
}

void
list_destroy(struct list *list)
{
        /* destroy nodes of  list */
        struct node *current = list->head;
        struct node *next = NULL;
        while (current) {
               next  = current->next;
               free(current);
               current = next;
        }
        free(list); /* destroy list itself */
}

/* this function use callback tips */
void
list_foreach(struct list *list, node_callback callback)
{
        struct node *current = list->head->next;
        while (current->next) {
                callback(current);
                current = current->next;
        }
}

void
list_traverse(struct list *list)
{
        list_foreach(list, node_visit);
}

int
list_test_main(int argc, char **argv)
{
        printf("----------------------------------------------\n");
        printf("start to have a test of list class.\n");
        printf("----------------------------------------------\n");
        struct list *list = list_create();
        char *first_name = "Hello";
        char *last_name = "World";
        list->insert_first(list, first_name);
        list->insert_first(list, last_name);
        list->insert_first(list, "Peace");
        list->insert_first(list, "Love");
        list->append(list, "Class");
        list->append(list, "Comput");
        list->delete_from(list, list->tail->prev->prev);
        list->insert_after(list, list->tail->prev->prev, "Code");
        list->insert_before(list, list->tail->prev->prev, "Would");
        list->traverse(list);
        printf("ok, now length is %d.\n", list->length);
        printf("-------------------------------------------------\n");
        printf("test is finished. everything is gone be alright.\n");
        printf("-------------------------------------------------\n");
        printf("\n");

        return EXIT_SUCCESS;
}

/* list.c ends here */
