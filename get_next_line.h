/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:43:33 by ynassibi          #+#    #+#             */
/*   Updated: 2023/11/25 12:56:08 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*arr;
	struct s_list	*next;
}				t_list;

int		foud_newline(t_list *list);
t_list	*lstlast(t_list *list);
char	*get_line(t_list *list, int (*f)(t_list *));
void	copy_str(t_list *list, char *str);
int		lenght(t_list *list);
void	flash(t_list **list, t_list *(*f)(t_list *));
char	*get_next_line(int fd);
void	cleanlst(t_list **list, t_list *newlst, char *buf, void (*d)(void *));
void	creater(t_list **list, int fd, int (*f)(t_list *));
void	lstadd(t_list **list, char *buf);
#endif
