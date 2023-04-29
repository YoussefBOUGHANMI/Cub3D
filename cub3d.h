/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <yboughan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:53:03 by yboughan          #+#    #+#             */
/*   Updated: 2023/03/19 16:16:34 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# define PI 3.1415926535897932384626433832795
# define P2 1.57079632679
# define P3 4.71238898038
# define CUBE_SIZE 32
# define SIZE_H 540
# define DR 0.00109083125

typedef struct image
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_image;

typedef struct all_images
{
	t_image	*screen_im;
	t_image	*no_im;
	t_image	*so_im;
	t_image	*we_im;
	t_image	*ea_im;
}t_all_images;

typedef struct ray_cast
{
	float	h_rx;
	float	h_ry;
	float	h_ra;
	float	h_xo;
	float	h_yo;
	float	h_dist;
	float	atan;
	float	v_rx;
	float	v_ry;
	float	v_ra;
	float	v_xo;
	float	v_yo;
	float	v_dist;
	float	ntan;

	float	r_dist;
	char	wall_dir;
	int		rx;
	int		ry;
}t_rt;

typedef struct cub3d
{
	unsigned int	ceilling_col;
	unsigned int	floor_col;
	char			**p_cub;
	char			**map;
	char			pos_j;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*map_name;
	int				px;
	int				py;
	float			pdx_1;
	float			pdy_1;
	float			pa;
	float			pdx_2;
	float			pdy_2;
	int				*f;
	int				*c;
	void			*mlx;
	void			*mlx_win;
	t_rt			rt;
	t_all_images	*data_im;
	int				i_rays;
	int				rays[960];
	char			rays_col[960];
	int				old_x;
	int				old_y;
	int				old_dir;
	int				nb_cube;
	int				x_desc[960];
}t_cub3d;

t_image			*get_wall_im(t_cub3d *data, int i);
unsigned int	create_trgb(int r, int g, int b);
unsigned int	get_pixel_col(t_image *img, int x, int y);
int				ft_strcmp(char *s1, char *s2);
int				ft_strlen(char *str);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
char			*ft_strchr(const char *s, int c);
char			**ft_split(char *str);
char			**ft_split_simple(char *s, char c);
int				ft_tablen(char **tab);
char			**ft_malloc_cub(int n, char *buf);
char			**ft_read_cub(t_cub3d *data);
void			ft_init_var(t_cub3d *data);
int				*ft_path_fc(char *str);
char			*ft_path(char *str);
int				ft_verif_ex_0(t_cub3d *data, char **line);
int				ft_verif_ex(t_cub3d *data, char **line);
int				ft_verif_para(t_cub3d *data);
void			ft_creat_map(t_cub3d *data, int j, int i);
int				ft_v_soeaweno(t_cub3d *data);
int				ft_search_p_j(t_cub3d *data);
int				ft_verif_map(t_cub3d *data);
int				ft_parcing(t_cub3d *data);
int				ft_manage_pj(t_cub3d *data);
void			ft_print_tab(char **tab);
int				ft_find_map(char *str);
int				ft_find_cub(char *str);
int				ft_check_err_1(t_cub3d *data, int ac, char **av);
int				ft_check_err_2(t_cub3d *data, int ac, char **av);
int				ft_cube3d(t_cub3d *data);
int				ft_find_xpm(char *str);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
int				ft_count_word(char *str, int len);
void			ft_split_bis_1(char *str, int *i, int *k, int *len);
void			ft_split_bis_2(char *str, int *j, int *i);
void			ft_split_bis_3(char **result, int *j, int *i, int *k);
void			ft_init_var(t_cub3d *data);
void			ft_free_all(t_cub3d *data);
void			free_double_tab(char **tab);
void			draw_case(t_cub3d *data, int x_pos, int y_pos, int col);
void			draw_mini_map(t_cub3d *data);
int				get_width(char **map);
int				get_length(char **map);
void			int_pos_player(t_cub3d *data);
void			draw_player(t_cub3d *data);
void			draw_line(t_cub3d *data, float angle);
void			draw_vision(t_cub3d *data, t_rt *rt);
void			calcul_h_dist(t_cub3d *data, t_rt *rt, float angle);
void			calcul_v_dist(t_cub3d *data, t_rt *rt, float angle);
void			draw_rc(t_cub3d *data, float r_dist, int line_pos, float angle);
int				move_player(int key, t_cub3d *data);
float			dist(t_cub3d *data, float bx, float by, float ang);
void			int_delta(t_cub3d *data);
void			display(t_cub3d *data);
unsigned int	create_trgb(int r, int g, int b);
int				ft_destroy(void);
int				check_case(int x, int y, t_cub3d *data);
void			move_cam_left(t_cub3d *data);
void			move_cam_right(t_cub3d *data);
void			move_player_straight(t_cub3d *data);
void			move_player_back(t_cub3d *data);
void			get_ceilling_floor(t_cub3d *data);
void			ft_init_screen_im(t_cub3d *data);
void			ft_init_screen_no(t_cub3d *data);
void			ft_init_screen_so(t_cub3d *data);
void			ft_init_screen_we(t_cub3d *data);
void			ft_init_screen_ea(t_cub3d *data);
void			init_all_images(t_cub3d *data);
void			get_ceilling_floor(t_cub3d *data);
char			get_wall_dir(t_cub3d *data, t_rt *rt);
void			add_ray(t_cub3d *data, t_rt *rt, int line_pos, float angle);
void			draw_ceiling(t_cub3d *data, int *ii, int i);
void			draw_wall(t_cub3d *data, int *ii, int i);
void			draw_floor(t_cub3d *data, int *ii, int i);
void			draw_screen(t_cub3d *data);
void			calcul_x_size(int line_pos, t_rt *rt, t_cub3d *data);
void			draw_vision(t_cub3d *data, t_rt *rt);
void			my_mlx_pixel_put(t_image *img, int x, int y, int color);
#endif
