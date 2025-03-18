/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabierma <dabierma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:54:58 by dabierma          #+#    #+#             */
/*   Updated: 2025/03/18 01:27:07 by dabierma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../mlx/mlx.h"

# define WIDTH   800
# define HEIGHT  800
# define MAX_ITERATION 80
# define ZOOM 1.1618
# define ESC 53
# define RIGHT_CLICK 2
# define WHEEL_UP 5
# define WHEEL_DOWN 4
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_RIGHT 124
# define ARROW_LEFT 123

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	char	*address;
	int		bpp;
	int		line_len;
	int		endian;
	int		set_color;
	int		type;
	int		init_frame;
	double	max_r;
	double	min_r;
	double	min_i;
	double	max_i;
	double	mid_i;
	double	mid_r;
	int		julia;
	int		palette[80];
}			t_fractal;

// main.c
void		handle_arguments(t_fractal *fractal, int argc, char **argv);
void		input_error(t_fractal **fractal);
// string_utils.c Handles argument inputs and prints error messages.
int			ft_strncmp(char *s1, char *s2, int n);
void		putstr_fd(char *str, int fd);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
// init.c
void		initialize_graphic_environment(char **argv, t_fractal *fractal);
void		its_not_that_hard(void);
// mandelbrot.c
void		define_bounds(t_fractal *fractal);
int			mandelbrot(double c_real, double c_imaginary);
// render.c
void		render_fractal(t_fractal *fractal, int iteration);
void		fill_pixels(t_fractal *fractal, int x, int y, int color);
int			zoom(int keycode, double x, double y, t_fractal *fractal);
// keypress hooks/events
int			mouse_handler(int keycode, int x, int y, t_fractal *fractal);
int			key_handler(int keysym, t_fractal *fractal);
int			esc_handler(int keycode, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
void		move(t_fractal *fractal, double x, double y);
//colors
void		color_range(t_fractal *fractal);

#endif
