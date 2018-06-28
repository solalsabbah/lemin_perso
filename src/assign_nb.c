/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_nb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:17:15 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/28 17:24:47 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	assign_nb(t_links **l, t_data *data)
{
	void	*tmp;
	void	*tmp_l;
	t_room	*room;

	tmp = room;
	tmp_l = *l;
	
	while (*l)
	{
		add_to_room((*l)->a, &room);
		add_to_room((*l)->b, &room);
		(*l) = (*l)->next;
		room = tmp;
	}
	*l = tmp_l;

/*	while (room)
	{
		printf("%8s %d\n", room->name, room->nb);
		room = room->next;
	}*/
	add_cnx(l, &room, data);
	return (0);
}
