/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:09:31 by nburchha          #+#    #+#             */
/*   Updated: 2023/12/10 22:04:54 by nburchha         ###   ########.fr       */
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
		if (cur.y >= 0 && cur.y < (int)image->height && cur.x >= 0 && cur.x < (int)image->width)
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
		if (cur.y >= 0 && cur.y < (int)image->height && cur.x >= 0 && cur.x < (int)image->width)
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

void	loop_thru_coordinates(t_coords **coordinates, mlx_image_t *image, mlx_t *mlx)
{
	int	x;
	int	y;

	mlx_delete_image(mlx, image);
	image = mlx_new_image(mlx, mlx->width, mlx->height);
	mlx_image_to_window(mlx, image, 0, 0);
	y = -1;
	while (++y < mlx->height)
	{
		x = -1;
		while (++x < mlx->width)
			mlx_put_pixel(image, x, y, 0x000000FF);
	}
	y = -1;
	while (coordinates[++y] != NULL)
	{
		x = -1;
		while (coordinates[y][++x].is_end == false)
		{
			if (coordinates[y][x + 1].is_end == false)
				draw_line(image, coordinates[y][x], coordinates[y][x + 1]);
			if (coordinates[y + 1] != NULL)
				draw_line(image, coordinates[y][x], coordinates[y + 1][x]);
		}
	}
}


//when changing the window size too much there is something being cut of sometimes, why??