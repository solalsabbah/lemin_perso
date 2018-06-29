#include "lemin.h"

void	init_tabs(int *col, int *father, int *dist, t_data *data)
{
	int a;

	a = 0;
	while (a <= data->rooms)
	{
		col[a] = 0;
		father[a] = 0;
		dist[a] = data->rooms + 1;
		a++;
	}
	col[a] = -1;
	father[a] = -1;
	dist[a] = -1;
}
