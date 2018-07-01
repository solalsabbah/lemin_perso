/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:02:08 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/28 18:06:49 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	path(t_tabs *tabs, t_data *data)
{
	int a;
	
	a = 0;
	while (data->id[a] != NULL)
	{
		printf("%s\n", data->id[a]);
	//	printf("%s [%d]\n", data->id[a], tabs->dist[a]);
		a++;	
	}
	return (0);
}

void	fill_tabs(t_tabs *tabs, t_queue *queue, int cnx, int u)
{
	tabs->col[cnx] = 1;
	tabs->dist[cnx] = tabs->dist[u] + 1;
	tabs->father[cnx] = u;
	while (queue->next)
		queue = queue->next;
	queue->next = malloc(sizeof(t_queue));
	queue->next->room = cnx;
	queue->next->next = NULL;
	queue = queue->next;
}

int	algo(t_tabs *tabs, t_queue *queue, t_cnx **cnx)
{
	int 	u;
	t_cnx	*tmp;
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
			if ((*cnx)->a == u && tabs->col[(*cnx)->b] == 0) //voisin de u et  couleur de v = Blanc ?
			{
				fill_tabs(tabs, queue, (*cnx)->b, u);
				del_cnx(&tmp, *cnx);
			}
			else if ((*cnx)->b == u && tabs->col[(*cnx)->a] == 0)
			{
				fill_tabs(tabs, queue, (*cnx)->a, u);
				del_cnx(&tmp, *cnx);
			}
			*cnx = (*cnx)->next;
		}
		*cnx = tmp;
		queue = adr;
		if (queue && u == queue->room)
			queue = queue->next;
		tabs->col[u] = 2;
	}
	*cnx = tmp;
	return (0);
}

int solve(t_cnx **cnx, t_data *data)
{
	t_tabs *tabs;
	t_queue	*queue;

	tabs = malloc(sizeof(t_tabs));
	queue = malloc(sizeof(t_queue));
	tabs->col = malloc(sizeof(int) * data->rooms + 1);
	tabs->father = malloc(sizeof(int) * data->rooms + 1);
	tabs->dist = malloc(sizeof(int) * data->rooms + 1);
	init_tabs(tabs->col, tabs->father, tabs->dist, data);
	queue->room = data->start_id;
	tabs->col[queue->room] = 1;
	tabs->dist[queue->room] = 0;
	algo(tabs, queue, cnx);
	path(tabs, data);
	return (0);
}
