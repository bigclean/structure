/* list.c ---
 *
 * Filename: list.c
 * Description: list implementation file.
 * Author: bigclean
 * Created: Wed Aug 25 15:37
 * Last-Updated: Wed Aug 25 15:37
 */

/* Code: */

/**
 * @file list.c
 * @brief list implementation
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <setjmp.h>

#include "list.h"

/*
 * link node operations
 */
link_node *
link_node_make(elem_type elem)
{
        link_node *node =(link_node *) malloc(sizeof(link_node));
        assert(node != NULL);
        node->data = elem;
        node->prev = node->next = NULL; /* pointer should be initialized */
        return node;
}

void
link_node_free(link_node *node)
{
        free(node);
        node = NULL;
}

/* callback function for link_list_foreach(), similar iterator */
void
link_node_visit(link_node *node)
{
        /* TODO: beautify output. */
        printf("element field is %d\n", node->data);
}

/*
 * linked list operations
 */

/*
 * create link list
 */
link_list *
link_list_create(void)
{
        /* in this version, link list has head and tail node */
        link_list *list = (link_list *) malloc(sizeof(link_list));
        if (!list) {
                /* return ERROR; */
                printf("memory error.\n");
        }
        list->head = (link_node *) malloc(sizeof(link_node));
        list->tail = (link_node *) malloc(sizeof(link_node));

        list->head->prev = NULL;
        list->tail->next = NULL;

        /* concatenate head and tail node to construct list */
        list->head->next = list->tail;
        list->tail->prev = list->head;
        list->length = 0;

        return list;
}

/*
 * when next is NULL it would inserts after the tail
 */
void
link_list_insert_before(link_list *list,
        link_node *next, elem_type elem)
{
        /* if (next->prev == NULL) { */
        /*         printf("inserts before head node, error.\n"); */
        /* } */
        assert(next->prev);
        link_node *newnode = link_node_make(elem);
        link_node *prev = next->prev;

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
link_list_insert_after(link_list *list,
        link_node *prev, elem_type elem)
{
        /* Now use assert() macro */
        /* if (prev->next == NULL) { */
        /*        printf("inserts after tail node, error.\n"); */
        /* } */
        assert(prev->next);
        /* 
         * Note: ISO C90 mixed declarations and code 
         * XXX: to solve this, always declarations go first, and if
         *      parameter is illegal and then free allocated memory.
         */
        link_node *newnode = link_node_make(elem);
        link_node *next = prev->next;

        newnode->prev = prev;
        newnode->next = next;

        prev->next = newnode;
        next->prev = newnode;

        list->length++;
}

void
link_list_insert_first(link_list *list, elem_type elem)
{
        /*
         * TODO: list->head->next is NULL when only head and tail node
         * exists in list(when create list only).
         * XXX: in create list function, you can concatenate head and
         * tail node together.
         */
        link_node *newnode = link_node_make(elem);
        link_node *next = list->head->next;
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
link_list_append(link_list *list, elem_type elem)
{
        link_node *newnode = link_node_make(elem);
        link_node *prev = list->tail->prev;
        newnode->next = list->tail;
        newnode->prev = prev;
        /* tail node refers to newnode */
        list->tail->prev = newnode;
        prev->next = newnode;
        list->length++;
}

void
link_list_delete(link_list *list, link_node *node)
{
        link_node *prev = node->prev;
        link_node *next = node->next;
        if (prev) {
                prev->next = next;
        } else {
                /*
                 * deleted node is head node, and 'next' node would be
                 * first node of link list, so it would place 'next' node
                 * as new head node of link list.
                 */
                list->head =next;
        }

        if (next) {
                next->prev = prev;
        } else {
                /*
                 * deleted node is tail node, and 'prev' node would be
                 * last node of link list, so it would place 'prev' node
                 * as new tail node of link list.
                 */
                list->tail = prev;
        }
        link_node_free(node);
        list->length--;
}

Bool
link_list_isempty(const link_list *list)
{
        return (list_length(list) == 0);
}

void
link_list_destroy(link_list *list)
{
        /* destroy nodes of link list */
        link_node *current = list->head;
        link_node *next = NULL;
        while (current) {
               next  = current->next;
               free(current);
               current = next;
        }
        free(list); /* destroy link list itself */
}

/* this function use call-back tips */
void
link_list_foreach(link_list *list, link_node_callback callback)
{
        link_node *current = list->head->next;
        while (current->next) {
                callback(current);
                current = current->next;
        }
}

void
link_list_traverse(link_list *list)
{
        link_list_foreach(list, link_node_visit);
}

int
link_list_test_main(int argc, char **argv)
{
        printf("----------------------------------------------\n");
        printf("starts to have a test of list.\n");
        printf("----------------------------------------------\n");
        link_list *list = link_list_create();
        link_list_insert_first(list, 1);
        link_list_insert_first(list, 2);
        link_list_insert_first(list, 3);
        link_list_insert_first(list, 4);
        link_list_append(list, 5);
        link_list_append(list, 6);
        link_list_delete(list, list->tail->prev->prev);
        link_list_insert_after(list, list->tail->prev->prev, 10);
        link_list_insert_before(list, list->tail->prev->prev, 9);
        link_list_traverse(list);
        /* printf("another is %d.\n", list->tail->prev->prev->next->data); */
        printf("ok, now length is %d.\n", list->length);
        printf("----------------------------------------------\n");
        printf("test is finished. everything is gone be alright.\n");
        printf("----------------------------------------------\n");
        printf("\n");

        return EXIT_SUCCESS;
}
/* list.c ends here */
