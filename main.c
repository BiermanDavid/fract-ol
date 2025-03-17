/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabierma <dabierma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:55:10 by dabierma          #+#    #+#             */
/*   Updated: 2025/03/17 17:23:32 by dabierma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx/mlx.h"

int main(int argc, char **argv)
{
    t_fractal fractal;
	
    if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) || (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
    {
        fractal.name = argv[1];
        fractal_init(&fractal);
        fractal_render(&fractal);
        mlx_loop(fractal.mlx_connection);
    }
    else
    {
        putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
        exit(EXIT_FAILURE);
    }

}

// gcc *.c -Lminilibx-linux -lmlx_Linux -lX11 -lXext -o fractol