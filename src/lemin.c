#include "lemin.h"

void	parser(t_file *file)
{
	int	nb_ants;

	while (file)
	{
		if (ft_strcmp(file->line, "##start") == 0)
			nb_ants = ft_atoi(file->next->line);	
		file = file->next;
	}
	printf("[%d]\n", nb_ants);
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
	parser(file);
	return (0);
}
