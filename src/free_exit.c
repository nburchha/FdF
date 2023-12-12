/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:12:36 by nburchha          #+#    #+#             */
/*   Updated: 2023/12/12 10:57:17 by nburchha         ###   ########.fr       */
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

void	free_exit(char **coordinates, char *line, t_coords **coords)
{
	if (coords != NULL)
	{
		while (*coords != NULL)
		{
			free(*coords);
			*coords = NULL;
			coords++;
		}
		// free(coords);
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
