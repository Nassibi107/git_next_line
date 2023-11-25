/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:42:58 by ynassibi          #+#    #+#             */
/*   Updated: 2023/11/25 13:08:14 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	foud_newline(t_list *list)
{
	int	i;
	int	valid;

	valid = 1;
	if (!list)
		return (valid);
	while (list)
	{
		i = 0;
		while (list->arr[i] && i < BUFFER_SIZE)
		{
			if (list->arr[i] == '\n')
			{
				return (-valid);
			}
			i++;
		}
		list = list->next;
	}
	return (valid);
}

t_list	*lstlast(t_list *list)
{
	if (list)
	{
		while (list->next)
			list = list->next;
		return (list);
	}
	return (NULL);
}

/*
 * Copy (string\n]
*/
void	join(t_list *list, char *str)
{
	int	i;
	int	j;

	if (!list)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->arr[i])
		{
			if (list->arr[i] == '\n')
			{
				str[j++] = '\n';
				break ;
			}
			str[j++] = list->arr[i++];
		}
		list = list->next;
	}
	str[j] = '\0';
}

/*
 * find the len to new line in
 * my linked list
*/
int	lenght(t_list *list)
{
	int	i;
	int	len;

	if (NULL == list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->arr[i])
		{
			if (list->arr[i] == '\n')
			{
				++len;
				return (len);
			}
			++i;
			++len;
		}
		list = list->next;
	}
	return (len);
}

/*
 * dealloc all from head
 * set heat->NULL
*/
void	cleanlst(t_list **list, t_list *newlst, char *buf, void (*d)(void *))
{
	t_list	*tmp;

	if (NULL == *list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		d((*list)->arr);
		d(*list);
		*list = tmp;
	}
	*list = NULL;
	if (newlst->arr[0])
		*list = newlst;
	else
	{
		d(buf);
		d(newlst);
	}
}
