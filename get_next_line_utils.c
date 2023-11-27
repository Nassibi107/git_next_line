/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:42:58 by ynassibi          #+#    #+#             */
/*   Updated: 2023/11/27 17:08:01 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;
	const char	*tracker;

	if (!s)
		return (NULL);
	if (start > lenght(s))
	{
		str = ft_strdup("");
		if (!str)
			return (0);
		return (str);
	}
	if (len > (lenght(s) - start))
		len = (lenght(s) - start);
	tracker = &s[start];
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = -1;
	while (tracker[++i] && i < len)
		str[i] = tracker[i];
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
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
	len_s1 = lenght(s1);
	len_s2 = lenght(s2);
	str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!str)
		return (0);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	i = 0;
	while (s2[i])
		str[len_s1++] = s2[i++];
	free((char *)s1);
	str[len_s1] = '\0';
	return (s1 = 0x0, str);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	s1_len;
	int		i;

	i = 0;
	s1_len = lenght(s1);
	copy = malloc(sizeof(char) * (s1_len + 1));
	if (!copy)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
