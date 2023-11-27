/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:07:33 by ynassibi          #+#    #+#             */
/*   Updated: 2023/11/27 17:43:34 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	lenght(const char *s)
{
	size_t	i;
	size_t	c;

	c = -1;
	i = 0;
	while (s[i++])
		c++;
	return (++c);
}

char	*get_next_line(int fd)
{
	static char	*arr;
	char		buffer[BUFFER_SIZE + 1];
	char		*star;
	int			i;

	if (!arr)
		arr = ft_strdup("");
	i = read(fd, buffer, BUFFER_SIZE);
	while (i >= 0)
	{
		buffer[i] = 0;
		arr = ft_strjoin(arr, buffer);
		if (is_newline(arr) != -1)
			return (helper(&star, &arr, is_newline));
		if (!i && !arr[0])
			break ;
		if (!i)
			return (get_cash(&arr, 0));
		i = read(fd, buffer, BUFFER_SIZE);
	}
	free(arr);
	arr = 0x0;
	return (0x0);
}

char	*helper(char **current, char **arr, int (*f)(char *))
{
	*current = ft_substr(*arr, 0, f(*arr) + 1);
	*arr = get_cash(arr, f(*arr) + 1);
	return (*current);
}

char	*get_cash(char **str, int len)
{
	char	*cash;

	cash = ft_substr(*str, len, lenght(*str + len));
	return (free(*str),*str = 0x0, cash);
}

int	is_newline(char *str)
{
	int	i;
	int	valid;

	valid = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (-valid);
		i++;
	}
	return (valid);
}
