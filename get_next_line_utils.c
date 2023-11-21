/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:42:58 by ynassibi          #+#    #+#             */
/*   Updated: 2023/11/21 09:23:36 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdlib.h>

int	get_line(g_list *list)
{
	int	ok;

	if (!list)
		return (0);
	while (list)
	{
		ok = 0;
		while (list->buf_node[ok] && ok < BUFFER_SIZE)
		{
			if (list->buf_node[ok] == '\n')
				return (1);
			ok++;
		}
		list = list->next;
	}
	return (0);
}

void	join(g_list *list, char *str)
{
	int	i;
	int	j;

	if (!list)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->buf_node[i] != '\0')
		{
			if (list->buf_node[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = list->buf_node[i++];
		}
		list = list->next;
	}
	str[j] = '\0';
}

g_list	*get_lstnode(g_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int	lenght(g_list *list)
{
	int	i;
	int	j;

	if (list)
		return (0);
	j = 0;
	while (list)
	{
		i = 0;
		while (list->buf_node[i])
		{
			if (list->buf_node[i] == '\n')
			{
				j++;
				return (i);
			}
			j++;
			i++;
		}
		list = list->next;
	}
	return (j);
}

void	clear(g_list **list, g_list *c_node, char *buf)
{
	g_list	*node;

	while (*list)
	{
		node = (*list)->next;
		free(*list->buf_node);
		free(*list);
		*list = node;
	}
	*list = NULL;
	if (c_node->buf_node[0])
		*list = c_node;
	else
	{
		free(buf);
		free(c_node);
	}
}
