#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list using
 * Cocktail Shaker Sort Algorithm
 * @list: The linked list
 *
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start, *end, *current;

	start = *list;
	end = NULL;
	if (!list || !(*list)->next)
		return;

	do {
		swapped = 0;
		current = start;
		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->next;
		}
		end = current;
		if (!swapped)
			break;
		swapped = 0;
		current = end->prev;
		while (current && current != start)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->prev;
		}
		start = current->next;
	} while (swapped);
}

/**
 * swap_nodes - Swaps nodes for cocktail_sort_list function
 *
 * @left: Goes left to right
 * @right: Goes right to left
 */

void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;

	else
		*list = right;

	if (right->next)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;
	right->next = left;
	left->prev = right;
}
