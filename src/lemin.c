#include "lemin.h"

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
