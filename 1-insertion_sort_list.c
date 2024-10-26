#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort algorithm
 * @list: The linked list
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *node1, *node2, *tmp;

	ptr = *list;
	while (ptr->next != NULL)
	{
		node1 = ptr;
		node2 = ptr->next;
		while (node1->n > node2->n)
		{
			if (node2->next)
			{
				node1->next = node2->next;
				node2->next->prev = node1;
			}
			else
				node1->next = NULL;

			if (node1->prev)
				node2->prev = node1->prev;

			else
				node2->prev = NULL;

			node1->prev = node2;

			if (node1->prev == NULL)
				break;

			node1 = node1->prev;
			node2 = node2->prev;
			tmp = node1;
			node1 = node2;
			node2 = tmp;
		}

		print_list(*list);
		ptr = ptr->next;
	}
}
