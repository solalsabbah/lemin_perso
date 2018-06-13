#include "lemin.h"

void	add_end(t_file **file)
{
	t_file *tmp;

	tmp = *file;
	if (*file == NULL)
	{
		(*file) = malloc(sizeof(t_file));
		(*file)->line = NULL;
		(*file)->next = NULL;
		tmp = *file;
	}
	else
	{
		while ((*file)->next != NULL)
			*file = (*file)->next;
		(*file)->next = malloc(sizeof(t_file));
		(*file)->next->line = NULL;
		(*file)->next->next = NULL;
	}
	*file = tmp;
}
