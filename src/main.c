/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:58:44 by nburchha          #+#    #+#             */
/*   Updated: 2023/12/06 17:14:40 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"
#include <string.h>
#define BPP sizeof(int32_t)
#define WIDTH 500
#define HEIGHT 500

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
void	hook(mlx_key_data_t keydata, void *param)
{
	mlx_t	*mlx = (mlx_t*)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(mlx);
}

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_coords	**coordinates;

	// if (argc != 2)
	// 	exit(1);
	coordinates = parse_map("test_maps/42.fdf");
	calc_2d_coords(coordinates, WIDTH, HEIGHT);
	// mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!image)
		exit(EXIT_FAILURE);
	loop_thru_coordinates(coordinates, image);
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_key_hook(mlx, &hook, (void *)mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
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
// 	draw_dom_x(image, (t_coords){100, 100, 0, 0xFFFFFFFF, false}, (t_coords){0, 0, 0, 0xFFFFFFFF, false});
// 	mlx_image_to_window(mlx, image, 0, 0);
// 	mlx_key_hook(mlx, &hook, (void *)mlx);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// }