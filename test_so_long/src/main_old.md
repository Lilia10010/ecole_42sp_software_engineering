#include "so_long.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


static mlx_image_t* image;

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP) || mlx_is_key_down(mlx, MLX_KEY_W))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) || mlx_is_key_down(mlx, MLX_KEY_S))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) || mlx_is_key_down(mlx, MLX_KEY_A))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) || mlx_is_key_down(mlx, MLX_KEY_D))
		image->instances[0].x += 5;
	
}

int32_t main(void)
{
	mlx_t* mlx;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "so_long_X", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	
	mlx_texture_t* texture = mlx_load_png("./assets/img/test00.png");
	if (!texture)
	{
		ft_printf("Erro ao carregar a textura test00.png\n");
		mlx_terminate(mlx);
		return (EXIT_FAILURE);
	}

	image = mlx_texture_to_image(mlx, texture);
	if (!image)
	{
		ft_printf("Erro ao converter textura em imagem\n");
		mlx_delete_texture(texture);
		mlx_terminate(mlx);
		return (EXIT_FAILURE);
	}

	// Exibir a imagem na janela
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		ft_printf("Erro ao exibir a imagem na janela\n");
		mlx_delete_image(mlx, image);
		mlx_terminate(mlx);
		return (EXIT_FAILURE);
	}

		mlx_loop_hook(mlx, ft_hook, mlx);

		mlx_loop(mlx);
		mlx_terminate(mlx);
		return (EXIT_SUCCESS);
	}
