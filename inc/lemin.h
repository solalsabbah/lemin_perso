/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 14:35:06 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/28 17:10:55 by ssabbah          ###   ########.fr       */
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
	int		start_id;
	char		*end;
	int		end_id;
	int		rooms;
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
}					t_links;

typedef struct	s_cnx
{	
	int				a;
	int				b;
	struct s_cnx	*next;
}					t_cnx;

typedef struct	s_tabs
{	
	int				*col;
	int				*dist;
	int				*father;
}					t_tabs;


typedef struct s_file t_file;

struct s_file
{
	char		*line;
	t_file		*next;

};

void	add_end(t_file **file);
void	add_links(t_links **l, char *a, char *b);
void	del_cnx(t_cnx **cnx, t_cnx *elem);


void	add_cnx(t_links **l, t_room **room, t_data *data);
void	init_tabs(int *col, int *father, int *dist, t_data *data);

int		add_to_room(char *name, t_room **room);
int		assign_nb(t_links **l, t_data *data);
int	 	is_link(char *line, t_links **l);
int		parser(t_file *file);
int		mytree(t_links *l, t_data *data);
int		solve(t_cnx **cnx, t_data *data);

#endif
