/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabierma <dabierma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:55:22 by dabierma          #+#    #+#             */
/*   Updated: 2025/03/24 16:42:19 by dabierma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	choose_fractal(t_fractal *fract, double c_real, double c_imaginary)
{
	if (fract->type == 1)
		return (mandelbrot(c_real, c_imaginary));
	else if (fract->type == 2)
		return (julia(fract, c_real, c_imaginary));
	return (1);
}

int	zoom(int keycode, double x, double y, t_fractal *fract)
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
	axis_width = (fract->max_r - fract->min_r);
	axis_height = (fract->max_i - fract->min_i);
	fract->mid_r = fract->min_r + (double) x * axis_width / WIDTH;
	fract->mid_i = fract->min_i + (double) y * axis_height / HEIGHT;
	fract->min_r = fract->mid_r - (fabs(fract->min_r - fract->mid_r) / zoom);
	fract->min_i = fract->mid_i - (fabs(fract->min_i - fract->mid_i) / zoom);
	fract->max_i = fract->mid_i + (fabs(fract->max_i - fract->mid_i) / zoom);
	fract->max_r = fract->mid_r + (fabs(fract->max_r - fract->mid_r) / zoom);
	render_fractal(fract, 0);
	return (0);
}

void	fill_pixels(t_fractal *fract, int x, int y, int color)
{
	char	*dest;

	if (!fract)
		return ;
	dest = fract->address + (y * fract->line_len + x * (fract->bpp / 8));
	*(unsigned int *) dest = color;
}

void	render_fractal(t_fractal *fract, int iteration)
{
	double	c_x;
	double	c_y;
	int		y;
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		c_x = fract->min_r + x * (fract->max_r - fract->min_r) / WIDTH;
		y = 0;
		while (y < HEIGHT)
		{
			c_y = fract->min_i + y * (fract->max_i - fract->min_i) / HEIGHT;
			iteration = choose_fractal(fract, c_x, c_y);
			if (iteration == -1)
				fill_pixels(fract, x, y, 0x00000000);
			else
				fill_pixels(fract, x, y, fract->palette[iteration]);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fract->mlx, fract->window, fract->image, 0, 0);
}
