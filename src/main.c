/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:58:44 by nburchha          #+#    #+#             */
/*   Updated: 2023/12/08 16:57:34 by nburchha         ###   ########.fr       */
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

// void	hook(mlx_key_data_t keydata, void *param)
// {
// 	mlx_t	*mlx = (mlx_t*)param;
// 	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
// 		mlx_close_window(mlx);
// }

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

t_render_settings	*init_render_settings(mlx_image_t *img, mlx_t *mlx, t_coords **coordinates)
{
	t_render_settings	*render_settings;

	render_settings = (t_render_settings *)malloc(sizeof(t_render_settings));
	if (!render_settings)
		exit (1);//handle error
	render_settings->image = img;
	render_settings->mlx = mlx;
	render_settings->rotation = 0;
	render_settings->zoom = 1;
	render_settings->keys = init_keys();
	render_settings->coordinates = coordinates;
	return (render_settings);
}

void	init_fdf(t_coords **coordinates)
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_render_settings *render_settings;

	render_settings = (t_render_settings *)malloc(sizeof(t_render_settings));
	if (!render_settings)
		exit(1);
	mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!image)
		exit(EXIT_FAILURE);
	render_settings = init_render_settings(image, mlx, coordinates);
	loop_thru_coordinates(coordinates, image);
	mlx_image_to_window(mlx, image, 0, 0);
	// mlx_key_hook(mlx, &hook, (void *)mlx);
	mlx_loop_hook(mlx, &generic_hook, (void *)render_settings);
	mlx_close_hook(mlx, &close_hook, (void *)render_settings);
	mlx_loop(mlx);
	mlx_terminate(mlx);
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
