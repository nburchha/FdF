/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:58:44 by nburchha          #+#    #+#             */
/*   Updated: 2023/12/14 21:21:51 by nburchha         ###   ########.fr       */
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

/* int	main(void)
// {
// 	mlx_t		*mlx;
// 	mlx_image_t	*image;
// 	// t_coords	**coordinates;

// 	// if (argc != 2)
// 	// 	exit(1);
// 	// mlx_set_setting(MLX_MAXIMIZED, true);
// 	mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
// 	if (!mlx)
// 		exit(EXIT_FAILURE);
// 	image = mlx_new_image(mlx, WIDTH, HEIGHT);
// 	if (!image)
// 		exit(EXIT_FAILURE);
// 	draw_dom_x(image, (t_coords){0, 0, 0, 0xFF000000, false}, \
// 	(t_coords){1000, 1000, 0, 0x0000FFFF, false});
// 	mlx_image_to_window(mlx, image, 0, 0);
// 	mlx_key_hook(mlx, &hook, (void *)mlx);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// }*/
