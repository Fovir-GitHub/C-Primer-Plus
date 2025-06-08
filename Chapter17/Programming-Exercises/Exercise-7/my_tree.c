#include "my_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initialize_tree(tree * ptree) {
    ptree->root = NULL;

    return;
}

int where_to_add_new_node(node * original_node, node * new_node) {
    int compare =
        strcmp((original_node->node_item).word, (new_node->node_item).word);

    if (compare > 0)
        return TO_LEFT;
    else if (compare < 0)
        return TO_RIGHT;
    else
        return THE_SAME;
}

bool add_item_to_tree(item new_item, tree * ptree) {
    node * new_node = (node *)malloc(sizeof(node));
    node ** father_node = &ptree->root;
    int new_node_position;

    if (!new_node) /* the node is NULL */
        return false;

    new_node->node_item = new_item;
    new_node->left = new_node->right = NULL;

    if (!*father_node) /* the tree is empty */
        *father_node = new_node;
    else {
        while (*father_node) /* father_node is no NULL */
        {
            new_node_position = where_to_add_new_node(*father_node, new_node);

            if (new_node_position == TO_LEFT)
                father_node = &(*father_node)->left;
            else if (new_node_position == TO_RIGHT)
                father_node = &(*father_node)->right;
            else /* there is the same item */
            {
                ((*father_node)->node_item).count++;
                free(new_node); // delete new_node
                return true;
            }
        }
        *father_node = new_node;
    }

    return true;
}

void show_tree_items(node * tree_root) {
    if (tree_root == NULL)
        return;
    printf("\"%s\" occurs %d times\n", (tree_root->node_item).word,
           (tree_root->node_item).count);

    show_tree_items(tree_root->left);
    show_tree_items(tree_root->right);

    return;
}

void clear_tree(node * tree_root) {
    if (tree_root->left)
        clear_tree(tree_root->left);
    else if (tree_root->right)
        clear_tree(tree_root->right);
    else
        free(tree_root);

    return;
}
