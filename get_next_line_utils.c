/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlachman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:23:49 by tlachman          #+#    #+#             */
/*   Updated: 2023/10/12 10:26:19 by tlachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strcpy(char *dest, char *src, int start, int end)
{
	while (start <= end)
		*dest++ = src[start++];
	*dest = 0;
}

t_list	*ft_lstnnew(t_buf *buff)
{
	t_list	*l;

	l = (t_list *) malloc(sizeof(t_list));
	if (!l)
		return (NULL);
	ft_strcpy(l->content, buff->buffer, buff->start, buff->mem);
	l->next = NULL;
	return (l);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*cursor;

	if (alst && *alst)
	{
		cursor = *alst;
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = new;
	}
	else if (alst)
		*alst = new;
}

int	ft_lstsize(t_list *lst)
{
	int		x;
	t_list	*cursor;

	x = 0;
	cursor = lst;
	while (cursor)
	{
		cursor = cursor->next;
		x++;
	}
	return (x);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*cursor;

	if (!lst || !(*lst))
		return ;
	cursor = *lst;
	while (*lst)
	{
		cursor = (*lst)->next;
		free(*lst);
		*lst = cursor;
	}
}
