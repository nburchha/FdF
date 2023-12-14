/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:10:55 by nburchha          #+#    #+#             */
/*   Updated: 2023/12/14 16:15:16 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

t_coords	assign_single_coordinate(char **z_and_color, int size)
{
	t_coords	coordinate;

	coordinate.is_end = false;
	coordinate.size = size;
	coordinate.z = ft_atoi(z_and_color[0]);
	if (z_and_color[1] != NULL)
		coordinate.color = adjust_color_format(ft_atoi_hex(z_and_color[1]));
	else
		coordinate.color = 0xFFFFFFFF;
	free_split(z_and_color);
	return (coordinate);
}

t_coords	*assign_coords(char **str_coordinates, int size)
{
	int			x;
	int			count;
	t_coords	*coordinates_array;

	x = -1;
	count = 0;
	while (str_coordinates[count] != NULL)
		count++;
	if (str_coordinates == NULL || str_coordinates[0] == NULL)
		return (NULL);
	coordinates_array = (t_coords *)malloc((count) * sizeof(t_coords));
	if (coordinates_array == NULL)
		return (NULL);
	while (str_coordinates[++x] != NULL)
	{
		coordinates_array[x] = \
		assign_single_coordinate(ft_split(str_coordinates[x], ','), size);
	}
	free_split(str_coordinates);
	coordinates_array[x - 1].is_end = true;
	return (coordinates_array);
}

t_coords	**parse_map(char *file)
{
	int			fd;
	int			y;
	int			size;
	char		*line;
	t_coords	**coords;

	if (fdf_ending(file) == false)
		exit (1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	size = get_map_size(file);
	coords = (t_coords **)malloc((size + 1) * sizeof(t_coords *));
	line = get_next_line(fd);
	y = 0;
	while (line != NULL)
	{
		coords[y] = assign_coords(ft_split(line, ' '), size);
		free(line);
		line = get_next_line(fd);
		y++;
	}
	coords[y] = NULL;
	close(fd);
	return (coords);
}
