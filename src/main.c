/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:58:44 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/30 18:01:09 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"
#include <string.h>

// Bytes Per Pixel. Since each pixel is represented as an integer, it will be four bytes for four channels.
#define BPP sizeof(int32_t)

// void	hook(mlx_key_data_t keydata, void *param)
// {
// 	mlx_t	*mlx = (mlx_t*)param;
// 	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
// 		mlx_close_window(mlx);
// }

// int32_t	main(int argc, char **argv)
// {
	

// 	// Init mlx with a canvas size of 256x256 and the ability to resize the window.
// 	mlx_t* mlx = mlx_init(128, 128, "MLX42", true);

// 	if (!mlx) exit(EXIT_FAILURE);

// 	// Create a 128x128 image.
//     mlx_image_t* img = mlx_new_image(mlx, 128, 128);

//     // Set the channels of each pixel in our image to the maximum byte value of 255. 
//     memset(img->pixels, 0xFF000000, img->width * img->height * BPP);

//     // Draw the image at coordinate (0, 0).
//     mlx_image_to_window(mlx, img, 0, 0);

//     // Run the main loop and terminate on quit.
// 	mlx_key_hook(mlx, &hook, (void *)mlx);
//     mlx_loop(mlx);
//     mlx_terminate(mlx);

//     return (EXIT_SUCCESS);
// }

int	main(void)
{
	t_coords	**coordinates;

	coordinates = parse_map("maps/42.fdf");
	printf("x: %d\n", coordinates[0][0].z);
}
