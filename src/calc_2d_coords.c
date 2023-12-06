/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_2d_coords.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:45:47 by nburchha          #+#    #+#             */
/*   Updated: 2023/12/06 17:11:58 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

void	calc_2d_coords(t_coords **coordinates, int screen_width, int screen_height)
{
	int	x;
	int	y;
	int	scale_factor = 15;

	y = 0;
	while (coordinates[y] != NULL)
	{
		x = 0;
		while (coordinates[y][x].is_end == false)
		{
			coordinates[y][x].x = ((x - y) * cos(0.523599)) * scale_factor + screen_width / 2;
			coordinates[y][x].y = ((x + y) * sin(0.523599) - coordinates[y][x].z) * scale_factor + screen_height / 2; //0.523599 = 30 degrees
			printf("x: %d\ty: %d\n", coordinates[y][x].x, coordinates[y][x].y);
			x++;
		}
		y++;
	}
}

// void	calc_2d_coords(t_coords **coordinates)
// {
// 	int	x;
// 	int	y;
// 	int	scale_factor = 5;

// 	y = 0;
// 	while (coordinates[y] != NULL)
// 	{
// 		x = 0;
// 		while (coordinates[y][x].is_end == false)
// 		{
// 			coordinates[y][x].x = (x - coordinates[y][x].z)/ sqrt(2) * scale_factor;
// 			coordinates[y][x].y = (x + 2 * y + coordinates[y][x].z) / sqrt(6) * scale_factor;
// 			printf("x: %f\ty: %f\n", coordinates[y][x].x, coordinates[y][x].y);
// 			x++;
// 		}
// 		y++;
// 	}
// }