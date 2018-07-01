/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_nb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:17:15 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/28 18:07:19 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	assign_nb(t_links **l, t_data *data)
{
	void	*tmp;
	void	*tmp_l;
	t_room	*room;

	tmp_l = *l;
	room = malloc(sizeof(t_room));
	room->name = NULL;
	tmp = room;
	while (*l)
	{
		add_to_room((*l)->a, &room);
		add_to_room((*l)->b, &room);
		(*l) = (*l)->next;
		data->rooms = room->nb;
		room = tmp;
	}
	data->id = malloc(sizeof(char *) * (data->rooms + 2));
	while (room)
	{
		data->id[room->nb] = room->name;
		room = room->next;
	}
	data->id[data->rooms + 1] = NULL;
	*l = tmp_l;
	room = tmp;
	add_cnx(l, &room, data);
	return (0);
}
