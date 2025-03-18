/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabierma <dabierma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:27:48 by dabierma          #+#    #+#             */
/*   Updated: 2025/03/18 01:05:51 by dabierma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/**
 * 0x000000, // Black
 * 0x1E90FF, // Dodger Blue
 * 0x32CD32, // Lime Green
 * 0xFFD700, // Gold
 * 0xFF4500, // Orange Red
 * 0x8A2BE2, // Blue Violet
 * 0xFFFFFF  // White
 */
void	color_range(t_fractal *fractal)
{
	int	palette[7];
	int	palette_size;
	int	index;

	palette[0] = 0x000000;
	palette[1] = 0x1E90FF;
	palette[2] = 0x32CD32;
	palette[3] = 0xFFD700;
	palette[4] = 0xFF4500;
	palette[5] = 0x8A2BE2;
	palette[6] = 0xFFFFFF;
	palette_size = sizeof(palette) / sizeof(int);
	index = 0;
	while (index < MAX_ITERATION)
	{
		fractal->palette[index] = palette[index % palette_size];
		index++;
	}
}
