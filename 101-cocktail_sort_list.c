#include "sort.h"

/**
 * switcher - swap nodes in doubly linked list (DLL)
 * help function for computing the Cocktail Sort on a DLL
 * @list: double pointer to start of DLL
 * @swap: pointer on the node to swap
 */

void switcher(listint_t **list, listint_t *swap)
{
	swap->next->prev = swap->prev;
	if (swap->prev)
		swap->prev->next = swap->next;
	else
		*(list) = swap->next;
	swap->prev = swap->next;
	swap->next = swap->next->next;
	swap->prev->next = swap;
	if (swap->next)
		swap->next->prev = swap;
}

/**
 * cocktail_sort_list - "cocktail sort" also called bi-directionnal
 * bubble sort. Here we cross the list in both directions
 * alternatively, forward and backward.
 * @list: double pointer to start of linked list
 */

void cocktail_sort_list(listint_t **list)
{
	int status = 1;
	listint_t *tmp;

	if (!list || !*list)
		return;
	tmp = *list;
	while (status != 0)
	{
		status = 0;
		while (tmp->next != NULL)
		{
			if (tmp->next->n < tmp->n)
			{
				switcher(list, tmp);
				status = 1;
				print_list(*list);
			}
			else
				tmp = tmp->next;
		}
		if (status == 0)
			break;
		status = 0;
		while (tmp->prev != NULL)
		{
			if (tmp->prev->n > tmp->n)
			{
				switcher(list, tmp->prev);
				status = 1;
				print_list(*list);
			}
			else
				tmp = tmp->prev;
		}
	}
}
