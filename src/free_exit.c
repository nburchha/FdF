/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:12:36 by nburchha          #+#    #+#             */
/*   Updated: 2023/12/14 11:00:39 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

void	free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

void	free_exit_coordinates(char **coordinates, char *line, t_coords **coords)
{
	int	i;

	i = -1;
	if (coords[++i] != NULL)
	{
		while (coords[i] != NULL)
		{
			free(coords[i]);
			coords[i] = NULL;
		}
	}
	if (coordinates != NULL)
		free_split(coordinates);
	if (line != NULL)
	{
		free(line);
		line = NULL;
	}
	exit(1);
}

void	free_exit_data(t_data *data)
{
	int	i;

	if (data->mlx)
		mlx_terminate(data->mlx);
	if (data->coordinates)
	{
		i = -1;
		while (data->coordinates[++i] != NULL)
		{
			free(data->coordinates[i]);
			data->coordinates[i] = NULL;
		}
		free(data->coordinates);
		data->coordinates = NULL;
	}
	free(data);
	data = NULL;
}
