/* btree.h --- 
 * 
 * Filename: btree.h
 * Description: 
 * Author: bigclean
 * Created: Wed Aug 25 15:40
 * Last-Updated: Wed Aug 31 21:39
 */

/* Code: */

/**
 * @file btree.h
 * @brief binary tree head file
 * @todo Should it distinguish binary tree with binary tree node?
 *       Should let ::btree as syntatic sugar always?
 */

#ifndef __BTREE_H_
#define __BTREE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "structure.h"

/**
 * @brief node of binary tree
 */
struct btree_node_t {
        void *data;
        struct btree_node_t *left;  /**< left child node */
        struct btree_node_t *right; /**< right child node */
};
typedef struct btree_node_t btree_node; /**< binary tree node */

/**
 * @brief btree is head pointer refers to root node of binary tree
 * @note In implementation, ::btree and *::btree_node is somehow recongnized
 *       same, just emphasis btree is pointer of root node.
 * @note ::btree is a notation of syntatic sugar for programmers.
 * @todo imporve ::btree structure
 */
typedef struct btree_node_t *btree;

/**
 * @brief mode of how to traverse binary tree
 */
enum btree_traverse_mode_t {
        PRE_ORDER,
        IN_ORDER,
        POST_ORDER
};
typedef enum btree_traverse_mode_t btree_traverse_mode; /**< tree traverse mode */

/**
 * @brief how to insert subtree to binary tree
 */
enum btree_insert_mode_t {
        LEFT,  /**< insert in left side of parent node  */
        RIGHT  /**< insert in right side of parent node */
};
typedef enum btree_insert_mode_t btree_insert_mode; /**< insert child subtree mode */

/**
 * @brief callback prototype for each binary tree node
 */
typedef void (*btree_node_callback)(btree_node *node);

/**
 * binary tree traverse callback prototype
 */
typedef void (*btree_traverse_callback)(btree tree,
                                       btree_node_callback btree_node_visit);

/*
 * binary node operations sets
 */
btree_node* btree_node_make(void *elem);

void btree_node_print(btree_node *node);

/*
 * binary tree operation sets
 */

/**
 * @brief create binary tree
 * @note It equals that create root node of its binary tree
 * @note now in this version implementation, ::btree is pointer of
 *       btree_node actually. It's planned that improve ::btree structure
 *       add some addition useful data fields, when in that situation,
 *       it's prototype should be rewritten.
 */
btree btree_create(void);

/**
 * @brief insert subtree to binary tree
 * insert child subtree to binary tree, and then the original
 * left or right subtree would become right child node of new 
 * inserted subtree.
 * @todo improve how to insert node or subtree
 *
 * @param parent target parent node of binary tree
 * @param flag insert orientation of child subtree
 *        @li \c LEFT insert left, left subtree would be right subtree
 *                    of new inserted subtree
 *        @li \c RIGHT insert right, right subtree would be right
 *                     subtree of new inserted subtree
 * @param child inserted child subtree
 * @note We should treat signle binary node as a tree with it's only
 *       root node
 */
void btree_insert_child_tree(btree_node *parent, btree_insert_mode flag, btree child);

/**
 * @brief traverse tree in choosed mode
 *
 * @param flag determine which mode to be used to traverse
 *        @li \c PRE_ORDER pre order traverse
 *        @li \c IN_ORDER in order traverse
 *        @li \c POST_ORDER post order traverse
 * @param btree_node_visit callback function of how to visit node of
 *                         binary tree
 *
 * @note because this version binary tree traverse always use recursive
 *       function, so it's recommended to know how function is invoked
 *       and contents of function stack.
 *
 * @note In this implementation, function jump table is used. So it's
 *       suggested that you have a basic idea about function pointer.
 */
void btree_traverse(btree tree, btree_traverse_mode flag,
                    btree_node_callback btree_node_visit);

/**
 * @brief traverse tree in pre-order
 *
 * @param btree_node_visit node visit function callback
 */
void btree_traverse_pre_order(btree tree,
                         btree_node_callback btree_node_visit);
/**
 * @brief traverse tree in in-order
 *
 * @param btree_node_visit node visit function callback
 */
void btree_traverse_in_order(btree tree,
                        btree_node_callback btree_node_visit);
/**
 * @brief traverse tree in post-order
 *
 * @param btree_node_visit node visit function callback
 */
void btree_traverse_post_order(btree tree,
                          btree_node_callback btree_node_visit);

int btree_depth(const btree tree);

/**
 * @brief binary tree test sample
 * @param argc count of argument
 * @param argv pointer of argument pointers array
 * @return indicate if test if succeed
 */
int btree_test_main(int argc, char **argv);

#ifdef __cplusplus
}
#endif

#endif

/* tree.h ends here */
