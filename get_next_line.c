/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlachman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:52:34 by tlachman          #+#    #+#             */
/*   Updated: 2023/10/12 09:59:29 by tlachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

void	clean_buffer(t_buf *buffer)
{
	int	i;

	i = 0;
	while (i < buffer->mem)
	{
		buffer->buffer[i] = 0;
		i++;
	}
}

void	end_line(int fd, int *end, t_buf *buff, t_list **lst)
{
	if (buff->mem < BUFFER_SIZE && buff->buffer[buff->mem] == '\n')
	{
		ft_lstadd_back(lst, ft_lstnnew(buff));
		*end = 1;
		buff->start = buff->mem + 1;
		buff->mem++;
	}
	else if (((buff->mem < BUFFER_SIZE) && !(buff->buffer[buff->mem]))
		|| (buff->mem == BUFFER_SIZE))
	{
		ft_lstadd_back(lst, ft_lstnnew(buff));
		clean_buffer(buff);
		if (!read(fd, buff->buffer, BUFFER_SIZE))
			*end = 1;
		buff->mem = 0;
		buff->start = 0;
	}
}

char	*ft_makeline(t_list *lst, int n)
{
	size_t	x;
	char	*dest;
	t_list	*cursor;
	size_t	y;
	char	*cpy;

	dest = (char *) malloc(((ft_lstsize(lst)) * BUFFER_SIZE + n + 2));
	if (!dest)
		return (NULL);
	x = 0;
	cursor = lst;
	y = 0;
	while (cursor)
	{
		y = 0;
		cpy = cursor->content;
		while (cpy[y])
			dest[x++] = cpy[y++];
		cursor = cursor->next;
	}
	dest[x] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	static t_buf	buffer = {.buffer = "", .mem = 0, .start = 0};
	char			*dest;
	int				end;
	t_list			*lst;

	end = 0;
	if (!buffer.buffer[0] && (read(fd, buffer.buffer, BUFFER_SIZE) <= 0))
		return (NULL);
	lst = NULL;
	while (!end)
	{
		while ((buffer.mem < BUFFER_SIZE)
			&& buffer.buffer[buffer.mem] && buffer.buffer[buffer.mem] != '\n')
			buffer.mem++;
		end_line(fd, &end, &buffer, &lst);
	}
	dest = ft_makeline(lst, buffer.mem);
	ft_lstclear(&lst);
	if (!dest || !(*dest))
	{
		free(dest);
		return (NULL);
	}
	return (dest);
}
