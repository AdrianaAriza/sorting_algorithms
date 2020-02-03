#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *aux, *_tmp, *_prev, *_next;
/**	int n_aux;

	aux = *list;

	while (aux && aux->next)
	{
		if (aux->n < aux->next->n)
		{
			aux = aux->next;
		}
		else
		{
			n_aux = aux->n;
			*(int *)&aux->n = (int)aux->next->n;
			*(int *)&aux->next->n = n_aux;
			print_list(*list);
			while(aux->next && aux->prev && aux->n < aux->prev->n)
			{
				aux = aux->prev;
				n_aux = (int)aux->n;
				*(int *)&aux->n = (int)aux->next->n;
				*(int *)&aux->next->n = n_aux;
				print_list(*list);
			}
		}
	}

*/
	aux = *list;
	while(aux->n < aux->next->n){
		aux = aux->next;
		if(!aux->next)
			return ;
	}
	_tmp = aux->prev;
	_prev = aux->next;
	_next = aux->next->next;
	_prev->prev = _tmp;
	_prev->next = aux;
	aux->next = _next;
	aux->prev = _prev;
	if(_tmp == NULL){
		_next->prev = aux;
		*list = _prev;
	}
	else if(_next == NULL)
		_tmp->next = _prev;
	else
	{
		_next->prev = aux;
		_tmp->next = _prev;
	}
	print_list(*list);
	insertion_sort_list(list);
}
