#include "lemin.h"

t_path	*add_to_path(t_path **path, int id)
{
	t_path *new;

	new = malloc(sizeof(t_path));
	new->id = id;
	new->ant = 0;
	new->next = *path;
	return (new);
}
