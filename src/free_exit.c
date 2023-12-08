/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:12:36 by nburchha          #+#    #+#             */
/*   Updated: 2023/12/08 13:35:17 by nburchha         ###   ########.fr       */
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
		i++;
	}
	free(tab);
}

void	free_exit(char **coordinates, char *line, t_coords **coords)
{
	if (coords != NULL)
	{
		while (*coords != NULL)
		{
			free(*coords);
			coords++;
		}
		// free(coords);
	}
	if (coordinates != NULL)
		free_split(coordinates);
	if (line != NULL)
		free(line);
	exit(1);
}
