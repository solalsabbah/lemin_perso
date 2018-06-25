/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:42:21 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/25 17:21:56 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	create_tree(t_links **l, t_node **tree)
{
	void 	*tmp;
	t_links	*tmp_l;
	tmp_l = *l;

	///// Find a child ////
	while (*l && (*tree)->child == NULL)
	{
		if (ft_strcmp((*l)->a, (*tree)->room) == 0)
		{
			(*tree)->child = malloc(sizeof(t_node));
			tmp = (*tree)->child;
			(*tree)->child->room = (*l)->b;
			del_link(&tmp_l, *l);
			(*tree)->child->child = NULL;
			create_tree(&tmp_l, &(**tree).child);
		}
		else if (ft_strcmp((*l)->b, (*tree)->room) == 0)
		{
			(*tree)->child = malloc(sizeof(t_node));
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
	if ((*tree)->child != NULL)
	{
		printf("room %s\n", (*tree)->room);
		while (*l)
		{	
			if (ft_strcmp((*l)->a, (*tree)->room) == 0 && (*tree)->child && (*tree)->child->room != NULL)
			{
				printf("Im in\n");
				(*tree)->child->bro = malloc(sizeof(t_node));
				(*tree)->child->bro->room = (*l)->b;
				printf("create room %s\n", (*tree)->child->bro->room);
				del_link(&tmp_l, *l);
				//			printf("ici [%s]\n", (*tree)->child->bro->room);
				create_tree(&tmp_l, &(**tree).child->bro);
			//	(*tree)->child = (*tree)->child->bro;
			}
			else if (ft_strcmp((*l)->b, (*tree)->room) == 0 && (*tree)->child && (*tree)->child->room != NULL)
			{
				printf("Im here\n");
				(*tree)->child->bro = malloc(sizeof(t_node));
				(*tree)->child->bro->room = (*l)->a;
				printf("bro room %s\n", (*tree)->child->bro->room);
				del_link(&tmp_l, *l);
				create_tree(&tmp_l, &(**tree).child->bro);
			//	(*tree)->child = (*tree)->child->bro;
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

	tree = malloc(sizeof(t_node));
	tree->room = data->start;

	create_tree(&l, &tree);
	while (l)
	{
		printf("[%s]-[%s]\n", l->a, l->b);
		l = l->next;
	}

	printf("======= TREE =======\n\n");

	printf("parent [%s]\n", tree->room);
	printf("child [%s]\n", tree->child->bro->child->room);
	printf("child [%s]\n", tree->child->child->room);
	printf("child [%s]\n", tree->child->child->child->room);
	printf("child [%s]\n", tree->child->child->child->child->room);
	printf("child [%s]\n", tree->child->child->child->child->child->room);

	//	printf("parent [%s]\n", tree->child->bro->room);

	//	printf("child [%s]\n", tree->child->bro->child->bro->room);
	/*	printf("child [%s]\n\n", tree->child->bro->bro->room);
		printf("child child  [%s]\n", tree->child->child->room);
		printf("child child  [%s]\n", tree->child->child->bro->room);
		*/	printf("=================\n\n\n");

	printf("======= LIST OF ROOMS  =======\n\n");
	return (0);
}
