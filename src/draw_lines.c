/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:09:31 by nburchha          #+#    #+#             */
/*   Updated: 2023/12/04 19:44:18 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

void	draw_line(mlx_image_t *image, t_coords coordinate1, t_coords coordinate2)
{
	float	dx;
	float	dy;
	float	f;
	int		delta;

	delta = 0;
	dx = (float)coordinate1.x - coordinate2.x;
	dy = (float)coordinate1.y - coordinate2.y;
	if (dx > dy)
	{
		f = dx / 2;
		while (coordinate2.x - delta > coordinate1.x)
		{
			delta++;
			f -= dx;
			if (f <= 0)
			{
				coordinate1.x++;
				coordinate1.y++;
			}
			else
				coordinate1.x++;
			f += dx;
			mlx_put_pixel(image, coordinate1.x, coordinate1.y, 0xFFFFFFFF);
		}
	}
	else
	{
		f = dy / 2;
		while (coordinate2.y - delta > coordinate1.y)
		{
			delta++;
			f -= dy;
			if (f <= 0)
			{
				coordinate1.y++;
				coordinate1.x++;
			}
			else
				coordinate1.y++;
			f += dy;
			mlx_put_pixel(image, coordinate1.x, coordinate1.y, 0xFFFFFFFF);
		}
	}
}

void	loop_thru_coordinates(t_coords **coordinates, mlx_image_t *image)
{
	int	x;
	int	y;

	y = 0;
	while (coordinates[y] != NULL)
	{
		x = 0;
		while (coordinates[y][x].is_end == false)
		{
			if (coordinates[y][x + 1].is_end == false)
				draw_line(image, coordinates[y][x], coordinates[y][x + 1]);
			if (coordinates[y + 1] != NULL && coordinates[y + 1][x].is_end == false)
				draw_line(image, coordinates[y][x], coordinates[y + 1][x]);
			x++;
		}
		y++;
	}
}
