/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabierma <dabierma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 01:37:21 by dabierma          #+#    #+#             */
/*   Updated: 2025/03/21 21:59:22 by dabierma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_fractal *fractal, double z_re, double z_im)
{
	int		n;
	double	temp;
	double	c_re;
	double	c_im;

	n = 0;
	c_re = fractal->julia_x;
	c_im = fractal->julia_y;
	while (n < MAX_ITERATION)
	{
		if (z_re * z_re + z_im * z_im > 4)
			return (n);
		temp = z_re * z_re - z_im * z_im + c_re;
		z_im = 2 * z_re * z_im + c_im;
		z_re = temp;
		n++;
	}
	return (-1);
}

void	julia_setup(t_fractal *fractal, double c[2])
{
	if (fractal->type == 2)
	{
		c[0] = fractal->julia_x;
		c[1] = fractal->julia_y;
	}
	else if (fractal->type == 1)
	{
		c[0] = -0.8;
		c[1] = 0.156;
	}
	else if (fractal->type == 3)
	{
		c[0] = -0.9;
		c[1] = 0.029;
	}
}
