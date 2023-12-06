/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:09:31 by nburchha          #+#    #+#             */
/*   Updated: 2023/12/06 17:15:07 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

int	inc_pos_neg(int a, int b)
{
	if (a > b)
		return (-1);
	return (1);
}

void	draw_dom_x(mlx_image_t *image, t_coords coordinate1, t_coords coordinate2)
{
	int	e;
	int	dx;
	int	dy;
	int	x_inc;
	int	y_inc;

	dx = abs(coordinate2.x - coordinate1.x);
	dy = abs(coordinate2.y - coordinate1.y);
	e = dx / 2;
	x_inc = inc_pos_neg(coordinate1.x, coordinate2.x);
	y_inc = inc_pos_neg(coordinate1.y, coordinate2.y);
	while (coordinate1.x != coordinate2.x)
	{
		mlx_put_pixel(image, coordinate1.x, coordinate1.y, 0xFF00FFFF);
		e -= dy;
		if (e < 0)
		{
			coordinate1.y += y_inc;
			e += dx;
		}
		coordinate1.x += x_inc;
	}
}

void	draw_dom_y(mlx_image_t *image, t_coords coordinate1, t_coords coordinate2)
{
	int	e;
	int	dx;
	int	dy;
	int	x_inc;
	int	y_inc;

	dx = abs(coordinate2.x - coordinate1.x);
	dy = abs(coordinate2.y - coordinate1.y);
	e = dx / 2;
	x_inc = inc_pos_neg(coordinate1.x, coordinate2.x);
	y_inc = inc_pos_neg(coordinate1.y, coordinate2.y);
	while (coordinate1.y != coordinate2.y)
	{
		mlx_put_pixel(image, coordinate1.x, coordinate1.y, 0xFF00FFFF);
		e -= dx;
		if (e < 0)
		{
			coordinate1.x += x_inc;
			e += dy;
		}
		coordinate1.y += y_inc;
	}
}

void	draw_line(mlx_image_t *image, t_coords coordinate1, t_coords coordinate2)
{
	int	dx;
	int	dy;

	dx = abs(coordinate2.x - coordinate1.x);
	dy = abs(coordinate2.y - coordinate1.y);
	if (dx > dy)
		draw_dom_x(image, coordinate1, coordinate2);
	else
		draw_dom_y(image, coordinate1, coordinate2);
}

// void	draw_line(mlx_image_t *image, t_coords coordinate1, t_coords coordinate2)
// {
//     int	dx;
//     int	dy;
//     int	x_inc;
//     int	y_inc;
//     int	error;

//     if (coordinate2.x > coordinate1.x)
//         x_inc = 1;
//     else
//         x_inc = -1;

//     if (coordinate2.y > coordinate1.y)
//         y_inc = 1;
//     else
//         y_inc = -1;

//     dx = coordinate2.x - coordinate1.x;
//     if (dx < 0)
//         dx = -dx;

//     dy = coordinate2.y - coordinate1.y;
//     if (dy < 0)
//         dy = -dy;

//     if (dx > dy)
//         error = dx / 2;
//     else
//         error = -dy / 2;

//     while (coordinate1.x != coordinate2.x || coordinate1.y != coordinate2.y)
//     {
//         mlx_put_pixel(image, coordinate1.x, coordinate1.y, 0xFFFFFFFF);
//         int e2 = error;
//         if (e2 > -dx)
//         {
//             error -= dy;
//             coordinate1.x += x_inc;
//         }
//         if (e2 < dy)
//         {
//             error += dx;
//             coordinate1.y += y_inc;
//         }
//     }
// }

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
			if (coordinates[y + 1] != NULL)
				draw_line(image, coordinates[y][x], coordinates[y + 1][x]);
			x++;
		}
		y++;
	}
}
