/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:39:02 by nburchha          #+#    #+#             */
/*   Updated: 2023/12/04 20:04:56 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

#include "../MLX42/include/MLX42/MLX42.h"
#include "libft/libft.h"

// typedef enum e_bool{false, true}	t_bool;

typedef struct s_FdF
{
	int	size_x;
	int	size_y;
}	t_FdF;

typedef struct s_coords
{
	float	x;
	float	y;
	int	z;
	int	color;
	bool	is_end;
}		t_coords;

t_coords	**parse_map(char *file);
void		free_exit(char **coordinates, char *line, t_coords **coords);
void		free_split(char **tab);
int			get_map_size(char *file);
void		calc_2d_coords(t_coords **coordinates);
void		draw_line(mlx_image_t *image, t_coords coordinate1, t_coords coordinate2);
void		loop_thru_coordinates(t_coords **coordinates, mlx_image_t *image);

