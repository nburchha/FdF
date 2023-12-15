/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_2d_coords.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:45:47 by nburchha          #+#    #+#             */
/*   Updated: 2023/12/15 15:15:48 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

void	isometric_projection(t_data *data, int x, int y)
{
	data->coordinates[y][x].x = ((rotation_x(x, y, data) - \
	rotation_y(x, y, data)) * cos(0.45)) * data->zoom + \
	data->mlx->width / 2 + data->offset_x;
	data->coordinates[y][x].y = ((rotation_x(x, y, data) + \
	rotation_y(x, y, data)) * sin(0.45) - (data->coordinates[y][x].z / 2)) \
	* data->zoom + data->mlx->height / 2 + data->offset_y;
}

void	parallel_projection(t_data *data, int x, int y)
{
	data->coordinates[y][x].x = rotation_x(x, y, data) * data->zoom + \
								data->mlx->width / 2 + data->offset_x;
	data->coordinates[y][x].y = (-data->coordinates[y][x].z / 2) * data->zoom \
								+ data->mlx->height / 2 + data->offset_y;
}

void	calc_2d_coords(t_data *data)
{
	int		x;
	int		y;

	y = -1;
	while (data->coordinates[++y] != NULL)
	{
		x = -1;
		while (data->coordinates[y][++x].is_end == false)
		{
			if (data->key_p == true)
				parallel_projection(data, x, y);
			else
				isometric_projection(data, x, y);
		}
		// if (data->key_p == true)
		// 	parallel_projection(data, x, y);
		// else
		// 	isometric_projection(data, x, y);
	}
}
