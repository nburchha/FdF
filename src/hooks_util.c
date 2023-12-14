/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:26:19 by nburchha          #+#    #+#             */
/*   Updated: 2023/12/14 11:02:12 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

void	load_new_image(t_data *data)
{
	calc_2d_coords(data);
	if (data->image)
		mlx_delete_image(data->mlx, data->image);
	data->image = mlx_new_image(data->mlx, data->mlx->width, data->mlx->height);
	mlx_image_to_window(data->mlx, data->image, 0, 0);
	loop_thru_coordinates(data->coordinates, data->image, data->mlx);
}
