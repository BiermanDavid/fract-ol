/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabierma <dabierma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:09:07 by dabierma          #+#    #+#             */
/*   Updated: 2025/03/17 16:54:59 by dabierma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unscaled_nbr, double new_min, double new_max, double old_min, double old_max)
{
	return(new_max - new_min) * (unscaled_nbr - old_min) / (old_max - old_min) + new_min;
}
t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;

	return(result);
}

// real = (x^2 - y^2)
// i = 2*x*y
t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return(result);	
}