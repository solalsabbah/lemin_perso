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

void	algo(t_tabs *tabs, t_queue *queue, t_cnx **cnx)
{
	int 	u;
	void 	*adr;
	t_cnx	*tmp;

	tmp = *cnx;
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
}

int solve(t_cnx **cnx, t_data *data)
{
	t_tabs *tabs;
	t_queue	*queue;

	tabs = malloc(sizeof(t_tabs));
	queue = malloc(sizeof(t_queue));
	init_tabs(tabs, data);
	queue->room = data->start_id;
	queue->next = NULL;
	tabs->col[queue->room] = 1;
	tabs->dist[queue->room] = 0;
	algo(tabs, queue, cnx);
	path(tabs, data);
	return (0);
}
