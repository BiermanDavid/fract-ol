/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabierma <dabierma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:55:22 by dabierma          #+#    #+#             */
/*   Updated: 2025/03/17 17:28:41 by dabierma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void my_pixel_put(int x, int y, t_img *img, int color)
{
	int offset;
	offset = (y * img->line_len) + (x * img->bpp / 8);
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			iterator;
	int			color;

	iterator = 0;

	// first iteration
	z.x = 0.0;
	z.y = 0.0;

	//mandelbrot fill within -2 on x axis and +2 on y axis.
	c.x = map(x, -2, +2, 0, WIDTH);
	c.y = map(y, +2, -2, 0, HEIGHT);

	//iterate zsquare + c to see if point is out of boundss
	while(iterator < fractal->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(iterator, BLACK, WHITE, 0, fractal->iterations_definition);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++iterator;
	}
	my_pixel_put(x, y, &fractal->img, MAGENTA);	
}

void	fractal_render(t_fractal *fractal)
{
	int x;
	int y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection,
							fractal->mlx_window,
							fractal->img.img_ptr,
							0, 0);
}