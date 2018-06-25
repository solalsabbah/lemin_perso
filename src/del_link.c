#include "lemin.h"

void	del_link(t_links **l, t_links *elem)
{
	void *tmp;

	tmp = *l;
	if ((*l) == elem)
	{
		(*l) = (*l)->next;
		tmp = *l;
	}
	else
	{
		while ((*l)->next != elem)
			(*l) = (*l)->next;
		(*l)->next = elem->next;
	}
	free(elem);
	elem = NULL;
	*l = tmp;
}
