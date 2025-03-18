/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabierma <dabierma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:09:07 by dabierma          #+#    #+#             */
/*   Updated: 2025/03/18 01:17:56 by dabierma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	define_bounds(t_fractal *fractal)
{
	if (!fractal)
		return ;
	if (fractal->type == 2)
	{
		fractal->max_r = 1.5;
		fractal->min_r = -1.5;
		fractal->min_i = -1.5;
	}
	else
	{
		fractal->max_r = 1;
		fractal->min_r = -1.9;
		fractal->min_i = -1.4;
	}
	fractal->max_i += (fractal->max_r - fractal->min_r) * HEIGHT / WIDTH;
	color_range(fractal);
}
/**
 * Mandelbrot Formula:
 * Complex nbr: c = c_real + i * c_imaginary
 * Check if complex number stays within bounds or escapes
 * updated iteratively in loop.
 */
int	mandelbrot(double c_real, double c_imaginary)
{
	int		n;
	double	z_real;
	double	z_imaginary;
	double	temp;

	n = 0;
	z_real = 0;
	z_imaginary = 0;
	while (n < MAX_ITERATION)
	{
		if (z_real * z_real + z_imaginary + z_imaginary > 4)
			return (n);
		temp = z_real;
		z_real = z_real * z_real - z_imaginary * z_imaginary + c_real;
		z_imaginary = 2 * temp * z_imaginary + c_imaginary;
		n++;
	}
	return (-1);
}
