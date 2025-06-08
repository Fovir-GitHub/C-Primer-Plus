#ifndef _MY_TREE_H_
#define _MY_TREE_H_

#include <stdbool.h>

#define WORD_MAX_LENGTH 50

enum WHERE_TO_ADD_NODE { TO_LEFT = 1, TO_RIGHT = -1, THE_SAME = 0 };

typedef struct {
    char word[WORD_MAX_LENGTH];
    int count;
} item;

typedef struct Node {
    item node_item;
    struct Node * left;
    struct Node * right;
} node;

typedef struct {
    node * root;
} tree;

void initialize_tree(tree * ptree);

/// @brief This function is used to identify where to store new node.
/// @param original_node the father node
/// @param new_node the child node
int where_to_add_new_node(node * original_node, node * new_node);

/// @brief This function is used to add new item to the tree.
/// @param new_item the item to be added
/// @param ptree the tree
/// @return if the item is added successfully, it will return true.
/// otherwise, it will return false.
bool add_item_to_tree(item new_item, tree * ptree);

/// @brief This function is used to show items in the tree.
/// @param ptree pointer to tree
void show_tree_items(node * tree_root);

void clear_tree(node * tree_root);

#endif // !_MY_TREE_H_