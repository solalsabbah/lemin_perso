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

int	create_tree(t_links **l, t_node **tree)
{
	void 	*tmp;
	void	*tmp_l;
	
	tmp_l = *l;
	while (*l)
	{
		if (ft_strcmp((*l)->a, (*tree)->room) == 0 && (*tree)->child == NULL)
		{	
			(*tree)->child = malloc(sizeof(t_node));
			tmp = (*tree)->child;
			(*tree)->child->room = (*l)->b;
		}
		else if (ft_strcmp((*l)->a, (*tree)->room) == 0 && (*tree)->child->room != NULL)
		{
			(*tree)->child->bro = malloc(sizeof(t_node));
			(*tree)->child->bro->room = (*l)->b;
			(*tree)->child = (*tree)->child->bro;
		}
		if (ft_strcmp((*l)->b, (*tree)->room) == 0 && (*tree)->child == NULL)
		{
			(*tree)->child = malloc(sizeof(t_node));
			tmp = (*tree)->child;
			(*tree)->child->room = (*l)->a;
		}
		else if (ft_strcmp((*l)->b, (*tree)->room) == 0 && (*tree)->child->room != NULL)
		{
			(*tree)->child->bro = malloc(sizeof(t_node));
			(*tree)->child->bro->room = (*l)->a;
			(*tree)->child = (*tree)->child->bro;
		}
		(*l) = (*l)->next;	
	}
	(*tree)->child = tmp;
	*l = tmp_l;
	return (0);
}

int	mytree(t_links *l, t_data *data)
{
	t_node *tree;

	tree = malloc(sizeof(t_node));
	tree->room = data->start;

	create_tree(&l, &tree);

	printf("%p\n", tree);
	printf("tmp : %p\n", tree->child);
	printf("[%s]\n", tree->room);
	printf("[%s]\n", tree->child->room);
	printf("[%s]\n", tree->child->bro->room);
	printf("[%s]\n", tree->child->bro->bro->room);
	printf("[%s]\n\n", tree->child->bro->bro->bro->room);
	while (l)
	{
		printf("[%s]-[%s]\n", l->a, l->b);
		l = l->next;
	}	
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
	mytree(l, &data);
	return (1);
}
