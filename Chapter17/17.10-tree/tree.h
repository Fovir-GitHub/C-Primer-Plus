#ifndef _TREE_H_
#define _TREE_H_

#include <stdbool.h>

typedef struct item {
    char petname[20];
    char petkind[20];
} Item;

#define MAXITEMS 10
#define SLEN 20

typedef struct trnode {
    Item item;
    struct trnode * left;
    struct trnode * right;
} Trnode;

typedef struct tree {
    Trnode * root;
    int size;
} Tree;

void InitializeTree(Tree * ptree);
bool TreeIsempty(const Tree * ptree);
bool TreeIsFull(const Tree * ptree);
int TreeItemCount(const Tree * ptree);
bool AddItem(const Item * pi, Tree * ptree);
bool InTree(const Item * pi, const Tree * ptree);
bool DeleteItem(const Item * pi, Tree * ptree);
void Traverse(const Tree * ptree, void (*pfun)(Item item));
void DeleteAll(Tree * ptree);

#endif // !_TREE_H_