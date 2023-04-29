/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <yboughan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:51:23 by yboughan          #+#    #+#             */
/*   Updated: 2023/04/29 18:11:37 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	check_case(int x, int y, t_cub3d *data)
{
	if (data->map[((int)y >> 5) << 5 / 32][((int)x >> 5) << 5 / 32] == '1')
		return (0);
	if (data->map[((int)(y + 2) >> 5) << 5 / 32] \
		[((int)(x + 2) >> 5) << 5 / 32] == '1')
		return (0);
	if (data->map[((int)(y + 2) >> 5) << 5 / 32] \
		[((int)(x - 2) >> 5) << 5 / 32] == '1')
		return (0);
	if (data->map[((int)(y - 2) >> 5) << 5 / 32] \
		[((int)(x + 2) >> 5) << 5 / 32] == '1')
		return (0);
	if (data->map[((int)(y - 2) >> 5) << 5 / 32] \
		[((int)(x - 2) >> 5) << 5 / 32] == '1')
		return (0);
	return (1);
}

void	move_cam_left(t_cub3d *data)
{
	double	angle;

	data->pa -= (PI / 20);
	if (data->pa < 0)
		data->pa += 2 * PI;
	data->pdx_1 = cos(data->pa) * 10;
	data->pdy_1 = sin(data->pa) * 10;
	angle = data->pa - P2;
	if (angle < 0)
		angle += 2 * PI;
	data->pdx_2 = cos(angle) * 10;
	data->pdy_2 = sin(angle) * 10;
}

void	move_cam_right(t_cub3d *data)
{
	double	angle;

	data->pa += (PI / 20);
	if (data->pa > 2 * PI)
		data->pa -= 2 * PI;
	data->pdx_1 = cos(data->pa) * 10;
	data->pdy_1 = sin(data->pa) * 10;
	angle = data->pa - P2;
	if (angle < 0)
		angle += 2 * PI;
	data->pdx_2 = cos(angle) * 10;
	data->pdy_2 = sin(angle) * 10;
}

void	move_player_straight(t_cub3d *data)
{
	if (check_case(data->px + floor(data->pdx_1), \
		data->py + floor(data->pdy_1), data) == 0)
		return ;
	data->px = data->px + floor(data->pdx_1);
	data->py = data->py + floor(data->pdy_1);
}

void	move_player_back(t_cub3d *data)
{
	if (check_case(data->px - floor(data->pdx_1), \
		data->py - floor(data->pdy_1), data) == 0)
		return ;
	data->px = data->px - floor(data->pdx_1);
	data->py = data->py - floor(data->pdy_1);
}
