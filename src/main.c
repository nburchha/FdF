/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:58:44 by nburchha          #+#    #+#             */
/*   Updated: 2023/12/17 14:13:27 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"
#include <string.h>

void	init_data2(t_data *data)
{
	data->zoom = 15;
	data->offset_x = 0;
	data->offset_y = 0;
	data->y_rotation_rad = 0;
	data->z_rotation_rad = 0;
	data->key_q = false;
	data->key_w = false;
	data->key_r = false;
	data->key_i = false;
	data->key_p = false;
}

t_data	*init_data(t_coords **coordinates)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		exit (1);
	data->coordinates = coordinates;
	data->image = NULL;
	data->mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
	if (!data->mlx)
		free_exit_data(data);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->image)
		free_exit_data(data);
	init_data2(data);
	return (data);
}

void	init_fdf(t_coords **coordinates)
{
	t_data	*data;

	data = init_data(coordinates);
	load_new_image(data);
	mlx_resize_hook(data->mlx, &resize_hook, (void *)data);
	mlx_key_hook(data->mlx, &hook, (void *)data);
	mlx_scroll_hook(data->mlx, &scroll_hook, (void *)data);
	mlx_loop_hook(data->mlx, &generic_hook, (void *)data);
	mlx_loop(data->mlx);
	free_exit_data(data);
}

int	main(int argc, char **argv)
{
	t_coords	**coordinates;

	if (argc != 2)
		exit(1);
	coordinates = parse_map(argv[1]);
	init_fdf(coordinates);
	return (0);
}
