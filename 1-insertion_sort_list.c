#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @previo: A pointer to the first node to swap.
 * @nwxto: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **previo, listint_t *nwxto)
{
	(*previo)->next = nwxto->next;
	if (nwxto->next != NULL)
		nwxto->next->prev = *previo;
	nwxto->prev = (*previo)->prev;
	nwxto->next = *previo;
	if ((*previo)->prev != NULL)
		(*previo)->prev->next = nwxto;
	else
		*h = nwxto;
	(*previo)->prev = nwxto;
	*previo = nwxto->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * @list: A pointer to the head of a doubly-linked list of integers.
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = temp)
	{
		temp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
