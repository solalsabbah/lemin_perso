/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 14:34:35 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/14 17:57:24 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	mytree(t_links *l, t_data *data)
{
	t_node *tree;

	l = l->next;
	tree = malloc(sizeof(t_node));
	printf("%p\n", tree);
	tree->room = data->start;
	tree->brother = NULL;
	tree->children = malloc(sizeof(t_node));
	tree->children->brother = malloc(sizeof(t_node));

	printf("[%s]\n", tree->room);
	return (0);
}

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
/*	while (l)
	{
		printf("l->a [%s] ", l->a);
		printf("l->b [%s]\n", l->b);
		l = l->next;
	}*/
	mytree(l, &data);
	return (1);
}
