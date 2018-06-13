/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 17:26:26 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/12 12:19:05 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

static unsigned int	ft_strclen(char *save)
{
	unsigned int	i;

	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	return (i);
}

static char			*ft_strrejoin(char *s1, char *s2, size_t len)
{
	char		*str;
	int			nb;
	char		*tmp;

	nb = ft_strlen(s1) + ++len;
	str = ft_strnew(nb);
	tmp = str;
	while (*s1)
		*str++ = *s1++;	
	while (*s2 && --len > 0)
		*str++ = *s2++;
	*str = '\0';
	return (str - (str - tmp));
}

static char			*ft_chrandcpy(char *save)
{
	if (ft_strchr(save, '\n'))
	{
		ft_strcpy(save, ft_strchr(save, '\n') + 1);
		return (save);
	}
	if (ft_strclen(save) > 0)
	{
		ft_strcpy(save, ft_strchr(save, '\0'));
		return (save);
	}
	return (NULL);
}

int					get_next_line(int const fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*save[256];
	int			res;
	char		*ptr;
	
	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!(save[fd]) && (save[fd] = ft_strnew(0)) == NULL)
		return (-1);
	while (!(ft_strchr(save[fd], '\n')) &&
			(res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		ptr = save[fd];
		save[fd] = ft_strrejoin(ptr, buff, res);
		free(ptr);
	}
	*line = ft_strsub(save[fd], 0, ft_strclen(save[fd]));
	if (ft_chrandcpy(save[fd]) == NULL)
		return (0);
	return (1);
}
