/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabierma <dabierma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:55:10 by dabierma          #+#    #+#             */
/*   Updated: 2025/03/18 00:23:11 by dabierma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "../mlx/mlx.h"

void	handle_arguments(t_fractal *fractal, int argc, char **argv)
{
	if (argc < 2 || !argv[1])
		input_error(&fractal);
	if (ft_strncmp(argv[1], "Mandelbrot", 11) == 0 && argc == 2)
		fractal->type = 1;
	else if (ft_strncmp(argv[1], "Julia", 6) == 0 && ft_isdigit(argv[3][0]))
		fractal->type = 2;
	else
		input_error(&fractal);
	return ;
}

void	input_error(t_fractal **fractal)
{
	its_not_that_hard();
	if (!*fractal)
		return ;
	if ((*fractal)->init_frame != 1)
		exit (0);
	if ((*fractal)->image && (*fractal)->init_frame == 1)
		mlx_destroy_image((*fractal)->mlx, (*fractal)->image);
	if ((*fractal)->window && (*fractal)->init_frame == 1)
		mlx_destroy_window((*fractal)->mlx, (*fractal)->window);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	if (argc < 2 || !argv[1] || argv[1][0] == '\0')
	{
		its_not_that_hard();
		return (1);
	}
	fractal.init_frame = 0;
	handle_arguments(&fractal, argc, argv);
	// if (fractal.type == 2)
	// 	julia_setup(&fractal, argc, argv);
	initialize_graphic_environment(argv, &fractal);
	define_bounds(&fractal);
	render_fractal(&fractal, 0);
	mlx_hook(fractal.window, 2, 0, esc_handler, &fractal);
	mlx_hook(fractal.window, 17, 0, close_handler, &fractal);
	mlx_mouse_hook(fractal.window, mouse_handler, &fractal);
	mlx_key_hook(fractal.window, key_handler, &fractal);
	mlx_loop(fractal.mlx);
}
