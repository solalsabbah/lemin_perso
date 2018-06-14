/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:53:30 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/12 13:23:36 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H


# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9 
# define RRB 10
# define RRR 11

typedef struct s_node
{
    unsigned int key;
    struct s_node *left;
    struct s_node *right;
} t_node ;

typedef struct	s_data
{	
	int			start;
	int			end;
}				t_data;

typedef struct s_file t_file;

struct s_file
{
	char		*line;
	t_file		*next;
};

void	add_end(t_file **file);
int	parser(t_file *file);

#endif
