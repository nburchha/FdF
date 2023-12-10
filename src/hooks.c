/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:24:28 by nburchha          #+#    #+#             */
/*   Updated: 2023/12/10 22:01:49 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

void	hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(data->mlx);
		// if (data->coordinates)
		// {
		// 	while (*(data->coordinates) != NULL)
		// 	{
		// 		free(*(data->coordinates));
		// 		(data->coordinates)++;
		// 	}
		// }
		// if (data->keys)
		// 	free(data->keys);
		// free(data);
	}
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
			(data->coordinates)++;
		}
	}
	if (data->keys)
		free(data->keys);
	free(data);
}

/// @brief executed every frame
/// @param param data struct with all info
void	generic_hook(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	calc_2d_coords(data->coordinates, data->mlx->height, data->mlx->width);
	loop_thru_coordinates(data->coordinates, data->image, data->mlx);
	mlx_image_to_window(data->mlx, data->image, 0, 0);
}