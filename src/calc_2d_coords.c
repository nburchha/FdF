/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_2d_coords.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:45:47 by nburchha          #+#    #+#             */
/*   Updated: 2023/12/08 17:05:35 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

void	calc_2d_coords(t_coords **coordinates, int height, int width)
{
	int	x;
	int	y;
	int	scale_factor = 15;
	float	angle = 0.45;

	y = 0;
	printf("width: %d, height: %d\n", width, height);
	while (coordinates[y] != NULL)
	{
		x = 0;
		while (coordinates[y][x].is_end == false)
		{
			coordinates[y][x].x = ((x - y) * cos(angle)) * scale_factor + width / 2; //muss in abhaengigkeit zur fenster groesse sein, also render setting struct rein da
			coordinates[y][x].y = ((x + y) * sin(angle) - coordinates[y][x].z) * scale_factor + height / 2;
			// printf("x: %d\ty: %d\n", coordinates[y][x].x, coordinates[y][x].y);
			x++;
		}
		y++;
	}
}
