/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:07:33 by ynassibi          #+#    #+#             */
/*   Updated: 2023/11/25 13:08:29 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

void	lstadd(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = lstlast(*list);
	new_node = malloc(sizeof(t_list));
	if (NULL == new_node)
		return ;
	if (NULL == last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->arr = buf;
	new_node->next = NULL;
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	creater(&list, fd, foud_newline);
	if (list == NULL)
		return (NULL);
	next_line = get_line(list, lenght);
	flash(&list, lstlast);
	return (next_line);
}

void	flash(t_list **list, t_list *(*f)(t_list *))
{
	int		i;
	int		t;
	char	*traker;
	t_list	*new_node;

	traker = malloc(BUFFER_SIZE + 1);
	new_node = malloc(sizeof(t_list));
	if (! traker ||!new_node)
		return ;
	i = 0;
	t = 0;
	while (f(*list)->arr[i])
	{
		if (f(*list)->arr[i] == '\n')
			break ;
		i++;
	}
	while (f(*list)->arr[i])
		traker[t++] = f(*list)->arr[++i];
	traker[t] = 0;
	new_node->arr = traker;
	new_node->next = NULL;
	cleanlst(list, new_node, traker, free);
}

void	creater(t_list **list, int fd, int (*f)(t_list *))
{
	int		read_pos;
	char	*buf;
	int		size_b;

	size_b = (BUFFER_SIZE + 1);
	while (f(*list) == 1)
	{
		buf = malloc(size_b);
		if (!buf)
			return ;
		read_pos = read(fd, buf, BUFFER_SIZE);
		if (!read_pos)
		{
			free(buf);
			return ;
		}
		buf[read_pos] = ((read_pos / read_pos) - 1);
		lstadd(list, buf);
	}
}

char	*get_line(t_list *list, int (*f)(t_list *))
{
	char	*next_str;

	if (!list)
		return (NULL);
	next_str = malloc(f(list) + 1);
	if (!next_str)
		return (0x0);
	join(list, next_str);
	return (next_str);
}
