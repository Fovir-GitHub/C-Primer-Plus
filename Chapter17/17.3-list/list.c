#include "list.h"

static void CopyToNode(Item item, Node * pnode);

void InitializeList(List * plist) { *plist = NULL; }
bool ListIsEmpty(const List * plist) {
    if (*plist == NULL)
        return true;
    return false;
}

bool ListIsFull(const List * plist) {
    Node * pt;
    bool full;

    pt = (Node *)malloc(sizeof(Node));
    if (pt == NULL)
        full = true;
    else
        full = false;
    free(pt);

    return full;
}

unsigned int ListItemCount(const List * plist) {
    unsigned int count = 0;
    Node * pnode = *plist;

    while (pnode) {
        ++count;
        pnode = pnode->next;
    }

    return count;
}

bool AddItem(Item item, List * plist) {
    Node * pnew;
    Node * scan = *plist;

    pnew = (Node *)malloc(sizeof(Node));
    if (pnew == NULL)
        return false;

    CopyToNode(item, pnew);
    pnew->next = NULL;

    if (scan == NULL)
        *plist = pnew;
    else {
        while (scan->next != NULL)
            scan = scan->next;
        scan->next = pnew;
    }

    return true;
}

void Traverse(const List * plist, void (*pfun)(Item Item)) {
    Node * pnode = *plist;

    while (pnode) {
        (*pfun)(pnode->item);
        pnode = pnode->next;
    }

    return;
}

void EmtpyTheList(List * plist) {
    Node * psave;

    while (*plist) {
        psave = (*plist)->next;
        free(*plist);
        *plist = psave;
    }

    return;
}

void CopyToNode(Item item, Node * pnode) {
    pnode->item = item;

    return;
}
