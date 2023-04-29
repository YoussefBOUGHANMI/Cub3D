/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <yboughan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:44:54 by yboughan          #+#    #+#             */
/*   Updated: 2023/03/25 10:57:16 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

void	ft_init_screen_we(t_cub3d *data)
{
	int		img_width;
	int		img_height;
	t_image	*wall_image;

	wall_image = malloc(sizeof(t_image));
	data->data_im->we_im = wall_image;
	data->data_im->we_im->img = mlx_xpm_file_to_image(data->mlx, data->we, \
	&img_width, &img_height);
	if ((int)data->data_im->we_im->img == 0)
	{
		printf("Error \nTexture\n");
		exit(-1);
	}
	data->data_im->we_im->addr = mlx_get_data_addr(data->data_im->we_im->img, \
		&data->data_im->we_im->bits_per_pixel, \
		&data->data_im->we_im->line_length, \
		&data->data_im->we_im->endian);
}

void	ft_init_screen_ea(t_cub3d *data)
{
	int		img_width;
	int		img_height;
	t_image	*wall_image;

	wall_image = malloc(sizeof(t_image));
	data->data_im->ea_im = wall_image;
	data->data_im->ea_im->img = mlx_xpm_file_to_image(data->mlx, data->ea, \
	&img_width, &img_height);
	if ((int)data->data_im->ea_im->img == 0)
	{
		printf("Error \nTexture\n");
		exit(-1);
	}
	data->data_im->ea_im->addr = mlx_get_data_addr(data->data_im->ea_im->img, \
		&data->data_im->ea_im->bits_per_pixel, \
		&data->data_im->ea_im->line_length, \
		&data->data_im->ea_im->endian);
}

void	init_all_images(t_cub3d *data)
{
	t_all_images	*all_im;

	all_im = malloc(sizeof(t_all_images));
	data->data_im = all_im;
	ft_init_screen_im(data);
	ft_init_screen_no(data);
	ft_init_screen_so(data);
	ft_init_screen_we(data);
	ft_init_screen_ea(data);
}

void	get_ceilling_floor(t_cub3d *data)
{
	data->ceilling_col = create_trgb(data->c[1], data->c[2], data->c[3]);
	data->floor_col = create_trgb(data->f[1], data->f[2], data->f[3]);
}
