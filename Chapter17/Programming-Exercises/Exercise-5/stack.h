/*
 * @Author: Fovir
 * @Email: fovir@disroot.org
 * @Date: 2024-08-03 22:21:24
 * @Last Modified by:   Fovir
 * @Last Modified time: 2024-08-03 23:47:03
 * @Description: This is my own stack header file.
 *				The stack is a FILO data structure.
 */

#ifndef _STACK_H_
#define _STACK_H_

#include<stdbool.h>

typedef char item;

typedef struct Node
{
	item node_item;
	struct Node * front;
	struct Node * next;
}node;

typedef struct Stack
{
	node * head;
	node * rear;
}stack;

/// @brief This function is used to initialize a stack.
/// @param st the stack
void init_stack(stack * st);

/// @brief Used to check whether the stack is empty.
/// @param st the stack
/// @return If the stack is empty, it will be true.
bool stack_is_empty(stack * st);

/// @brief The function is used to add new item to the stack.
/// @param new_item new item to add
/// @param st the stack
/// @return If the item is added successfully, it will return true.
bool add_item_to_stack(item new_item, stack * st);

/// @brief The function is used to pop the first element up from the stack.
/// @param st the stack
/// @return If pop up successfully, it will return the item from the back of stack.
item pop_up_from_stack(stack * st);

/// @brief The function is used to clear the stack.
/// @param st the stack you want to clear
void clear_stack(stack * st);

#endif // !_STACK_H_