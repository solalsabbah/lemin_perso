/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:32:21 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/14 17:32:36 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	 	is_link(char *line, t_links **l)
{
	int i;
	int	a;

	i = 0;
	a = 0;
	if (line[0] == '\0' || line[0] == 'L' || line[0] == '#' || line[0] == '-')
		return (0);
	while (line[i])
	{
		if (line[i] == '-')
		{
			if (a > 0)
				return (0);
			a = i;
		}
		i++;
	}
	if (a == 0)
		return (0);
	add_links(l, ft_strtrim(ft_strsub(line, 0, a)), ft_strtrim(ft_strsub(line, a + 1, i)));
	return (1);
}
