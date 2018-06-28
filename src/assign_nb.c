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

	tmp = room;
	tmp_l = *l;
	
	while (*l)
	{
		add_to_room((*l)->a, &room);
		add_to_room((*l)->b, &room);
		(*l) = (*l)->next;
		data->rooms = room->nb;
		room = tmp;
	}
	*l = tmp_l;
	add_cnx(l, &room, data);
	return (0);
}
