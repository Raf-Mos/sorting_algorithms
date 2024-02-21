#include "sort.h"

/**
 * cocktail_sort_list - Prints an array of integers
 *
 * @list: The array to be printed
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *move_ptr, *right_ptr, *left_ptr;

	if (list == NULL || !(*list) || (*list)->next == NULL)
		return;

	right_ptr = NULL;
	move_ptr = left_ptr = (*list);
	while (left_ptr != right_ptr)
	{
		while (move_ptr != right_ptr && move_ptr->next != NULL)
		{
			if (move_ptr->n > move_ptr->next->n)
			{
				swap_nodes(list, move_ptr, move_ptr->next);
				print_list(*list);
			}
			else
				move_ptr = move_ptr->next;
		}
		move_ptr = move_ptr->prev;
		right_ptr = move_ptr;

		if (left_ptr->prev == right_ptr && right_ptr->next == left_ptr)
			break;

		while (move_ptr != left_ptr && move_ptr->prev != NULL)
		{
			if (move_ptr->n < move_ptr->prev->n)
			{
				swap_nodes(list, move_ptr->prev, move_ptr);
				print_list(*list);
			}
			else
				move_ptr = move_ptr->prev;
		}
		move_ptr = move_ptr->next;
		left_ptr = move_ptr;
	}
}

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list
 * @list: pointer to the head of the list
 * @n1: first node to swap
 * @n2: second node to swap
 */
void swap_nodes(listint_t **list, listint_t *n1, listint_t *n2)
{
	if (n1->prev)
		n1->prev->next = n2;
	else
		*list = n2;

	if (n2->next)
		n2->next->prev = n1;

	n1->next = n2->next;
	n2->prev = n1->prev;
	n1->prev = n2;
	n2->next = n1;
}
