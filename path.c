#include "lemin.h"

int	print_path(t_path **path, t_data *data)
{
	int nb;
	void *tmp;
	t_path *last;

	nb = 0;
	tmp = *path;
	last = adr_last_room(path, last);
	while (last->ant != data->ants)
	{
		if (*path && (*path)->ant == 0)
		{
			(*path)->ant = 1;
			printf("L%d-%s\n", (*path)->ant, data->id[(*path)->id]);
		}
		else
		{
			while (*path && (*path)->ant != 0)
			{
				if ((*path)->ant < data->ants)
				{
					(*path)->ant += 1;
					printf("L%d-%s ", (*path)->ant, data->id[(*path)->id]);
				}
				nb = (*path)->ant;
				*path = (*path)->next;
			}
			if (*path)
			{
				(*path)->ant = nb - 1;
				printf("L%d-%s", (*path)->ant, data->id[(*path)->id]);
			}
			printf("\n");
		}
		*path = tmp;
	}
	return (0);
}

int	path(t_tabs *tabs, t_data *data)
{
	int u;
	t_path *path;

	path = malloc(sizeof(t_path));
	if (tabs->dist[data->end_id] < data->rooms)
	{
		u = data->end_id;
		path->id = u;
		path->ant = 0;
		path->next = NULL;
		while (tabs->father[u] != -1)
		{
			path = add_to_path(&path, tabs->father[u]);
			u = tabs->father[u];
		}
		print_path(&path, data);
	}
	return (0);
}
