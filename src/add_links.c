/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:32:50 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/28 15:04:32 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	add_links(t_links **l, char *a, char *b)
{
	t_links *tmp;

	tmp = *l;
	if (*l == NULL)
	{
		*l = malloc(sizeof(t_links));
		(*l)->a = a;
		(*l)->b = b;
		(*l)->next = NULL;
		tmp = *l;
	}
	else
	{
		while ((*l)->next)
			*l = (*l)->next;
		(*l)->next = malloc(sizeof(t_links));
		(*l)->next->a = a;
		(*l)->next->b = b;
		(*l)->next->next = NULL;
	}
	*l = tmp;
}
