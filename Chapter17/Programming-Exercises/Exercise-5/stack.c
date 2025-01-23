#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void init_stack(stack * st)
{
    st->head = NULL;
    st->rear = NULL;

    return;
}

bool stack_is_empty(stack * st)
{
    // if the head is NULL, the stack is empty
    return st->head == NULL;
}

bool add_item_to_stack(item new_item, stack * st)
{
    node * new_node = (node *) malloc(sizeof(node));

    if (!new_node) /* new_node is NULL */
        return false;

    new_node->node_item = new_item; /* set item*/
    new_node->next = NULL;

    if (stack_is_empty(st)) /* the first node */
    {
        new_node->front = NULL;
        st->head = new_node;
        st->rear = new_node;
    }
    else
    {
        new_node->front = st->rear;
        st->rear->next = new_node;
        st->rear = new_node;
    }

    return true;
}

item pop_up_from_stack(stack * st)
{
    if (stack_is_empty(st)) /* nothing to pop up */
    {
        fprintf(stderr, "The stack is empty.\n");
        exit(1);
    }

    node * temp = st->rear; /* back up the pointer of stack rear */
    item return_item = st->rear->node_item; /* the return value */

    if (st->head == st->rear) /* only one element in stack */
        st->head = st->rear = NULL;
    else
    {
        st->rear = st->rear->front;
        st->rear->next = NULL;
    }

    free(temp);

    return return_item;
}

void clear_stack(stack * st)
{
    node * temp;

    while (st->head) /* stack->head != NULL */
    {
        temp = st->rear;            /* back up st->rear */
        st->rear = st->rear->front; /* move to the next */
        free(temp);
    }
    st->rear = NULL;
    st->head = NULL;

    return;
}
