/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:24:28 by nburchha          #+#    #+#             */
/*   Updated: 2023/12/13 18:28:38 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

void	resize_hook(int width, int height, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->mlx->height = height;
	data->mlx->width = width;
	load_new_image(data);
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->key_r == true)
		data->z_rotation_rad += ydelta * 0.0174533;
	else if (data->key_q == true)
		data->offset_y += 10 * ydelta;
	else if (data->key_w == true)
		data->offset_x += 10 * ydelta;
	else if (data->zoom + 0.5 * ydelta > 0)
		data->zoom += 0.5 * ydelta;
	load_new_image(data);
	ydelta = xdelta;
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
	if (keydata.key == MLX_KEY_I && keydata.action == MLX_PRESS)
		data->key_i = !data->key_i;
	if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
	{
		data->key_p = !data->key_p;
		load_new_image(data);
	}
}

// void	close_hook(void *param)
// {
// 	t_data	*data;

// 	data = (t_data *)param;
// 	mlx_close_window(data->mlx);
// 	if (data->coordinates)
// 	{
// 		while (*(data->coordinates) != NULL)
// 		{
// 			free(*(data->coordinates));
// 			*(data->coordinates) = NULL;
// 			(data->coordinates)++;
// 		}
// 	}
// 	free(data);
// 	data = NULL;
// }

void	generic_hook(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->key_i == true)
	{
		data->z_rotation_rad += 0.0174533;
		load_new_image(data);
	}
}
