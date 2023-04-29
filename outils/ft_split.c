/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <yboughan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:35:12 by pschemit          #+#    #+#             */
/*   Updated: 2023/03/19 12:08:29 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	ft_count_word(char *str, int len)
{
	int	word_count;
	int	i;

	i = 0;
	word_count = 0;
	while (i < len)
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
		{
			word_count++;
			while (str[i] && (str[i] != ' ' \
				&& str[i] != '\t' && str[i] != '\n'))
				i++;
		}
	}
	return (word_count);
}

void	ft_split_bis_1(char *str, int *i, int *k, int *len)
{
	*i = 0;
	*k = 0;
	*len = ft_strlen(str);
}

void	ft_split_bis_2(char *str, int *j, int *i)
{
	*j = *i;
	while (str[*j] && (str[*j] != ' ' \
		&& str[*j] != '\t' && str[*j] != '\n'))
	*j = *j + 1;
}

void	ft_split_bis_3(char **result, int *j, int *i, int *k)
{
	result[*k][*j - *i] = '\0';
	*k = *k + 1;
	*i = *j;
}
