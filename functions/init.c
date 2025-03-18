/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabierma <dabierma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:55:05 by dabierma          #+#    #+#             */
/*   Updated: 2025/03/18 00:22:51 by dabierma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_graphic_environment(char **argv, t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		return ;
	fractal->window = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "fractol");
	if (!fractal->window)
		return ;
	fractal->image = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!(fractal->image))
		return ;
	fractal->address = mlx_get_data_addr(fractal->image, &fractal->bpp,
			&fractal->line_len, &fractal->endian);
	if (argv[2])
		fractal->set_color = ft_atoi(argv[2]);
	else
		fractal->set_color = 4;
	fractal->init_frame = 1;
	return ;
}

void	its_not_that_hard(void)
{
	putstr_fd("#########################################", STDOUT_FILENO);
	putstr_fd("####################################\n", STDOUT_FILENO);
	putstr_fd("#\t\t\tListen... Its not that hard...\t\t\t", STDOUT_FILENO);
	putstr_fd("    #\n", STDOUT_FILENO);
	putstr_fd("#\t\t\t\t\t\t\t\t\t    #\n", STDOUT_FILENO);
	putstr_fd("#\t\tTry with Mandelbrot:\t\t\t\t\t", STDOUT_FILENO);
	putstr_fd("    #\n", STDOUT_FILENO);
	putstr_fd("#\t\t\t./fractol Mandelbrot\t\t\t\t", STDOUT_FILENO);
	putstr_fd("    #\n", STDOUT_FILENO);
	putstr_fd("#\t\t\t\t\t\t\t\t\t    #\n", STDOUT_FILENO);
	putstr_fd("#\t\tOr try with Julia:\t\t\t\t\t", STDOUT_FILENO);
	putstr_fd("    #\n", STDOUT_FILENO);
	putstr_fd("#\t\t\t./fractol Julia <nbr> <nbr> \t\t\t", STDOUT_FILENO);
	putstr_fd("    #\n", STDOUT_FILENO);
	putstr_fd("#\t\t\tJust numbers... not \"<>\"\t\t\t    #\n", STDOUT_FILENO);
	putstr_fd("#\t\t\t\t\t\t\t\t\t    #\n", STDOUT_FILENO);
	putstr_fd("#\t\t\t\t\t\t   (Case Sensitive... Duh?) #\n", STDOUT_FILENO);
	putstr_fd("#########################################", STDOUT_FILENO);
	putstr_fd("####################################", STDOUT_FILENO);
}
