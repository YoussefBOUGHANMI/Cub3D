/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <yboughan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:28:37 by yboughan          #+#    #+#             */
/*   Updated: 2023/03/19 13:28:54 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

void	calcul_x_size(int line_pos, t_rt *rt, t_cub3d *data)
{
	if (rt->h_dist < rt->v_dist)
		data->x_desc[line_pos] = (int)floor(rt->h_rx * 2) % 64;
	else
		data->x_desc[line_pos] = (int)floor(rt->v_ry * 2) % 64;
}

void	draw_vision(t_cub3d *data, t_rt *rt)
{
	float	angle;
	int		i;

	data->nb_cube = 0;
	angle = data->pa - DR * 480;
	i = 0;
	while (i < 480 * 2)
	{
		if (angle <= 0)
			angle += 2 * PI;
		if (angle >= 2 * PI)
			angle -= 2 * PI;
		calcul_h_dist(data, rt, angle);
		calcul_v_dist(data, rt, angle);
		add_ray(data, rt, i, angle);
		calcul_x_size(i, rt, data);
		angle += DR;
		i++;
	}
	draw_screen(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
		data->data_im->screen_im->img, 0, 0);
}
