/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:58:44 by nburchha          #+#    #+#             */
/*   Updated: 2023/12/10 21:41:29 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"
#include <string.h>


void	print_coordinates(t_coords **coordinates)
{
	int	x;
	int	y;

	y = 0;
	while (coordinates[y] != NULL)
	{
		x = 0;
		while (coordinates[y][x].is_end == false)
		{
			printf("%d	", coordinates[y][x].z);
			x++;
		}
		printf("\n");
		y++;
	}
}

t_keys_held	*init_keys(void)
{
	t_keys_held	*keys;

	keys = (t_keys_held *)malloc(sizeof(t_keys_held));
	if (!keys)
		exit (1);//error handling
	keys->scroll_down = false;
	keys->scroll_up = false;
	return (keys);
}

t_data	*init_data(t_coords **coordinates)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		exit (1);//handle error
	data->mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
	if (!data->mlx)
		exit(EXIT_FAILURE);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->image)
		exit(EXIT_FAILURE);
	data->rotation = 0;
	data->zoom = 1;
	data->keys = init_keys();
	data->coordinates = coordinates;
	return (data);
}

//put more functions in main loop, that arent there to initialize the window etc?
void	init_fdf(t_coords **coordinates)
{
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		exit(1);
	data = init_data(coordinates);
	loop_thru_coordinates(coordinates, data->image, data->mlx);
	mlx_image_to_window(data->mlx, data->image, 0, 0);
	mlx_key_hook(data->mlx, &hook, (void *)data);
	mlx_loop_hook(data->mlx, &generic_hook, (void *)data);
	mlx_close_hook(data->mlx, &close_hook, (void *)data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
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


// int	main(void)
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
// 	draw_dom_x(image, (t_coords){0, 0, 0, 0xFFFFFFFF, false}, (t_coords){1000, 1000, 0, 0x000000FF, false});
// 	mlx_image_to_window(mlx, image, 0, 0);
// 	mlx_key_hook(mlx, &hook, (void *)mlx);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// }
