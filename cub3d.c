/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <yboughan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:48:23 by yboughan          #+#    #+#             */
/*   Updated: 2023/03/19 15:39:40 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

int	main(int ac, char **av)
{
	t_cub3d	data;

	if (ft_check_err_1(&data, ac, av) == 1)
		return (0);
	if (ft_check_err_2(&data, ac, av) == 1)
		return (0);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 960, SIZE_H, "cub3d");
	int_pos_player(&data);
	int_delta(&data);
	init_all_images(&data);
	get_ceilling_floor(&data);
	draw_vision(&data, &data.rt);
	mlx_hook(data.mlx_win, 2, 1L << 0, move_player, &data);
	mlx_hook(data.mlx_win, 17, 0, ft_destroy, NULL);
	mlx_loop(data.mlx);
	return (0);
}
