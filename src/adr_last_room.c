#include "lemin.h"

t_path	*adr_last_room(t_path **path, t_path *last)
{
	void *tmp;

	tmp = *path;
	last = *path;
	while ((*path)->next)
	{

		(*path) = (*path)->next;
		last = *path;
	}
	*path = tmp;
	return (last);
}
