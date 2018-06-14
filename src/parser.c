/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 14:34:35 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/14 15:34:12 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*int	mytree(t_file *file, t_data data)
{
	t_node *tree;

	tree = malloc(sizeof(t_node));
	printf("%p\n", tree);
	tree->val = data.start;
	tree->brother = NULL;
	tree->children = malloc(sizeof(t_node));
	tree->children->val = 8;
	tree->children->brother = malloc(sizeof(t_node));
	tree->children->brother->val = 13;
	printf("brother %p\n", tree->children->brother);

	printf("[%d]\n", tree->val);
	printf("[%d]\n", tree->children->val);
}*/

int	 is_room(char *line)
{
	int i;
	int	a;
	t_links *l;

	i = 0;
	a = 0;
	l = malloc(sizeof(t_links));
	if (line[0] == '\0' || line[0] == 'L' || line[0] == '#' || line[0] == '-')
		return (0);
	while (line[i])
	{
		if (line[i] == '-')
		{
			if (a > 0)
				return (0);
			a = i; 
		}
		i++;
	}
	if (a == 0)
		return (0);
	l->a = ft_strtrim(ft_strsub(line, 0, a));
	l->b = ft_strtrim(ft_strsub(line, a + 1, i));
	printf("l->a [%s]\n", l->a);
	printf("l->b [%s]\n", l->b);
	return (1);	
}

int	parser(t_file *file)
{
	int	nb_ants;
	t_data data;

	nb_ants = 0;
	if (ft_isnumber(file->line))
		nb_ants = ft_atoi(file->line);
	else
		return (0);
	while (file)
	{
//		printf("%s\n", file->line);
		if (ft_strcmp(file->line, "##start") == 0)
			data.start = ft_atoi(file->next->line);
		else if (ft_strcmp(file->line, "##end") == 0)
			data.end = ft_atoi(file->next->line);
		else if (is_room(file->line))
			break;	
		file = file->next;
	}
//	mytree(file, data);
	return (1);
}
