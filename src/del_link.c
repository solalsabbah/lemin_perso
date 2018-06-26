/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 16:18:01 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/26 16:32:54 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	del_link(t_links **l, t_links *elem)
{
	t_links *tmp;

	tmp = *l;
	if ((*l) == elem)
	{
		(*l) = (*l)->next;
		tmp = *l;
	}
	else
	{
		while ((*l)->next != elem)
			(*l) = (*l)->next;
		(*l)->next = elem->next;
	}
	free(elem);
	elem = NULL;
	*l = tmp;
}
