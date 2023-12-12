/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:39:02 by nburchha          #+#    #+#             */
/*   Updated: 2023/12/12 21:25:08 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <errno.h>

#define BPP sizeof(int32_t)
#define WIDTH 1000 //5120
#define HEIGHT 1000 //2880

#include "../MLX42/include/MLX42/MLX42.h"
#include "libft/libft.h"

typedef struct s_coords
{
	int	x;
	int	y;
	int	z;
	int	color;
	bool	is_end;
}		t_coords;

typedef struct s_data
{
	int			rotation;
	float			zoom;
	int			offset_x;
	int			offset_y;
	double		x_rotation_rad;
	double		y_rotation_rad;
	double		z_rotation_rad;
	mlx_image_t	*image;
	mlx_t		*mlx;
	t_coords	**coordinates;
	bool	key_r;
	bool	key_q;
	bool	key_w;
	bool	key_e;
}	t_data;

t_coords	**parse_map(char *file);
void		free_exit(char **coordinates, char *line, t_coords **coords);
void		free_split(char **tab);
int			get_map_size(char *file);
void		calc_2d_coords(t_data *data);
void		draw_line(mlx_image_t *image, t_coords c1, t_coords c2);
void		loop_thru_coordinates(t_coords **coordinates, mlx_image_t *image, mlx_t *mlx);
void		draw_dom_x(mlx_image_t *image, t_coords c1, t_coords c2);
int			calculate_gradient(t_coords coord_a, t_coords coord_b, float fraction);
void		generic_hook(void *param);
void	close_hook(void *param);
void	hook(mlx_key_data_t keydata, void *param);
void	load_new_image(t_data *data);
void	resize_hook(int width, int height, void *param);
void	scroll_hook(double xdelta, double ydelta, void* param);

float	rotation_x(float x, float y, t_data *data);
float	rotation_y(float x, float y, t_data *data);
float	rotation_z(float x, float y, t_data *data);