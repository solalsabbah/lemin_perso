/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 16:24:05 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/28 18:00:33 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"


int	find_id(char *name, t_room **room)
{
	void *tmp;
	int nb;

	tmp = *room;
	while (*room)
	{
		if (ft_strcmp(name, (*room)->name) == 0)
		{
			nb = (*room)->nb;
			*room = tmp;
			return (nb);
		}
		*room = (*room)->next;
	}
	*room = tmp;
	return (-1);
}

void	add_cnx(t_links **l, t_room **room, t_data *data)
{
	void	*tmp;
	t_cnx	*cnx;

	cnx = malloc(sizeof(t_cnx));
	tmp = cnx;
	while (*l)
	{
		cnx->a = find_id((*l)->a, room);
		cnx->b = find_id((*l)->b, room);
		cnx->next = malloc(sizeof(t_cnx));
		cnx = cnx->next;
		cnx->next = NULL;
		*l = (*l)->next;
	}
	cnx = tmp;
	if ((data->start_id = find_id(data->start, room)) == -1 || (data->end_id = find_id(data->end, room)) == -1)
	{
		printf("Error\n");
		exit (0);
	}	
	solve(&cnx, data);
}
