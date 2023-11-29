/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:33:26 by ynassibi          #+#    #+#             */
/*   Updated: 2023/11/28 10:27:40 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include <sys/syslimits.h>

typedef struct s_list
{
	char			*arr;
	struct s_list	*next;
}				t_list;

int		foud_newline(t_list *list);
t_list	*lstlast(t_list *list);
char	*get_line_c(t_list *list, int (*f)(t_list *));
int		lenght(t_list *list);
void	flash(t_list **list, t_list *(*f)(t_list *));
char	*get_next_line(int fd);
void	join(t_list *list, char *arr);
void	cleanlst(t_list **list, t_list *newlst, char *buf, void (*d)(void *));
void	creater(t_list **list, int fd, int (*f)(t_list *));
void	lstadd(t_list **list, char *buf);

#endif
