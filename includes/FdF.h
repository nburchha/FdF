/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:39:02 by nburchha          #+#    #+#             */
/*   Updated: 2023/12/17 13:54:17 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <errno.h>
#define WIDTH 1000
#define HEIGHT 1000

#include "../MLX42/include/MLX42/MLX42.h"
#include "libft/libft.h"

typedef struct s_coords
{
	int		x;
	int		y;
	int		z;
	int		color;
	bool	is_end;
	int		size;
}		t_coords;

typedef struct s_data
{
	float		zoom;
	int			offset_x;
	int			offset_y;
	double		y_rotation_rad;
	double		z_rotation_rad;
	mlx_image_t	*image;
	mlx_t		*mlx;
	t_coords	**coordinates;
	bool		key_q;
	bool		key_w;
	bool		key_r;
	bool		key_i;
	bool		key_p;
}	t_data;

t_coords	**parse_map(char *file);
int			get_map_size(char *file);
int			adjust_color_format(int rgb);
bool		fdf_ending(char *file);
void		free_exit_data(t_data *data);
void		free_exit_coordinates(char **coordinates, char *line, \
			t_coords **coords);
void		free_split(char **tab);
int			get_map_size(char *file);
void		calc_2d_coords(t_data *data);
void		draw_line(mlx_image_t *image, t_coords c1, t_coords c2);
void		loop_thru_coordinates(t_coords **coordinates, mlx_image_t *image, \
			mlx_t *mlx);
void		draw_dom_x(mlx_image_t *image, t_coords c1, t_coords c2);
int			calculate_gradient(t_coords coord_a, t_coords coord_b, \
			float fraction);
void		generic_hook(void *param);
void		close_hook(void *param);
void		hook(mlx_key_data_t keydata, void *param);
void		load_new_image(t_data *data);
void		resize_hook(int width, int height, void *param);
void		scroll_hook(double xdelta, double ydelta, void *param);
void		generic_hook(void *param);
void		print_coordinates(t_coords **coordinates);
float		rotation_x(float x, float y, t_data *data);
float		rotation_y(float x, float y, t_data *data);
int			inc_pos_neg(int a, int b);
void		reset_image(mlx_image_t *image, mlx_t *mlx);