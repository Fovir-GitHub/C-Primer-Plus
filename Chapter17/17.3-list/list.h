#ifndef _LIST_H_
#define _LIST_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define TSIZE 45

typedef struct _FILM_
{
    char title[TSIZE];
    int  rating;
} film;

typedef film Item;

typedef struct node
{
    Item          item;
    struct node * next;
} Node;

typedef Node * List;

void         InitializeList(List * plist);
bool         ListIsEmpty(const List * plist);
bool         ListIsFull(const List * plist);
unsigned int ListItemCount(const List * plist);
bool         AddItem(Item item, List * plist);
void         Traverse(const List * plist, void (*pfun)(Item Item));
void         EmtpyTheList(List * plist);

#endif // !_LIST_H_