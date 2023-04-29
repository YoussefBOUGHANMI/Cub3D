/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <yboughan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:12:56 by yboughan          #+#    #+#             */
/*   Updated: 2023/03/25 10:41:28 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

char	get_wall_dir(t_cub3d *data, t_rt *rt)
{
	if (rt->h_dist > rt->v_dist && data->px > rt->v_rx)
		return ('W');
	if (rt->h_dist > rt->v_dist && data->px < rt->v_rx)
		return ('E');
	if (rt->h_dist < rt->v_dist && data->py > rt->h_ry)
		return ('N');
	if (rt->h_dist < rt->v_dist && data->py < rt->h_ry)
		return ('S');
	return ('S');
}

unsigned int	create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_pixel_col(t_image *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	add_ray(t_cub3d *data, t_rt *rt, int line_pos, float angle)
{
	float	line_h;
	float	ca;

	ca = data->pa - angle;
	if (rt->h_dist < rt->v_dist)
	{
		rt->r_dist = rt->h_dist;
		rt->rx = (int)rt->h_rx >> 5;
		rt->ry = (int)rt->h_ry >> 5;
	}
	else
	{
		rt->r_dist = rt->v_dist;
		rt->rx = (int)rt->v_rx >> 5;
		rt->ry = (int)rt->v_ry >> 5;
	}
	line_h = 32 * SIZE_H / (rt->r_dist * cos(ca));
	if (line_h < 0)
		line_h = 0;
	data->rays[line_pos] = line_h;
	data->rays_col[line_pos] = get_wall_dir(data, rt);
}
