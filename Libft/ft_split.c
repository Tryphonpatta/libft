/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptantiam <ptantiam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:36:27 by ptantiam          #+#    #+#             */
/*   Updated: 2023/06/28 20:04:27 by ptantiam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	checksep(char c, char sep)
{
	return (c == sep);
}

int	count_string(char *c, char sep)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (c[index])
	{
		while (c[index] && checksep(c[index], sep))
			index ++;
		if (c[index] != '\0')
			count ++;
		while (c[index] && !checksep(c[index], sep))
			index ++;
	}
	return (count);
}

int	str_len_word(char *c, char sep)
{
	int	i;

	i = 0;
	while (*c)
	{
		if (!checksep(*c, sep))
			i ++;
		else
			break ;
		c ++;
	}
	return (i);
}

char	*str_cpy(char *c, char sep)
{
	char	*a;
	char	*b;

	a = (char *)malloc(str_len_word(c, sep) + 1);
	b = a;
	while (*c && !checksep(*c, sep))
	{
		*a = *c;
		a ++;
		c ++;
	}
	*a = '\0';
	return (b);
}

char	**ft_split(char *str, char charset)
{
	char		**c;
	char		**d;
	int			count;
	int			i;
	int			index;

	index = 0;
	count = count_string(str, charset);
	c = (char **)malloc(sizeof(char *) * (count + 1));
	if (!c)
		return (0);
	d = c;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] && checksep(str[i], charset))
			i ++;
		if (str[i] != '\0')
			c[index++] = str_cpy(str + i, charset);
		while (str[i] && !checksep(str[i], charset))
			i ++;
	}
	c[index] = 0;
	return (d);
}
