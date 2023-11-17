/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:42:58 by ynassibi          #+#    #+#             */
/*   Updated: 2023/11/17 09:45:21 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(char const *str)
{
	size_t	i;
	size_t	cp;

	i = -1;
	cp = 0;
	while (str[++i])
		cp += 1;
	return(cp);
}
