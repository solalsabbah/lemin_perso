#include "lemin.h"

void	init(int *col, int *father, int *dist /*room in parameter*/)
{
	int a;

	a = 0;
	while (a < 8)
	{
		col[a] = 0;
		father[a] = 0;
		dist[a] = 8;
		a++;
	}
	col[a] = -1;
	father[a] = -1;
	dist[a] = -1;
}

int	algo(int *col, int *father, int *dist, t_queue *queue, t_links **l /*room in parameter*/)
{
	int 	u;
	t_links *tmp;
	void 	*adr;
	void 	*start;

	tmp = *l;
	start = queue;
	while (queue)
	{
		u = queue->room;
		adr = queue;
		while (*l) // parcours la liste des voisins
		{
			if (ft_atoi((*l)->a) == u) // voisin de U (l->a)
			{
				if (col[ft_atoi((*l)->b)] == 0) // couleur de v = Blanc ?
				{
					col[ft_atoi((*l)->b)] = 1;
					dist[ft_atoi((*l)->b)] = dist[u] + 1;
					father[ft_atoi((*l)->b)] = u;
					while (queue->next)
						queue = queue->next;
					queue->next = malloc(sizeof(t_queue));
					queue->next->room = ft_atoi((*l)->b);
					queue->next->next = NULL;
					queue = queue->next;
					del_link(&tmp, *l);
				}
			}
			else if (ft_atoi((*l)->b) == u) // voisin de U
			{
				if (col[ft_atoi((*l)->a)] == 0)
				{
					col[ft_atoi((*l)->a)] = 1;
					dist[ft_atoi((*l)->a)] = dist[u] + 1;
					father[ft_atoi((*l)->a)] = u;
					while (queue->next)
						queue = queue->next;
					queue->next = malloc(sizeof(t_queue));
					queue->next->room = ft_atoi((*l)->a);
					queue->next->next = NULL;
					queue = queue->next;
					del_link(&tmp, *l);
				}
			}
			*l = (*l)->next;
		}
		*l = tmp;
		queue = adr;
		if (queue && u == queue->room)
			queue = queue->next;
		col[u] = 2;
	}
	*l = tmp;

	int a;

	a = 0;
	while (father[a] != -1)
	{
		printf("%d\n", father[a]);
		printf("col : %d\n", col[a]);
		a++;
	}
	printf("distance %d\n", dist[7]);
	printf("distance %d\n", dist[4]);
	printf("distance %d\n", dist[3]);
	while (*l)
	{
		printf("[%s]-[%s]\n", (*l)->a, (*l)->b);
		*l = (*l)->next;
	}
	return (0);
}

int solve(t_links **l, t_data *data)
{
	t_queue *queue;
	int *col;
	int *dist;
	int	*father;

	queue = malloc(sizeof(t_queue));
	col = malloc(sizeof(int) * 9);
	father = malloc(sizeof(int) * 9);
	dist = malloc(sizeof(int) * 9);

	init(col, father, dist);
	queue->room = ft_atoi(data->start);
	col[queue->room] = 1;
	dist[queue->room] = 0;
	algo(col, father, dist, queue, l);
	return (0);
}
