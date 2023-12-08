/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:24:28 by nburchha          #+#    #+#             */
/*   Updated: 2023/12/08 15:26:37 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

void	close_hook(void *param)
{
	t_render_settings	*render_settings;

	render_settings = (t_render_settings*)param;
	mlx_close_window(render_settings->mlx);
	if (render_settings->coordinates)
	{
		while (*(render_settings->coordinates) != NULL)
		{
			free(*(render_settings->coordinates));
			(render_settings->coordinates)++;
		}
	}
	if (render_settings->keys)
		free(render_settings->keys);
	free(render_settings);
}

/// @brief executed every frame
/// @param param render_settings struct with all info
void	generic_hook(void *param)
{
	t_render_settings	*render_settings;

	render_settings = (t_render_settings *)param;
	
	loop_thru_coordinates(render_settings->coordinates, render_settings->image);
	mlx_image_to_window(render_settings->mlx, render_settings->image, 0, 0);
	
}