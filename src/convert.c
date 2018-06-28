/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 16:24:05 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/28 17:40:49 by ssabbah          ###   ########.fr       */
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
			printf("je suis la\n");
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

	tmp = cnx;

/*	while (*room)
	{
		printf("%8s %d\n", (*room)->name, (*room)->nb);
		*room = (*room)->next;
	}
*/
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
	while (cnx)
	{
		printf("%4d %d\n", cnx->a, cnx->b);
		cnx = cnx->next;
	}
//	solve(&cnx, data); //SOLVE 
}
