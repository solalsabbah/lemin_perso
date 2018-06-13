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

int	main(void)
{
	t_file *file;
	void *tmp;
	file = NULL;
	
	add_end(&file);
	tmp = file;
	while (get_next_line(0, &file->line))
	{
		add_end(&file);
		file = file->next;
	}
	file = tmp;
	while (file)
	{
		printf("%s\n", file->line);
		file = file->next;
	}
	return (0);
}
