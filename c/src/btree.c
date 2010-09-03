/* btree.c --- 
 * 
 * Filename: btree.c
 * Description: 
 * Author: bigclean
 * Created: Wed Aug 25 15:37
 * Last-Updated: Wed Aug 31 20:57
 */

/* Code: */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <setjmp.h>

#include "btree.h"

/* binary tree traverse function table */
const btree_traverse_callback BTREE_TRAVERSE_TABLE[] = {
        btree_traverse_pre_order,
        btree_traverse_in_order,
        btree_traverse_post_order
};

/*
 * binary tree node operations
 */
btree_node *
btree_node_make(void *elem)
{
        btree_node *node= (btree_node *) malloc(sizeof(btree_node));
        assert(node != NULL);
        node->data = elem;
        node->left = node->right = NULL;
        return node;
}

void
btree_node_print(btree_node *node)
{
        printf("%s\n", node->data);
}

/*
 * binary tree operations
 */
btree
btree_create(void)
{
        btree_node *root = (btree_node *) malloc(sizeof(btree_node));
        root->left = root->right = NULL;
        root->data = "root"; /* root data field is "root" defaultly */
        return root;
}

void
btree_insert_child_tree(btree_node *parent, btree_insert_mode flag, btree child)
{
        btree move = NULL;  /* moved child part of parent node
                               based on insert mode */
        if(parent) {
                if (flag == LEFT) {
                        move = parent->left;
                        child->right = move;
                        parent->left = child;
                }
                else {
                        move = parent->right;
                        child->right = parent->right;
                        parent->right = child;
                }
        }
}

void
btree_traverse(btree tree, btree_traverse_mode flag,
               btree_node_callback btree_node_visit)
{
        /* callback variable to invoke real function */
        btree_traverse_callback traverse_func = BTREE_TRAVERSE_TABLE[flag];
        /* now it's time to invoke traverse function */
        traverse_func(tree, btree_node_visit);
}

/*
 * In traverse process, recursive is generally used to implement it.
 * So it's recommended to know function stack.
 */
void
btree_traverse_pre_order(btree tree,
                         btree_node_callback btree_node_visit)
{
        if (tree) {
                btree_node_visit(tree);
                btree_traverse_post_order(tree->left, btree_node_visit);
                btree_traverse_pre_order(tree->right, btree_node_visit);
        }
}

void
btree_traverse_in_order(btree tree,
                        btree_node_callback btree_node_visit)
{
        if (tree) {
                btree_traverse_in_order(tree->left, btree_node_visit);
                btree_node_visit(tree);
                btree_traverse_in_order(tree->right, btree_node_visit);
        }
}

void
btree_traverse_post_order(btree tree,
                          btree_node_callback btree_node_visit)
{
        if (tree) {
                btree_traverse_post_order(tree->left, btree_node_visit);
                btree_traverse_post_order(tree->right, btree_node_visit);
                btree_node_visit(tree);
        }
}

int
btree_depth(const btree tree)
{
        int left_depth, right_depth;
        int max_depth;
        if (!tree) {
                return 0;
        }

        /* traverse left subtree */
        if (tree->left) {
                left_depth = btree_depth(tree->left);
        } else {
                left_depth = 0;
        }
        /* traverse right subtree */
        if (tree->right) {
                right_depth = btree_depth(tree->right);
        } else {
                right_depth = 0;
        }

        /* colon three-meta expression shoulde be careful */
        max_depth = left_depth > right_depth ? left_depth + 1: right_depth + 1;
        return max_depth;
}

int
btree_test_main(int argc, char **argv)
{
        printf("-------------------------------------------------\n");
        printf("starts to have a test of binary tree.\n");
        printf("-------------------------------------------------\n");
        btree tree = btree_create();
        btree_node *dataone = btree_node_make("hello");
        btree_insert_child_tree(tree, PRE_ORDER, dataone);
        btree_node *datatwo = btree_node_make("World");
        btree_insert_child_tree(dataone, PRE_ORDER, datatwo);
        btree_traverse(tree, IN_ORDER, btree_node_print);
        printf("now length of tree is %d\n", btree_depth(tree));
        printf("-------------------------------------------------\n");
        printf("test is over, everything is gone be alright.\n");
        printf("-------------------------------------------------\n");
        printf("\n");

        return EXIT_SUCCESS;
}
/* tree.c ends here */
