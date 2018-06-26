/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:42:21 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/26 18:33:08 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	print_file(t_links **l)
{
	t_links *tmp_l;

	tmp_l = *l;
	printf("=============\nPRINTFILE\n");
	while (*l)
	{
		printf("[%s]-[%s]\n", (*l)->a, (*l)->b);
		*l = (*l)->next;
	}
	printf("=============\n");
	*l = tmp_l;
	return (0);
}

int	create_tree(t_links **l, t_node **tree)
{
	void 	*tmp;
	t_links	*tmp_l;
	tmp_l = *l;

	
	//printf("tree room %s\n", (*tree)->room);
	///// Find a child ////
	while (*l && (*tree)->child == NULL)
	{
		if (ft_strcmp((*l)->a, (*tree)->room) == 0)
		{
			(*tree)->child = malloc(sizeof(t_node));
			(*tree)->child->room = NULL;
			tmp = (*tree)->child;
			(*tree)->child->room = (*l)->b;
			del_link(&tmp_l, *l);
			(*tree)->child->child = NULL;
			create_tree(&tmp_l, &(**tree).child);
		}
		else if (ft_strcmp((*l)->b, (*tree)->room) == 0)
		{
			(*tree)->child = malloc(sizeof(t_node));
			(*tree)->child->room = NULL;
			tmp = (*tree)->child;
			(*tree)->child->room = (*l)->a;
			del_link(&tmp_l, *l);
			(*tree)->child->child = NULL;
			create_tree(&tmp_l, &(**tree).child);
		}
		(*l) = (*l)->next;
	}
	*l = tmp_l;
	
	//// Find the brothers ///
	if ((*tree)->child != NULL && (*tree)->child->room != NULL)
	{
		while (*l)
		{
			if (ft_strcmp((*l)->a, (*tree)->room) == 0 && (*tree)->child && (*tree)->child->room != NULL)
			{
				(*tree)->child->bro = malloc(sizeof(t_node));
				(*tree)->child->bro->child = NULL;
				(*tree)->child->bro->bro = NULL;
				(*tree)->child->bro->room = (*l)->b;
				del_link(&tmp_l, *l);
				create_tree(&tmp_l, &(**tree).child->bro);
			}
			else if (ft_strcmp((*l)->b, (*tree)->room) == 0 && (*tree)->child && (*tree)->child->room != NULL)
			{
				(*tree)->child->bro = malloc(sizeof(t_node));
				(*tree)->child->bro->child = NULL;
				(*tree)->child->bro->bro = NULL;
				(*tree)->child->bro->room = (*l)->a;
				del_link(&tmp_l, *l);
				create_tree(&tmp_l, &(**tree).child->bro);
			}
			(*l) = (*l)->next;
		}
	}
	(*tree)->child = tmp;
	*l = tmp_l;
	return (0);
}

int	mytree(t_links *l, t_data *data)
{
	t_node *tree;
	void *tmp;
	tree = malloc(sizeof(t_node));
	tree->room = data->start;

	tmp = &l;
	create_tree(&l, &tree);
	printf("======= FILE =======\n\n");
	
	while (l)
	{
		printf("[%s]-[%s]\n", l->a, l->b);
		l = l->next;
	}

	printf("======= TREE =======\n\n");

	printf("parent [%s]\n", tree->room);
	printf("tree child bro [%s]\n", tree->child->room);
	printf("tree child bro [%s]\n", tree->child->bro->room);
	//printf("tree child bro [%s]\n", tree->child->bro->bro->room);
	printf("child [%s]\n", tree->child->child->room);
	printf("child [%s]\n", tree->child->child->bro->room);
	printf("child [%s]\n", tree->child->child->bro->child->room);

	printf("child [%s]\n", tree->child->bro->child->room);
	printf("child [%s]\n", tree->child->child->child->room);
	printf("child [%s]\n", tree->child->child->child->child->room);
	printf("child [%s]\n", tree->child->child->child->child->child->room);

		printf("child [%s]\n", tree->child->bro->child->room);
	/*	printf("child [%s]\n\n", tree->child->bro->bro->room);
		printf("child child  [%s]\n", tree->child->child->room);
		printf("child child  [%s]\n", tree->child->child->bro->room);
		*/	printf("=================\n\n\n");

	return (0);
}
