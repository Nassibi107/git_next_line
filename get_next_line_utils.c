/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:42:58 by ynassibi          #+#    #+#             */
/*   Updated: 2023/11/17 12:07:38 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;
	size_t	cp;

	i = -1;
	cp = 0;
	while (str[++i])
		cp += 1;
	return(cp);
}
void	*go_to_heap(size_t count, size_t n)
{
	size_t	lenght;
	size_t	i;
	void		*str;

	lenght = (count * n);
	if (n != 0 && count != lenght / n)
		return (NULL);
	str = malloc(lenght);
	if (!str)
		return (0);
	i  = 0;
	while (i < lenght)
	{
		((char *)str)[i] = 0;
		i++;
	}
	return(str);
}
char  *ft_dup(const char *src)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = malloc ((sizeof(char) * (ft_strlen(src) + 1)));
	if (!tmp)
		return (NULL);
	while (src[i])
	{
		tmp[i] = src[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *) &s[i]);
		i++;
	}
	if (!(char)c)
		return ((char *) &s[i]);
	return (0);
}

char	*jion(char *s1, char *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	if (s1 && !s2)
		return ((char *)s1);
	else if (!s1 && s2)
		return ((char *)s2);
	else if (!s1 && !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!str)
		return (0);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	i = 0;
	while (s2[i])
		str[len_s1++] = s2[i++];
	str[len_s1] = '\0';
	return (str);
}
