/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:42:58 by ynassibi          #+#    #+#             */
/*   Updated: 2023/11/25 14:58:24 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	cleanlst(t_list **list, t_list *newlst, char *buf, void (*d)(void *))
{
	t_list	*current;

	while (*list)
	{
		current = (*list)->next;
		d((*list)->arr);
		d(*list);
		*list = current;
	}
	*list = NULL;
	if (newlst->arr[0])
		*list = newlst;
	else
	{
		d(buf);
		d(newlst);
	}
	return ;
}

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

int	lenght(t_list *list)
{
	int	i;
	int	lst_len;

	if (!list)
		return (0);
	lst_len = 0;
	while (list != NULL)
	{
		i = 0;
		while (list->arr[i])
		{
			if (list->arr[i] == '\n')
			{
				++lst_len;
				break ;
			}
			++i;
			++lst_len;
		}
		list = list->next;
	}
	return (lst_len);
}

void	join(t_list *list, char *arr)
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
				arr[j++] = '\n';
				break ;
			}
			arr[j++] = list->arr[i++];
		}
		list = list->next;
	}
	arr[j] = '\0';
}
