/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:24:28 by nburchha          #+#    #+#             */
/*   Updated: 2023/12/12 21:24:51 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

void	load_new_image(t_data *data)
{
	calc_2d_coords(data);
	if (data->image)
		mlx_delete_image(data->mlx, data->image);
	data->image = mlx_new_image(data->mlx, data->mlx->width, data->mlx->height);
	printf("new image\n");
	mlx_image_to_window(data->mlx, data->image, 0, 0);
	loop_thru_coordinates(data->coordinates, data->image, data->mlx);
	// printf("neues image\n");
	// mlx_image_to_window(data->mlx, data->image, 0, 0);
}

void	resize_hook(int width, int height, void *param)
{
	height = width;
	width = height;
	load_new_image((t_data *)param);
}

void	scroll_hook(double xdelta, double ydelta, void* param)
{
	t_data *data;

	data = (t_data *)param;
	// if (data->z_rotation_rad >= 6.28319 || data->z_rotation_rad <= -6.28319)
	// 	data->z_rotation_rad = 0;
	if (data->key_r == true)
		data->z_rotation_rad += ydelta * 0.0174533;
	else if (data->key_e == true)
		data->y_rotation_rad += ydelta * 0.0174533;
	else if (data->key_q == true)
		data->offset_y += 25 * ydelta;
	else if (data->key_w == true)
		data->offset_x += 25 * ydelta;
	else if (data->zoom + 0.5 * ydelta > 0)
		data->zoom += 0.5 * ydelta;
	load_new_image(data);
	ydelta = xdelta;
	// if (keydata.key == MLX_KEY_W && mlx_is_key_down(data->mlx, keydata.key))
	// 	data->x_rotation_rad += 0.0174533;
	// if (keydata.key == MLX_KEY_S && mlx_is_key_down(data->mlx, keydata.key))
	// 	data->x_rotation_rad += -0.0174533;
}

void	hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		data->key_w = true;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		data->key_w = false;
	if (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS)
		data->key_q = true;
	if (keydata.key == MLX_KEY_Q && keydata.action == MLX_RELEASE)
		data->key_q = false;
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
		data->key_r = true;
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_RELEASE)
		data->key_r = false;
	// if (keydata.key != MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		// load_new_image(data);
}

void	close_hook(void *param)
{
	t_data	*data;

	data = (t_data*)param;
	mlx_close_window(data->mlx);
	if (data->coordinates)
	{
		while (*(data->coordinates) != NULL)
		{
			free(*(data->coordinates));
			*(data->coordinates) = NULL;
			(data->coordinates)++;
		}
	}
	free(data);
	data = NULL;
}
