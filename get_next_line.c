/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:07:33 by ynassibi          #+#    #+#             */
/*   Updated: 2023/11/17 11:45:45 by ynassibi         ###   ########.fr       */
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


int main ()
{
	char *str = "yassine\nnassibi";
	printf("\n>> %s",at_line(str));
}
