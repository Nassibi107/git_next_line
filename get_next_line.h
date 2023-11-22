/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:43:33 by ynassibi          #+#    #+#             */
/*   Updated: 2023/11/22 10:16:12 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <unistd.h>

typedef struct node {
	char	*buf_node;
	node	*next;
}	t_list;

int		get_line(t_list *list);
void	join(t_list *list, char *str);
t_list	*get_lstnode(t_list *list);
int		lenght(t_list *list);
void	clear(t_list **list, t_list *c_node, char *buf);
#endif
