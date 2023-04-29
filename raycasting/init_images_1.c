/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <yboughan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:37:55 by yboughan          #+#    #+#             */
/*   Updated: 2023/03/25 10:56:30 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

void	ft_init_screen_im(t_cub3d *data)
{
	t_image	*im;

	im = malloc(sizeof(t_image));
	data->data_im->screen_im = im;
	data->data_im->screen_im->img = mlx_new_image(data->mlx, 960, SIZE_H);
	data->data_im->screen_im->addr = mlx_get_data_addr \
		(data->data_im->screen_im->img, \
		&data->data_im->screen_im->bits_per_pixel, \
		&data->data_im->screen_im->line_length, \
		&data->data_im->screen_im->endian);
}

void	ft_init_screen_no(t_cub3d *data)
{
	t_image	*wall_image;
	int		img_width;
	int		img_height;

	wall_image = malloc(sizeof(t_image));
	data->data_im->no_im = wall_image;
	data->data_im->no_im->img = mlx_xpm_file_to_image(data->mlx, data->no, \
	&img_width, &img_height);
	if ((int)data->data_im->no_im->img == 0)
	{
		printf("Error \nTexture\n");
		exit(-1);
	}
	data->data_im->no_im->addr = mlx_get_data_addr(data->data_im->no_im->img, \
		&data->data_im->no_im->bits_per_pixel, \
		&data->data_im->no_im->line_length, \
		&data->data_im->no_im->endian);
}

void	ft_init_screen_so(t_cub3d *data)
{
	int		img_width;
	int		img_height;
	t_image	*wall_image;

	wall_image = malloc(sizeof(t_image));
	data->data_im->so_im = wall_image;
	data->data_im->so_im->img = mlx_xpm_file_to_image(data->mlx, data->so, \
	&img_width, &img_height);
	if ((int)data->data_im->so_im->img == 0)
	{
		printf("Error \nTexture\n");
		exit(-1);
	}
	data->data_im->so_im->addr = mlx_get_data_addr(data->data_im->so_im->img, \
		&data->data_im->so_im->bits_per_pixel, \
		&data->data_im->so_im->line_length, \
		&data->data_im->so_im->endian);
}
