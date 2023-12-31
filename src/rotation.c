/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:13:24 by nburchha          #+#    #+#             */
/*   Updated: 2023/12/12 22:07:14 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

// float	rotation_x(float x, float y, t_data *data)
// {
// 	float	z;

// 	z = data->coordinates[(int)y][(int)x].z;

// 	return (x * cos(data->y_rotation_rad) * cos(data->z_rotation_rad)
// 			- y * sin(data->z_rotation_rad)
// 			+ z * sin(data->y_rotation_rad) * cos(data->z_rotation_rad));
// }

// float	rotation_y(float x, float y, t_data *data)
// {
// 	float	z;

// 	z = data->coordinates[(int)y][(int)x].z;

// 	return (x * cos(data->y_rotation_rad) * sin(data->z_rotation_rad)
// 			+ y * cos(data->z_rotation_rad)
// 			+ z * sin(data->y_rotation_rad) * sin(data->z_rotation_rad));
// }

// float	rotation_z(float x, float y, t_data *data)
// {
// 	float	z;

// 	z = data->coordinates[(int)y][(int)x].z;

// 	return (-x * sin(data->y_rotation_rad)
// 			+ z * cos(data->y_rotation_rad));
// }

float	rotation_x(float x, float y, t_data *data)
{
	return (x * cos(data->z_rotation_rad) - y * sin(data->z_rotation_rad));
}

float	rotation_y(float x, float y, t_data *data)
{
	return (x * sin(data->z_rotation_rad) + y * cos(data->z_rotation_rad));
}
