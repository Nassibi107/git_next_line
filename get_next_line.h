/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:43:33 by ynassibi          #+#    #+#             */
/*   Updated: 2023/11/27 17:27:05 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*helper(char **current, char **arr, int (*f)(char *));
char	*get_next_line(int fd);
int		is_newline(char *buff);
char	*ft_strdup(const char *s1);
size_t	lenght(const char *s);
char	*get_cash(char **str, int len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
#endif
