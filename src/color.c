/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:00:06 by nburchha          #+#    #+#             */
/*   Updated: 2023/12/12 22:41:37 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

// Get the red channel.
int	get_r(int rgba)
{
	// Move 3 bytes to the right and mask out the first byte.
	return ((rgba >> 24) & 0xFF);
}

// Get the green channel.
int	get_g(int rgba)
{
	// Move 2 bytes to the right and mask out the first byte.
	return ((rgba >> 16) & 0xFF);
}

// Get the blue channel.
int	get_b(int rgba)
{
	// Move 1 byte to the right and mask out the first byte.
	return ((rgba >> 8) & 0xFF);
}

// Get the alpha channel.
int	get_a(int rgba)
{
	// Move 0 bytes to the right and mask out the first byte.
	return (rgba & 0xFF);
}


int	calculate_gradient(t_coords coord_a, t_coords coord_b, float fraction)
{
	int r;
	int g;
	int b;
	int	a;

	if (coord_a.color == coord_b.color)
		return (coord_a.color);
	r = (get_r(coord_b.color) - get_r(coord_a.color));
	g = (get_g(coord_b.color) - get_g(coord_a.color));
	b = (get_b(coord_b.color) - get_b(coord_a.color));
	a = (get_a(coord_b.color) - get_a(coord_a.color));
	r = get_r(coord_a.color) + fraction * r;
	g = get_g(coord_a.color) + fraction * g;
	b = get_b(coord_a.color) + fraction * b;
	a = get_a(coord_a.color) + fraction * a;
	// printf("0x%X\n", ((r << 24) | (g << 16) | (b << 8) | a));
	return ((r << 24) | (g << 16) | (b << 8) | a);
}
