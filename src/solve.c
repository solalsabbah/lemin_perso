/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:02:08 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/28 17:14:21 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	algo(int *col, int *father, int *dist, t_queue *queue, t_cnx **cnx)
{
	int 	u;
	t_cnx *tmp;
	void 	*adr;
	void 	*start;

	tmp = *cnx;
	start = queue;
	while (queue)
	{
		u = queue->room;
		adr = queue;
		while (*cnx) // parcours la liste des voisins
		{
			if ((*cnx)->a == u) // voisin de U (l->a)
			{
				if (col[(*cnx)->b] == 0) // couleur de v = Blanc ?
				{
					col[(*cnx)->b] = 1;
					dist[(*cnx)->b] = dist[u] + 1;
					father[(*cnx)->b] = u;
					while (queue->next)
						queue = queue->next;
					queue->next = malloc(sizeof(t_queue));
					queue->next->room = (*cnx)->b;
					queue->next->next = NULL;
					queue = queue->next;
					del_cnx(&tmp, *cnx);
				}
			}
			else if ((*cnx)->b == u) // voisin de U
			{
				if (col[(*cnx)->a] == 0)
				{
					col[(*cnx)->a] = 1;
					dist[(*cnx)->a] = dist[u] + 1;
					father[(*cnx)->a] = u;
					while (queue->next)
						queue = queue->next;
					queue->next = malloc(sizeof(t_queue));
					queue->next->room = (*cnx)->a;
					queue->next->next = NULL;
					queue = queue->next;
					del_cnx(&tmp, *cnx);
				}
			}
			*cnx = (*cnx)->next;
		}
		*cnx = tmp;
		queue = adr;
		if (queue && u == queue->room)
			queue = queue->next;
		col[u] = 2;
	}
	*cnx = tmp;

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
	while (*cnx)
	{
		printf("[%d]-[%d]\n", (*cnx)->a, (*cnx)->b);
		*cnx = (*cnx)->next;
	}
	return (0);
}

int solve(t_cnx **cnx, t_data *data)
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
	algo(col, father, dist, queue, cnx);
	return (0);
}
