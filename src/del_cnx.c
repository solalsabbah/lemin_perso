/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_cnx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 17:10:12 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/28 17:14:02 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	del_cnx(t_cnx **cnx, t_cnx *elem)
{
	t_cnx *tmp;

	tmp = *cnx;
	if ((*cnx) == elem)
	{
		(*cnx) = (*cnx)->next;
		tmp = *cnx;
	}
	else
	{
		while ((*cnx)->next != elem)
			(*cnx) = (*cnx)->next;
		(*cnx)->next = elem->next;
	}
	free(elem);
	elem = NULL;
	*cnx = tmp;
}
