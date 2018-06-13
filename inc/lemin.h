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

typedef struct	s_param
{	
	int			nb; // count of element in stack 
	int			i;  // used for table of operands
	int			min;
	int			max;
	int			med;
	int			min_med;
	int			max_med;
	int			sens;
	void		*a1;
	void		*b1;
}				t_param;

typedef struct s_file t_file;

struct s_file
{
	char		*line;
	t_file		*next;
};

#endif
