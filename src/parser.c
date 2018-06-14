#include "lemin.h"

int	parser(t_file *file)
{
	int	nb_ants;
	t_data data;
	t_node tree;

	nb_ants = 0;
	if (ft_isnumber(file->line))
		nb_ants = ft_atoi(file->line);
	else
		return (0);
	while (file)
	{
		if (ft_strcmp(file->line, "##start") == 0)
			data.start = ft_atoi(file->next->line);
		if (ft_strcmp(file->line, "##end") == 0)
			data.end = ft_atoi(file->next->line);
		file = file->next;
	}
	printf("[%d]\n", nb_ants);
	printf("[%d]\n", data.start);
	printf("[%d]\n", data.end);
	return (1);
}
