/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:39:02 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/30 18:04:08 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

#include "../MLX42/include/MLX42/MLX42.h"
#include "libft/libft.h"

typedef struct s_FdF
{
	/* data */
}	t_FdF;

typedef struct s_coords
{
	int	z;
	int	color;
}		t_coords;

t_coords	**parse_map(char *file);
void		free_exit(char **coordinates, char *line, t_coords **coords);
void		free_split(char **tab);
