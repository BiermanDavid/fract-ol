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


}           t_fractal;

//string_utils.c
int     ft_strncmp(char *s1, char *s2, int n);
void    putstr_fd(char *str, int fd);
void    fractal_init(t_fractal *fractal);

#endif