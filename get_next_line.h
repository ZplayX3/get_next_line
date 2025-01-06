/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlachma <trlachma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:59:53 by tlachman          #+#    #+#             */
/*   Updated: 2025/01/06 11:22:40 by trlachma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_buf
{
	char	buffer[BUFFER_SIZE + 1];
	int		mem;
	int		start;
}	t_buf;

typedef struct s_list
{
	char			content[BUFFER_SIZE + 1];
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnnew(t_buf *buff);
void	ft_lstadd_back(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst);
void	clean_buffer(t_buf *buffer);
void	end_line(int fd, int *end, t_buf *buff, t_list **lst);
char	*ft_makeline(t_list *lst, int n);
char	*get_next_line(int fd);

#endif
