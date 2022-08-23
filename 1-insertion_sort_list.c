#include "sort.h"

/**
 * @brief
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *swap, *after;

	if (*list == NULL)
		return;

	swap = (*list)->next;
	while (swap)
	{
		after = swap->next;
		while (swap->prev != NULL && swap->prev->n > swap->n)
		{
			swap->prev->next = swap->next;
			if (swap->next != NULL)
				swap->next->prev = swap->prev;
			swap->next = swap->prev;
			swap->prev = swap->next->prev;
			swap->next->prev = swap;
			if (swap->prev == NULL)
				(*list) = swap;
			else
				swap->prev->next = swap;
			print_list(*list);
		}
		swap = after;
	}
}
