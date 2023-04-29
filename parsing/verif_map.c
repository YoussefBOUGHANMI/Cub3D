/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <yboughan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:09:52 by pschemit          #+#    #+#             */
/*   Updated: 2023/03/25 14:13:26 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	ft_v_lpd(t_cub3d *data, int i)
{
	int	j;

	j = 0;
	while (data->map[i][j])
	{
		if (data->map[i][j] != ' ' && data->map[i][j] != '1')
			return (-1);
		j++;
	}
	return (1);
}

int	ft_v_hall_bis(t_cub3d *data, int i, int j)
{
	if ((data->map[i][j] != ' ' && data->map[i][j] != '1' && data-> \
		map[i][j] != '0' && data->map[i][j] != data->pos_j) && data->map[i][j])
		return (1);
	return (0);
}

int	ft_v_hall(t_cub3d *data, int i)
{
	int	j;

	j = 0;
	while (data->map[i][j])
	{
		if (ft_v_hall_bis(data, i, j) == 1)
			return (-3);
		if (data->map[i][j] == '0')
		{
			if (data->map[i - 1][j] != '1' && data->map[i - 1][j] != '0'
				&& data->map[i - 1][j] != data->pos_j)
				return (-2);
			if (data->map[i + 1][j] != '1' && data->map[i + 1][j] != '0'
				&& data->map[i + 1][j] != data->pos_j)
				return (-2);
			if (data->map[i][j - 1] != '1' && data->map[i][j - 1] != '0'
				&& data->map[i][j - 1] != data->pos_j)
				return (-2);
			if (data->map[i][j + 1] != '1' && data->map[i][j + 1] != '0'
				&& data->map[i][j + 1] != data->pos_j)
				return (-2);
		}
		j++;
	}
	return (1);
}

int	ft_verif_map(t_cub3d *data)
{
	int	i;
	int	a;

	if ((ft_v_lpd(data, ft_tablen(data->map) - 1) == -1)
		|| (ft_v_lpd(data, 0) == -1))
	{
		printf("Error\n parsing : first or end line\n");
		return (-1);
	}
	if (ft_manage_pj(data) < 0)
		return (-1);
	i = 0;
	while (data->map[i])
	{
		a = ft_v_hall(data, i++);
		if (a < 0)
		{
			if (a == -2)
				printf("Error\n parsing : Map ouverte\n");
			if (a == -3)
				printf("Error\n parsing : Caractere inexistant\n");
			return (-1);
		}
	}
	return (1);
}

int	ft_check_err_2(t_cub3d *data, int ac, char **av)
{
	(void)ac;
	(void)av;
	if (ft_find_xpm(data->no) == 0 || ft_find_xpm(data->so) == 0
		|| ft_find_xpm(data->we) == 0 || ft_find_xpm(data->ea) == 0)
	{
		printf("Error\n : xpm\n");
		return (1);
	}
	return (0);
}
