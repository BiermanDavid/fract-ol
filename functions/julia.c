/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabierma <dabierma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 01:37:21 by dabierma          #+#    #+#             */
/*   Updated: 2025/03/24 16:41:04 by dabierma         ###   ########.fr       */
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
