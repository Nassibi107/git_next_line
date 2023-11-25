/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:42:58 by ynassibi          #+#    #+#             */
/*   Updated: 2023/11/25 11:22:09 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	foud_newline(t_list *list)
{
	int	i;
	int valid = 1;

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

t_list	*find_last_node(t_list *list)
{
	if (NULL == list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

/*
 * Copy (string\n]
*/
void	copy_str(t_list *list, char *str)
{
	int	i;
	int	k;

	if (NULL == list)
		return ;
	k = 0;
	while (list)
	{
		i = 0;
		while (list->arr[i])
		{
			if (list->arr[i] == '\n')
			{
				str[k++] = '\n';
				str[k] = '\0';
				return ;
			}
			str[k++] = list->arr[i++];
		}
		list = list->next;
	}
	str[k] = '\0';
}

/*
 * find the len to new line in
 * my linked list
*/
int	len_to_newline(t_list *list)
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
void	dealloc(t_list **list, t_list *clean_node, char *buf)
{
	t_list	*tmp;

	if (NULL == *list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->arr);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node->arr[0])
		*list = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}
