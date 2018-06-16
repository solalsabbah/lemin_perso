#include "lemin.h"

int	create_tree(t_links **l, t_node **tree)
{
	void 	*tmp;
	t_links	*tmp_l;

	tmp_l = *l;
	while (*l)
	{
		if (ft_strcmp((*l)->a, (*tree)->room) == 0 && (*tree)->child == NULL)
		{
			(*tree)->child = malloc(sizeof(t_node));
			tmp = (*tree)->child;
			(*tree)->child->room = (*l)->b;
			del_link(&tmp_l, *l);
		}
		else if (ft_strcmp((*l)->a, (*tree)->room) == 0 && (*tree)->child->room != NULL)
		{
			(*tree)->child->bro = malloc(sizeof(t_node));
			(*tree)->child->bro->room = (*l)->b;
			(*tree)->child = (*tree)->child->bro;
			del_link(&tmp_l, *l);
		}
		if (ft_strcmp((*l)->b, (*tree)->room) == 0 && (*tree)->child == NULL)
		{
			(*tree)->child = malloc(sizeof(t_node));
			tmp = (*tree)->child;
			(*tree)->child->room = (*l)->a;
			del_link(&tmp_l, *l);
		}
		else if (ft_strcmp((*l)->b, (*tree)->room) == 0 && (*tree)->child->room != NULL)
		{
			(*tree)->child->bro = malloc(sizeof(t_node));
			(*tree)->child->bro->room = (*l)->a;
			(*tree)->child = (*tree)->child->bro;
			del_link(&tmp_l, *l);
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

	printf("======= TREE =======\n\n");
	printf("%p\n", tree);
	printf("tmp : %p\n", tree->child);
	printf("[%s]\n", tree->room);
	printf("[%s]\n", tree->child->room);
	printf("[%s]\n", tree->child->bro->room);
	printf("[%s]\n", tree->child->bro->bro->room);
	printf("[%s]\n\n", tree->child->bro->bro->bro->room);
	printf("=================\n\n\n");

	printf("======= LIST OF ROOMS  =======\n\n");
	while (l)
	{
		printf("[%s]-[%s]\n", l->a, l->b);
		l = l->next;
	}
	return (0);
}
