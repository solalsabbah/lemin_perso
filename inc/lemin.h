/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 14:35:06 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/26 18:31:08 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H


# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_room t_room;

struct		s_room
{
   	char	*name;
    	int	nb;
    t_room	*next;

};

typedef struct	s_data
{	
	char		*start;
	char		*end;
	int			ants;
}				t_data;

typedef struct s_queue t_queue;

struct s_queue
{
	int	room;
	t_queue *next;
};

typedef struct	s_links
{	
	char			*a;
	char			*b;
	struct s_links	*next;
}				t_links;

typedef struct s_file t_file;

struct s_file
{
	char		*line;
	t_file		*next;

};

void	add_end(t_file **file);
void	add_links(t_links **l, char *a, char *b);
void	del_link(t_links **l, t_links *elem);

void	init(int *col, int *father, int *dist);

int		place_bro(t_links **l, t_node **tree, void *tmp);
int	 	is_link(char *line, t_links **l);
int		parser(t_file *file);
int		mytree(t_links *l, t_data *data);
int		solve(t_links **l, t_data *data);

#endif
