/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:10:55 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/30 18:03:07 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

int	get_map_size(char *file)
{
	int		fd;
	char	*line;
	int		y;

	y = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		y++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (y);
}

t_coords	assign_single_coordinate(char **z_and_color)
{
	t_coords	coordinate;

	coordinate.z = ft_atoi(z_and_color[0]);
	if (z_and_color[1] != NULL)
		coordinate.color = ft_atoi_hex(z_and_color[1]);
	else
		coordinate.color = 0xFFFFFF;
	free_split(z_and_color);
	return (coordinate);
}

t_coords	*assign_coords(char **str_coordinates, int y)
{
	int			x;
	int			count;
	t_coords	*coordinates_array;
	char		**z_and_color;

	x = -1;
	count = 0;
	while (str_coordinates[count] != NULL)
		count++;
	if (str_coordinates == NULL || str_coordinates[0] == NULL)
		return (NULL);
	coordinates_array = (t_coords *)malloc(count * sizeof(t_coords));
	if (coordinates_array == NULL)
		return (NULL);
	while (str_coordinates[++x] != NULL)
		coordinates_array[x] = assign_single_coordinate(ft_split(str_coordinates[x], ','));
	free_split(str_coordinates);
	return (coordinates_array);
}

// open a certain file and read line by line and save the word (seperated by a space) in a 2d array with ft_split
t_coords	**parse_map(char *file)
{
	int			fd;
	int			y;
	char		*line;
	t_coords	**coords;

	y = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	coords = (t_coords **)malloc((get_map_size(file) + 1) * sizeof(t_coords *));
	line = get_next_line(fd);
	while (line != NULL)
	{
		coords[y] = assign_coords(ft_split(line, ' '), y);
		free(line);
		y++;
	}
	coords[y] = NULL;
	close(fd);
	return (coords);
}
