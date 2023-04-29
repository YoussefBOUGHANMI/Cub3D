/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outils_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <yboughan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:17:04 by yboughan          #+#    #+#             */
/*   Updated: 2023/03/25 14:12:51 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

void	ft_init_var(t_cub3d *data)
{
	data->p_cub = NULL;
	data->map = NULL;
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->c = NULL;
	data->f = NULL;
	data->pos_j = 0;
}

int	ft_check_err_1(t_cub3d *data, int ac, char **av)
{
	if (ac > 1)
	{
		if (ft_find_map(av[1]) == 0 || ft_find_cub(av[1]) == 0)
		{
			printf("Error\n argument map\n");
			return (1);
		}
		data->map_name = av[1];
		ft_cube3d(data);
	}
	else
	{
		printf("Error\n argument missing\n");
		return (1);
	}
	return (0);
}

int	ft_cube3d(t_cub3d *data)
{
	ft_init_var(data);
	if (ft_parcing(data) == -1)
	{
		ft_free_all(data);
		exit(-1);
	}
	if (ft_find_map(data->no) == 0 || ft_find_map(data->so) == 0
		|| ft_find_map(data->ea) == 0 || ft_find_map(data->we) == 0)
	{
		printf("Error\n texture\n");
		exit (-1);
	}
	return (0);
}

int	ft_find_xpm(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.' && str[i + 1] == 'x' && str[i + 2] == 'p'
			&& str[i + 3] == 'm' && str[i + 4] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	ft_find_map(char *str)
{
	int	f;

	f = open(str, O_RDONLY);
	if (f == -1)
	{
		close(f);
		return (0);
	}
	return (1);
}
