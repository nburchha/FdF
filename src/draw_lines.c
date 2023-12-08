/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:09:31 by nburchha          #+#    #+#             */
/*   Updated: 2023/12/08 16:58:14 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

int	inc_pos_neg(int a, int b)
{
	if (a > b)
		return (-1);
	return (1);
}

void	draw_dom_x(mlx_image_t *image, t_coords cur, t_coords c2)
{
	int	e;
	int	dx;
	int	dy;
	int	x_inc;
	int	y_inc;

	dx = abs(c2.x - cur.x);
	dy = abs(c2.y - cur.y);
	e = dx / 2;
	x_inc = inc_pos_neg(cur.x, c2.x);
	y_inc = inc_pos_neg(cur.y, c2.y);
	while (cur.x != c2.x)
	{
		if (cur.y >= 0 && cur.y < HEIGHT && cur.x >= 0 && cur.x < WIDTH)
			mlx_put_pixel(image, cur.x, cur.y, calculate_gradient(cur, c2, 1 - fabs((float)(cur.x - c2.x) / (float)dx)));
		e -= dy;
		if (e < 0)
		{
			cur.y += y_inc;
			e += dx;
		}
		cur.x += x_inc;
	}
}

void	draw_dom_y(mlx_image_t *image, t_coords cur, t_coords c2)
{
	int	e;
	int	dx;
	int	dy;
	int	x_inc;
	int	y_inc;

	dx = abs(c2.x - cur.x);
	dy = abs(c2.y - cur.y);
	e = dx / 2;
	x_inc = inc_pos_neg(cur.x, c2.x);
	y_inc = inc_pos_neg(cur.y, c2.y);
	while (cur.y != c2.y)
	{
		if (cur.y >= 0 && cur.y < HEIGHT && cur.x >= 0 && cur.x < WIDTH)
			mlx_put_pixel(image, cur.x, cur.y, calculate_gradient(cur, c2, 1 - fabs((float)(cur.y - c2.y) / (float)dy)));
		e -= dx;
		if (e < 0)
		{
			cur.x += x_inc;
			e += dy;
		}
		cur.y += y_inc;
	}
}

void	draw_line(mlx_image_t *image, t_coords cur, t_coords c2)
{
	int	dx;
	int	dy;

	dx = abs(c2.x - cur.x);
	dy = abs(c2.y - cur.y);
	if (dx > dy)
		draw_dom_x(image, cur, c2);
	else
		draw_dom_y(image, cur, c2);
}

// void	draw_line(mlx_image_t *image, t_coords cur, t_coords c2)
// {
//     int	dx;
//     int	dy;
//     int	x_inc;
//     int	y_inc;
//     int	error;

//     if (c2.x > cur.x)
//         x_inc = 1;
//     else
//         x_inc = -1;

//     if (c2.y > cur.y)
//         y_inc = 1;
//     else
//         y_inc = -1;

//     dx = c2.x - cur.x;
//     if (dx < 0)
//         dx = -dx;

//     dy = c2.y - cur.y;
//     if (dy < 0)
//         dy = -dy;

//     if (dx > dy)
//         error = dx / 2;
//     else
//         error = -dy / 2;

//     while (cur.x != c2.x || cur.y != c2.y)
//     {
//         mlx_put_pixel(image, cur.x, cur.y, 0xFFFFFFFF);
//         int e2 = error;
//         if (e2 > -dx)
//         {
//             error -= dy;
//             cur.x += x_inc;
//         }
//         if (e2 < dy)
//         {
//             error += dx;
//             cur.y += y_inc;
//         }
//     }
// }

void	loop_thru_coordinates(t_coords **coordinates, mlx_image_t *image)
{
	int	x;
	int	y;

	calc_2d_coords(coordinates, image->height, image->width);
	y = -1;
	while (coordinates[++y] != NULL)
	{
		x = -1;
		while (coordinates[y][++x].is_end == false)
			mlx_put_pixel(image, x, y, 0xFFFFFFFF);
	}
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
