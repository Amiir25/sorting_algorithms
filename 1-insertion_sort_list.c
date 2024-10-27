#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using
 * insertion sort algorithm
 * @list: The linked list
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *first, *second;

	if (!list || !(*list) || !(*list)->next)
		return;

	ptr = (*list)->next;	/* Node 2 */
	while (ptr)
	{
		first = ptr->prev;	/* Node 1 */
		second = ptr;		/* Node 2 */
		while (first && second->n < first->n)
		{
			swap_node(list, first, second);
			first = second->prev;
			print_list(*list);
		}

		ptr = ptr->next;
	}
}

/**
 * swap_node - Swaps two nodes in a doubly linked list
 *
 * @list: The linked list
 * @node1: The first node
 * @node2: The second node
 */

void swap_node(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;

	else
		*list = node2;	/* Update the head */

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->next = node1;
	node2->prev = node1->prev;
	node1->prev = node2;
}
