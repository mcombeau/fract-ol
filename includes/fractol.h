/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:36:48 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/08 13:36:51 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <math.h>

/*  Dimensions    */
# define WIDTH 900
# define HEIGHT 900
# define MAX_ITERATIONS 80

/*  Fractal sets    */
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3
# define TRICORN 4

/*  Keycodes    */
# define EVENT_CLOSE_BTN 17
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_PLUS 61
# define KEY_MINUS 45
# define KEY_SPACE 32
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define MOUSE_WHEEL_BTN 3
# define MOUSE_BTN 1
# define MOUSE_BTN_2 3

typedef struct  s_fractol
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *buf;
    int     set;
    double  min_r;
    double  max_r;
    double  min_i;
    double  max_i;
    double  cr;
    double  ci;
    int     *color_palette;
    int     color_pattern;
    int     main_color;
    int     second_color;
    int     julia_toggle;
}   t_fractol;

/*  Sets   */
int mandelbrot(t_fractol *f, double cr, double ci);
int julia(t_fractol *f, double zr, double zi, double cr, double ci);
int burning_ship(t_fractol *f, double cr, double ci);
int tricorn(t_fractol *f, double cr, double ci);

/*  Draw    */
void    render(t_fractol *f);
void    color_shift(t_fractol *f);
void    set_color_opposites(t_fractol *f, int color);
void    set_color_zebra(t_fractol *f, int color, int color2);
void    set_color_mono(t_fractol *f, int color);
int    julia_shift(int x, int y, t_fractol *f);

/*  Events   */
int key_event(int keycode, t_fractol *mlx);
int mouse_event(int keycode, int x, int y, t_fractol *mlx);

/*  Utils   */
void    init_img(t_fractol *f);
void    get_colors(t_fractol *f, int ac, char **av);
int    get_color_arg(t_fractol *f, char *color);
int    end_fractol(t_fractol *mlx);
void    exit_error(int error_code);
int     msg(char *str1, char *str2, int errno);
void help_msg(void);

#endif
