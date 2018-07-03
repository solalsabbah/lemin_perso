#include "lemin.h"

void	init_tabs(t_tabs *tabs, t_data *data)
{
	int a;

	a = 0;
	tabs->col = malloc(sizeof(int) * data->rooms + 1);
	tabs->father = malloc(sizeof(int) * data->rooms + 1);
	tabs->dist = malloc(sizeof(int) * data->rooms + 1);
	while (a <= data->rooms)
	{
		tabs->col[a] = 0;
		tabs->father[a] = -1;
		tabs->dist[a] = data->rooms + 1;
		a++;
	}
	tabs->col[a] = -1;
	tabs->father[a] = -1;
	tabs->dist[a] = -1;
}
