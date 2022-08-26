#include "sort.h"

/**
 * switcher - swap nodes in doubly linked list (DLL)
 * help function for computing the Cocktail Sort on a DLL
 * @list: double pointer to start of DLL
 * @nod: pointer on the node to swap
 */

void switcher(listint_t **list, listint_t *nod)
{
	nod->next->prev = nod->prev;
	if (nod->prev != NULL)
		nod->prev->next = nod->next;
	else
		*list = nod->next;
	nod->prev = nod->next;
	nod->next = nod->next->next;
	nod->prev->next = nod;
	if (nod->next != NULL)
		nod->next->prev = nod;
}
/**
 * cocktail_sort_list - "cocktail sort" also called bi-directionnal bubble sort.
 * here we cross the list in both directions alternatively, forward and backward.
 *
 */

void cocktail_sort_list(listint_t **list)
{
	int status = 1;
	listint_t *tmp;

	if (!list || !*list)
		return;
	tmp = *list;
	while (status)
	{
		status = 0;
		while (tmp->next != NULL)
		{
			if (tmp->n < tmp->next->n)
			{
				switcher(list, tmp);
				status = 1;
				print_list(*list);
			}
			else
				tmp = tmp->next;
		}
		if (status)
			break;
		status = 0;
		while (tmp->prev != NULL)
		{
			if (tmp->n < tmp->prev->n)
			{
				switcher(list, tmp);
				status = 1;
				print_list(*list);
			}
			else
				tmp = tmp->prev;
		}
	}
}
