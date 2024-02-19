#include "sort.h"

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

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || *list == NULL)
		return;

	node = (*list)->next;
	while (node != NULL)
	{
		while (node->prev != NULL && node->prev->n > node->n)
		{
			swap_nodes(list, node->prev, node);
			print_list(*list);
		}
		node = node->next;
	}
}
