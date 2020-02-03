#include "sort.h"
/**
 *insertion_sort_list - sort list
 *@list: lsit to sort
 *Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *aux, *_tmp, *_prev, *_next;

	aux = *list;
	while (aux->n < aux->next->n)
	{
		aux = aux->next;
		if (!aux->next)
			return;
	}
	_tmp = aux->prev;
	_prev = aux->next;
	_next = aux->next->next;
	_prev->prev = _tmp;
	_prev->next = aux;
	aux->next = _next;
	aux->prev = _prev;
	if (_tmp == NULL)
	{
		_next->prev = aux;
		*list = _prev;
	}
	else if (_next == NULL)
		_tmp->next = _prev;
	else
	{
		_next->prev = aux;
		_tmp->next = _prev;
	}
	print_list(*list);
	insertion_sort_list(list);
}
