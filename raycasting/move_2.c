/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <yboughan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:59:21 by yboughan          #+#    #+#             */
/*   Updated: 2023/03/19 12:59:45 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

void	move_player_left(t_cub3d *data)
{
	if (check_case(data->px + floor(data->pdx_2), \
		data->py + floor(data->pdy_2), data) == 0)
		return ;
	data->px = data->px + floor(data->pdx_2);
	data->py = data->py + floor(data->pdy_2);
}

void	move_player_right(t_cub3d *data)
{
	if (check_case(data->px - floor(data->pdx_2), \
		data->py - floor(data->pdy_2), data) == 0)
		return ;
	data->px = data->px - floor(data->pdx_2);
	data->py = data->py - floor(data->pdy_2);
}

int	move_player(int key, t_cub3d *data)
{
	if (key == 123)
		move_cam_left(data);
	if (key == 124)
		move_cam_right(data);
	if (key == 13)
		move_player_straight(data);
	if (key == 1)
		move_player_back(data);
	if (key == 0)
		move_player_left(data);
	if (key == 2)
		move_player_right(data);
	if (key == 53)
		exit(0);
	draw_vision(data, &data->rt);
	return (0);
}
