/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_2d_coords.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:45:47 by nburchha          #+#    #+#             */
/*   Updated: 2023/12/12 13:18:21 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

void	calc_2d_coords(t_data *data)
{
	int	x;
	int	y;
	float	angle = 0.45;

	y = 0;
	// printf("width: %d, height: %d\n", width, height);
	while (data->coordinates[y] != NULL)
	{
		x = 0;
		while (data->coordinates[y][x].is_end == false)
		{
			data->coordinates[y][x].x = ((rotation_x(x, y, data) - rotation_y(x, y, data)) * cos(angle)) * data->zoom + data->mlx->width / 2 + data->offset_x;
			data->coordinates[y][x].y = ((rotation_x(x, y, data) + rotation_y(x, y, data)) * sin(angle) - data->coordinates[y][x].z) * data->zoom + data->mlx->height / 2 + data->offset_y;
			x++;
		}
		y++;
	}
}
