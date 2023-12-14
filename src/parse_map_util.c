/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:30:15 by nburchha          #+#    #+#             */
/*   Updated: 2023/12/14 15:19:39 by nburchha         ###   ########.fr       */
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

int	adjust_color_format(int rgb)
{
	if ((rgb & 0xFF000000) == 0)
	{
		rgb = rgb << 8;
		rgb |= 0x000000FF;
	}
	return (rgb);
}

bool	fdf_ending(char *file)
{
	char	**splitted_string;
	int		i;

	splitted_string = ft_split(file, '.');
	if (splitted_string == NULL)
	{
		perror("allocation failed");
		exit(1);
	}
	i = 0;
	while (splitted_string[i])
		i++;
	if (ft_strncmp(splitted_string[i - 1], "fdf", 3) != 0)
	{
		return (perror("wrong file ending"), free_split(splitted_string), \
		false);
	}
	return (free_split(splitted_string), true);
}
