/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <yboughan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:06:11 by yboughan          #+#    #+#             */
/*   Updated: 2023/03/19 14:05:05 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

void	draw_case(t_cub3d *data, int x_pos, int y_pos, int col)
{
	int	i;
	int	ii;

	i = 0;
	while (i < CUBE_SIZE)
	{
		ii = 0;
		while (ii < CUBE_SIZE)
		{
			if (ii == CUBE_SIZE - 1 || i == CUBE_SIZE - 1)
				mlx_pixel_put(data->mlx, data->mlx_win, x_pos + i, \
				y_pos + ii, 0x000000);
			else
				mlx_pixel_put(data->mlx, data->mlx_win, x_pos + i, \
				y_pos + ii, col);
			ii++;
		}
		i++;
	}
}

void	draw_mini_map(t_cub3d *data)
{
	int	i;
	int	ii;

	i = 0;
	while (data->map[i])
	{
		ii = 0;
		while (data->map[i][ii])
		{
			if (data->map[i][ii] == '1')
				draw_case(data, ii * CUBE_SIZE, i * CUBE_SIZE, 0x098D00);
			else if (data->map[i][ii] != ' ')
				draw_case(data, ii * CUBE_SIZE, i * CUBE_SIZE, 0xFFFFFF);
			ii++;
		}
		i++;
	}
}

void	int_pos_player(t_cub3d *data)
{
	int	i;
	int	ii;

	i = 0;
	while (data->map[i])
	{
		ii = 0;
		while (data->map[i][ii])
		{
			if ((data->map[i][ii] == 'N')
			|| (data->map[i][ii] == 'S')
			|| (data->map[i][ii] == 'E')
			|| (data->map[i][ii] == 'W'))
			{
				data->px = ii * CUBE_SIZE + CUBE_SIZE / 2 ;
				data->py = i * CUBE_SIZE + CUBE_SIZE / 2;
				return ;
			}
			ii++;
		}
		i++;
	}
}

void	draw_player(t_cub3d *data)
{
	int	i;
	int	ii;

	i = 0;
	while (i < 5)
	{
		ii = 0;
		while (ii < 5)
		{
			mlx_pixel_put(data->mlx, data->mlx_win, data->px - 2 + ii, \
				data->py - 2 + i, 0xFF0404);
			ii++;
		}
		i++;
	}
	mlx_pixel_put(data->mlx, data->mlx_win, data->px, data->py, 0x0000FF);
}

void	draw_line(t_cub3d *data, float angle)
{
	int	i;
	int	x;
	int	y;
	int	pdx;
	int	pdy;

	i = 0;
	if (angle < 0)
			angle += 2 * PI;
	if (angle > 2 * PI)
		angle -= 2 * PI;
	pdx = cos(angle) * 15;
	pdy = sin(angle) * 15;
	x = data->px;
	y = data->py;
	while (i < 150)
	{
		mlx_pixel_put(data->mlx, data->mlx_win, x, y, 0x000000);
		x = floor(x + pdx);
		y = floor(y + pdy);
		i++;
	}
}
