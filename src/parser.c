/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 14:34:35 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/28 17:15:41 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	parser(t_file *file)
{
	t_data data;
	t_links *l;

	l = NULL;
	if (ft_isnumber(file->line))
		data.ants = ft_atoi(file->line);
	else
		return (0);
	while (file)
	{
		if (ft_strcmp(file->line, "##start") == 0)
			data.start = ft_split(file->next->line)[0];
		else if (ft_strcmp(file->line, "##end") == 0)
			data.end = ft_split(file->next->line)[0];
		else
			is_link(file->line, &l);
		file = file->next;
	}
	assign_nb(&l, &data);
	return (1);
}
