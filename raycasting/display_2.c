/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <yboughan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:28:08 by yboughan          #+#    #+#             */
/*   Updated: 2023/03/19 14:08:18 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

void	draw_ceiling(t_cub3d *data, int *ii, int i)
{
	while (*ii < SIZE_H / 2 - floor(data->rays[i] / 2))
	{
		my_mlx_pixel_put(data->data_im->screen_im, i, *ii, data->ceilling_col);
		*ii = *ii + 1;
	}
}

t_image	*get_wall_im(t_cub3d *data, int i)
{
	if (data->rays_col[i] == 'N')
		return (data->data_im->no_im);
	if (data->rays_col[i] == 'S')
		return (data->data_im->so_im);
	if (data->rays_col[i] == 'E')
		return (data->data_im->ea_im);
	if (data->rays_col[i] == 'W')
		return (data->data_im->we_im);
	return (NULL);
}

void	draw_wall(t_cub3d *data, int *ii, int i)
{
	int		col;
	float	old_size;

	old_size = data->rays[i];
	if (data->rays[i] > SIZE_H)
		data->rays[i] = SIZE_H;
	while (*ii < SIZE_H / 2 + floor(data->rays[i] / 2))
	{
		col = get_pixel_col(get_wall_im(data, i), (int)data->x_desc[i], \
		(int)floor(((*ii - SIZE_H / 2 + floor(old_size / 2)) \
		/ floor(old_size)) * 63));
		my_mlx_pixel_put(data->data_im->screen_im, i, *ii, col);
		*ii = *ii + 1;
	}
}

void	draw_floor(t_cub3d *data, int *ii, int i)
{
	while (*ii < SIZE_H)
	{
		my_mlx_pixel_put(data->data_im->screen_im, i, *ii, data->floor_col);
		*ii = *ii + 1;
	}
}

void	draw_screen(t_cub3d *data)
{
	int	i;
	int	ii;

	i = 0;
	while (i < 960)
	{
		ii = 0;
		draw_ceiling(data, &ii, i);
		draw_wall(data, &ii, i);
		draw_floor(data, &ii, i);
		i++;
	}
}
