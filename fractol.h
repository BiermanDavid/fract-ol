/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabierma <dabierma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:54:58 by dabierma          #+#    #+#             */
/*   Updated: 2025/03/17 17:19:32 by dabierma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx/mlx.h"

#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"

#define WIDTH   800
#define HEIGHT  800

// Original Color Definitions
#define BLACK         0x000000
#define WHITE         0xFFFFFF
#define RED           0xFF0000
#define GREEN         0x00FF00
#define BLUE          0x0000FF
#define YELLOW        0xFFFF00
#define CYAN          0x00FFFF
#define MAGENTA       0xFF00FF

// Psychedelic Color Definitions
#define NEON_PURPLE   0xBF40BF
#define ELECTRIC_PINK 0xFF1493
#define LIME_GREEN    0x32CD32
#define VIBRANT_ORANGE 0xFFA500
#define AQUA_MARINE   0x7FFFD4

typedef struct s_complex
{
	//real
	double	x;
	//imaginary
	double	y;
}			t_complex;
typedef struct s_img
{
    void    *img_ptr;
    char    *pixels_ptr;
    int     bpp;
    int     endian;
    int     line_len;
}           t_img;

typedef struct s_fractal
{
    char    *name;
    //mlx
    void    *mlx_connection;
    void    *mlx_window;
    //image
    t_img   img;
    //hooks
	double	escape_value;
	int		iterations_definition;


}           t_fractal;

//string_utils.c
int     	ft_strncmp(char *s1, char *s2, int n);
void    	putstr_fd(char *str, int fd);
//int.c
void    	fractal_init(t_fractal *fractal);
//math_utils.c
t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z1, t_complex z2);
double		map(double unscaled_nbr, double new_min, double new_max, double old_min, double old_max);
//render.c
void		fractal_render(t_fractal *fractal);

#endif