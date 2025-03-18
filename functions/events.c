/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabierma <dabierma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:26:22 by dabierma          #+#    #+#             */
/*   Updated: 2025/03/18 11:14:18 by dabierma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_handler(int keycode, int x, int y, t_fractal *fractal)
{
	if (keycode == RIGHT_CLICK)
	{
		fractal->set_color += 1;
		fractal->set_color %= 5;
		color_range(fractal);
		render_fractal(fractal, 0);
	}
	zoom(keycode, (double)x, (double)y, fractal);
	return (1);
}

int	key_handler(int keycode, t_fractal *fractal)
{
	if (keycode == ARROW_UP)
		move(fractal, 0, -1);
	else if (keycode == ARROW_DOWN)
		move(fractal, 0, +1);
	else if (keycode == ARROW_LEFT)
		move(fractal, -1, 0);
	else if (keycode == ARROW_RIGHT)
		move(fractal, +1, 0);
	return (0);
}

int	esc_handler(int keycode, t_fractal *fractal)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(fractal->mlx, fractal->window);
		exit (0);
	}
	else
		return (1);
}

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx, fractal->window);
	exit (0);
}

void	move(t_fractal *fractal, double x, double y)
{
	double	distance_real;
	double	distance_imaginary;

	if (!fractal)
		return ;
	distance_real = (fractal->max_r - fractal->min_r);
	distance_imaginary = (fractal->max_i - fractal->min_i);
	fractal->max_r += distance_real * x * 0.03;
	fractal->min_r += distance_real * x * 0.03;
	fractal->max_i += distance_imaginary * y * 0.03;
	fractal->min_i += distance_imaginary * y * 0.03;
	render_fractal(fractal, 0);
}
