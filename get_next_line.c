/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:07:33 by ynassibi          #+#    #+#             */
/*   Updated: 2023/11/17 12:11:54 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	lenght(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			return (i);
		}
		i++;
	}
	return (i);
}
static char	*at_line(char *str)
{
	char	*line;
	int	len_line;
	int	i;
	if (!str)
		return (NULL);
	len_line = lenght(str);
	line = malloc(sizeof(char) * (len_line));
	if (!line)
		return (NULL);
	i = -1;
	while (++i < len_line)
		line[i] = str[i];
	line[--i] = 0;
	return (line);
}
// static char *next(char *str)
// {
// 	char	*next;
// 	int	i;
// 	int	n;

// 	i = 0;
// 	n = 0;
// 	if (str[i] && str[i + 1] != '\n')
// 		return (free(str), NULL);
// 	while (str[i] && str[i + 1] != '\n')
// 		i++;
// 	if (str[i])
// 		i++;
// 	next = malloc(sizeof(char) * ft_strlen(str + i) + 1);
// 	if (!next)
// 	return(free(str), NULL);
// 	n = 0;
// 	while (str[i])
// 		next[n++] = str[i++];
// 	next[n] = '\0';
// 	free(str);
// 	return (next);
// }

int main ()
{
 static char *str = "yassine\nnassibi";
	printf("\n>> %s",at_line(str));
	// printf("\n>> %s",next(str));
}
