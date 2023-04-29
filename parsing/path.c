/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <yboughan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:09:24 by pschemit          #+#    #+#             */
/*   Updated: 2023/03/19 18:56:27 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

char	*ft_path(char *str)
{
	char	*path;
	int		j;

	if (!str)
	{
		printf("Error\nParsing\n");
		exit(-1);
	}
	j = 0;
	path = malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[j])
	{
		path[j] = str[j];
		j++;
	}
	path[j] = '\0';
	if (j == 0)
		return (NULL);
	return (path);
}

int	ft_v_digit(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] < '0' || str[i][j] > '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	*ft_path_fc(char *str)
{
	char	**tab;
	int		*num;
	int		i;
	int		test;

	i = 0;
	num = malloc(sizeof(int) * (3 + 1));
	tab = ft_split_simple(str, ',');
	if (ft_v_digit(tab) == 0)
		return (NULL);
	if (tab[0] && tab[1] && tab[2] && !tab[3])
	{
		while (tab[i])
		{
			test = ft_atoi(tab[i++]);
			if (test <= 255 && test >= 0)
				num[i] = test;
			else
				return (NULL);
		}
	}
	else
		return (NULL);
	free_double_tab (tab);
	return (num);
}
