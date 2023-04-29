/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <yboughan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:08:48 by yboughan          #+#    #+#             */
/*   Updated: 2023/03/19 12:11:58 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	ft_split_bis_4(char **result, int j, int i, int k)
{
	result[k] = (char *)malloc(sizeof(char) * (j - i + 1));
	if (result[k] == NULL)
		return (0);
	return (1);
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		k;
	int		len;
	char	**result;

	ft_split_bis_1(str, &i, &k, &len);
	result = (char **)malloc(sizeof(char *) * (ft_count_word(str, len) + 1));
	if (result == NULL)
		return (NULL);
	while (i < len)
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
		{
			ft_split_bis_2(str, &j, &i);
			if (ft_split_bis_4(result, j, i, k) == 0)
				return (NULL);
			ft_strncpy(result[k], str + i, j - i);
			ft_split_bis_3(result, &j, &i, &k);
		}
	}
	result[k] = NULL;
	return (result);
}
