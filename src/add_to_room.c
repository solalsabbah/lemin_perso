/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 16:39:50 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/28 16:40:09 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	add_to_room(char *name, t_room **room)
{
	if ((*room)->name == NULL)
	{
		(*room)->name = name;
		(*room)->nb = 0;
		(*room)->next = NULL;
		return (0);
	}
	while ((*room)->next)
	{
		if (ft_strcmp((*room)->name, name) == 0)
			return (0);
		*room = (*room)->next;
	}
	if (ft_strcmp((*room)->name, name) == 0)
		return (0);
	(*room)->next = malloc(sizeof(t_room));
	(*room)->next->name = name;
	(*room)->next->nb = (*room)->nb + 1;
	(*room)->next->next = NULL;
	return (1);
}
