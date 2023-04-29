/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <yboughan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:03:27 by yboughan          #+#    #+#             */
/*   Updated: 2023/03/19 16:24:25 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

float	dist(t_cub3d *data, float bx, float by, float ang)
{
	(void)ang;
	return (sqrt((bx - data->px) * \
		(bx - data->px) + (by - data->py) * (by - data->py)));
}

void	init_dir_vision(t_cub3d *data)
{
	if (data->pos_j == 'E')
		data->pa = 0;
	if (data->pos_j == 'N')
		data->pa = P3;
	if (data->pos_j == 'W')
		data->pa = PI;
	if (data->pos_j == 'S')
		data->pa = P2;
}

void	int_delta(t_cub3d *data)
{
	float	angle;

	init_dir_vision(data);
	data->pdx_1 = cos(data->pa) * 12;
	data->pdy_1 = sin(data->pa) * 12;
	angle = data->pa - P2;
	if (angle < 0)
		angle += 2 * PI;
	data->pdx_2 = cos(angle) * 12;
	data->pdy_2 = sin(angle) * 12;
}

int	ft_destroy(void)
{
	exit (0);
}
