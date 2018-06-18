#include "lemin.h"

int	create_tree(t_links **l, t_node **tree)
{
	void 	*tmp;
	t_links	*tmp_l;
	tmp_l = *l;

	printf("tree room\n");
	printf("tree ===%p===\n", tree);
	printf("tree ===[%s]===\n\n", (*tree)->room); // pas de tree->room 

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
				create_tree(&tmp_l, &(**tree).child);
			}
			if (ft_strcmp((*l)->b, (*tree)->room) == 0)
			{
				(*tree)->child = malloc(sizeof(t_node));
				tmp = (*tree)->child;
				(*tree)->child->room = (*l)->a;
				del_link(&tmp_l, *l);
				create_tree(&tmp_l, &(**tree).child);
			}
		}
		(*l) = (*l)->next;
	}
	printf("tree ===[%s]===\n", (*tree)->room); // pas de tree->room 
	printf("child [%s]\n\n", (*tree)->child->room);
	printf("WTF happens exit \n");
	*l = tmp_l;

	//// Find the brothers ///
	//printf("tree ===%s===\n", (*tree)->room);
	if ((*tree)->child != NULL)
	{
	printf("WTF happens still  print \n");
		while (*l)
		{	
//			printf("WTF happens still  print \n");
//		printf("child [%s]\n", (*tree)->child->room);
			if (ft_strcmp((*l)->a, (*tree)->room) == 0 && (*tree)->child->room != NULL)
			{
				(*tree)->child->bro = malloc(sizeof(t_node));
				(*tree)->child->bro->room = (*l)->b;
				printf("tree bro room ===%s===\n", (*tree)->child->bro->room); // pas de tree->room 
				del_link(&tmp_l, *l);
				create_tree(&tmp_l, &(**tree).child->bro);
				(*tree)->child = (*tree)->child->bro;
			}
			else if (ft_strcmp((*l)->b, (*tree)->room) == 0 && (*tree)->child->room != NULL)
			{
				(*tree)->child->bro = malloc(sizeof(t_node));
				(*tree)->child->bro->room = (*l)->a;
				del_link(&tmp_l, *l);
				create_tree(&tmp_l, &(**tree).child->bro);
				(*tree)->child = (*tree)->child->bro;
			}
			(*l) = (*l)->next;
		}
	}
	printf("Ca segfault\n");
	(*tree)->child = tmp;
	*l = tmp_l;
	return (0);
}

int	mytree(t_links *l, t_data *data)
{
	t_node *tree;

	tree = malloc(sizeof(t_node));
	tree->room = data->start;

	//	printf("Pointeur A  %p\n\n", tree);
	//	printf("Pointeur B  %p\n\n", &tree);
	create_tree(&l, &tree);

	printf("======= TREE =======\n\n");
	printf("%p\n", tree);
	printf("tmp : %p\n\n", tree->child);
	printf("parent [%s]\n", tree->room);
	printf("child [%s]\n", tree->child->room);
	printf("child [%s]\n", tree->child->bro->room);
	printf("child [%s]\n", tree->child->bro->bro->room);
	printf("child [%s]\n\n", tree->child->bro->bro->bro->room);
	printf("child child  [%s]\n", tree->child->child->room);
	printf("child child  [%s]\n", tree->child->child->bro->room);
	printf("=================\n\n\n");

	printf("======= LIST OF ROOMS  =======\n\n");
	while (l)
	{
		printf("[%s]-[%s]\n", l->a, l->b);
		l = l->next;
	}
	return (0);
}
