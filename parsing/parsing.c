/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <yboughan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:03:02 by pschemit          #+#    #+#             */
/*   Updated: 2023/03/19 12:18:55 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	ft_len_ligne(char **map)
{
	int	i;
	int	a;
	int	j;

	i = 0;
	a = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (a < j)
				a = j;
			j++;
		}
		i++;
	}
	return (a);
}

void	ft_init_creat_map(t_cub3d *data, int *a, int *i)
{
	*a = ft_len_ligne(data->map);
	*i = 0;
}

void	creat_map(t_cub3d *data)
{
	char	**tab;
	int		a;
	int		i;
	int		j;

	tab = malloc(sizeof(char *) * ft_tablen(data->map) + 1);
	ft_init_creat_map(data, &a, &i);
	while (data->map[i])
	{
		j = 0;
		tab[i] = malloc(sizeof(char) * a + 1);
		while (j < a)
		{
			if (data->map[i][j] && data->map[i][j] != ' ')
				tab[i][j] = data->map[i][j];
			else
				tab[i][j] = '1';
			j++;
		}
		tab[i][j] = '1';
		tab[i++][j + 1] = '\0';
	}
	tab[i] = NULL;
	free_double_tab(data->map);
	data->map = tab;
}

int	ft_parcing(t_cub3d *data)
{
	data->p_cub = ft_read_cub(data);
	if (ft_v_soeaweno(data) == -1)
		return (-1);
	if (ft_verif_map(data) == -1)
		return (-1);
	creat_map(data);
	return (1);
}
