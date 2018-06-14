/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 14:34:52 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/14 14:34:53 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
