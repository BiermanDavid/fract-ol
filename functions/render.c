/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabierma <dabierma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:55:22 by dabierma          #+#    #+#             */
/*   Updated: 2025/03/18 01:32:44 by dabierma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	choose_fractal(t_fractal *fractal, double c_real, double c_yaginary)
{
	if (fractal->type == 1)
		return (mandelbrot(c_real, c_yaginary));
	// else if (fractal->type == 2)
	// 	return(julia(fractal, c_real, c_yaginary));
	return (1);
}

int	zoom(int keycode, double x, double y, t_fractal *fractal)
{
	double	axis_width;
	double	axis_height;
	double	zoom;

	if (keycode == WHEEL_UP)
		zoom = ZOOM;
	else if (keycode == WHEEL_DOWN)
		zoom = 1 / ZOOM;
	else
		return (1);
	axis_width = (fractal->max_r - fractal->min_r);
	axis_height = (fractal->max_i - fractal->min_i);
	fractal->mid_r = fractal->min_r + (double) x * axis_width / WIDTH;
	fractal->mid_i = fractal->min_i + (double) y * axis_height / HEIGHT;
	fractal->min_r = fractal->mid_r - (fabs(fractal->min_r - fractal->mid_r) / zoom);
	fractal->min_i = fractal->mid_i - (fabs(fractal->min_i - fractal->mid_i) / zoom);
	fractal->max_i = fractal->mid_i + (fabs(fractal->max_i - fractal->mid_i) / zoom);
	fractal->max_r = fractal->mid_r + (fabs(fractal->max_r - fractal->mid_r) / zoom);
	render_fractal(fractal, 0);
	return (0);
}

void	fill_pixels(t_fractal *fractal, int x, int y, int color)
{
	char	*dest;

	if (!fractal)
		return ;
	dest = fractal->address + (y * fractal->line_len + x * (fractal->bpp / 8));
	*(unsigned int *) dest = color;
}

void	render_fractal(t_fractal *fractal, int iteration)
{
	double	c_x;
	double	c_y;
	int		y;
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		c_x = fractal->min_r + x * (fractal->max_r - fractal->min_r) / WIDTH;
		y = 0;
		while (y < HEIGHT)
		{
			c_y = fractal->min_i + y * (fractal->max_i - fractal->min_i) / HEIGHT;
			iteration = choose_fractal(fractal, c_x, c_y);
			if (iteration == -1)
				fill_pixels(fractal, x, y, 0x00000000);
			else
				fill_pixels(fractal, x, y, fractal->palette[iteration]);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0, 0);
}
