/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:07:33 by ynassibi          #+#    #+#             */
/*   Updated: 2023/11/21 18:31:26 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>


void	ft_fash(g_list)
{
	g_list	*born_tobe_node;
	char		*buffer;
	int		o;
	int		t;

	buf = malloc(BUFFER_SIZE + 1);
	born_tobe_node =malloc(sizeof(g_list));
	if (!buf || !born_tobe_node)
		return ;
	o = 0;
	t = 0;
	while (get_lstnode()->buf_node[o] && get_lstnode()->buf_node[o] !='\n')
		o++;
	while (get_lstnode()->buf_node[o] && get_lstnode()->buf_node[++o] )
		buffer[t++] = get_lstnode()->buf_node[o];
	buffer[t] = '\0';
	born_tobe_node->next = NULL;
	born_tobe_node->buf_node = buffer;
}
void	ft_lstadd(g_list	**list,char *bufer)
{
	g_list	*n_node;
	g_list	*l_node;

	l_node = get_lstnode(*list);
	if (!l_node)
		return ;
	n_node = malloc(sizeof(g_list));
	if (!n_node)
		return ;
	else
		l_node->next =n_node;
	n_node->buf_node = bufer;
	n_node->next = NULL;

}

void	creater(g_list **list,int fd)
{
	int		traker;
	char	*bufer;

	while (!get_line(*list))
	{
		bufer = malloc(BUFFER_SIZE + 1);
		if (!bufer)
			return ;
		traker = read(fd, bufer, BUFFER_SIZE);
		if (!traker)
		{
			free(traker);
			return ;
		}
		buf[char_read] = '\0';
		ft_lstadd(list, bufer);
	}

}
char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	creater(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = get_line(list);
	ft_flash(&list);
	return (next_line);
}
