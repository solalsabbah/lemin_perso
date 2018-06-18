#include "lemin.h"

int	create_tree(t_links **l, t_node **tree)
{
	void 	*tmp;
	t_links	*tmp_l;

	tmp_l = *l;
	
	printf("Pointeur C  %p\n", tree);
	printf("Pointeur C  %p\n", (*tree)->child);
	printf("Pointeur D  %p\n", tmp_l);
	///// Find a child ////
	while (*l && (*tree)->child == NULL)
	{
		if ((*tree)->child == NULL)
		{
			if (ft_strcmp((*l)->a, (*tree)->room) == 0)
			{
				(*tree)->child = malloc(sizeof(t_node));
				tmp = (*tree)->child;
				(*tree)->child->room = (*l)->b;
				del_link(&tmp_l, *l);
				printf("Pointeur F  %p\n", &tree);
		//		*tree = (*tree)->child;
		//		create_tree(&tmp_l, tree);
			}
			if (ft_strcmp((*l)->b, (*tree)->room) == 0)
			{
				(*tree)->child = malloc(sizeof(t_node));
				tmp = (*tree)->child;
				(*tree)->child->room = (*l)->a;
				del_link(&tmp_l, *l);
			}
		}
		(*l) = (*l)->next;
	}
	*l = tmp_l;

	//// Find the brothers ///
	while (*l)
	{	
		if (ft_strcmp((*l)->a, (*tree)->room) == 0 && (*tree)->child->room != NULL)
		{
			(*tree)->child->bro = malloc(sizeof(t_node));
			(*tree)->child->bro->room = (*l)->b;
			(*tree)->child = (*tree)->child->bro;
			del_link(&tmp_l, *l);
			printf("tmp 1 %s\n", (*tree)->child->room);
			//tree = (&tree)->child;
			//create_tree(&tmp_l, tree);
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

//			printf("%s\n", (*l)->b);
//			printf("tmp %p %s\n", tmp_l, tmp_l->next->b);
//			printf("tmp %p %s\n", tmp_l, tmp_l->b);
//			printf("bef [%s]\n\n", (*tree)->child->room);

int	mytree(t_links *l, t_data *data)
{
	t_node *tree;

	tree = malloc(sizeof(t_node));
	tree->room = data->start;

	printf("Pointeur A  %p\n\n", tree);
	printf("Pointeur B  %p\n\n", &tree);
	create_tree(&l, &tree);

	printf("======= TREE =======\n\n");
	printf("%p\n", tree);
	printf("tmp : %p\n\n", tree->child);
	printf("parent [%s]\n", tree->room);
	printf("child [%s]\n", tree->child->room);
	printf("child [%s]\n", tree->child->bro->room);
	printf("child [%s]\n", tree->child->bro->bro->room);
	printf("child [%s]\n\n", tree->child->bro->bro->bro->room);
	printf("=================\n\n\n");

	printf("======= LIST OF ROOMS  =======\n\n");
	while (l)
	{
		printf("[%s]-[%s]\n", l->a, l->b);
		l = l->next;
	}
	return (0);
}