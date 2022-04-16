/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:23:44 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/16 16:50:25 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include "keys.h"
# include <stdio.h>
# include <math.h>

/*  Dimensions	*/
# define WIDTH 900
# define HEIGHT 900
# define MAX_ITERATIONS 60

/*  Fractal sets	*/
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3
# define TRICORN 4

typedef struct  s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*buf;
	int	 set;
	double  min_r;
	double  max_r;
	double  min_i;
	double  max_i;
	double  kr;
	double  ki;
	int	 *color_palette;
	int	 color_pattern;
	int	 main_color;
	int	 second_color;
}   t_fractol;

/*  Sets   */
int mandelbrot(t_fractol *f, double cr, double ci);
int julia(t_fractol *f, double zr, double zi);
int burning_ship(t_fractol *f, double cr, double ci);
int tricorn(t_fractol *f, double cr, double ci);

/*  Draw	*/
void	render(t_fractol *f);
void	color_shift(t_fractol *f);
void	set_color_opposites(t_fractol *f, int color);
void	set_color_zebra(t_fractol *f, int color, int color2);
void	set_color_mono(t_fractol *f, int color);
int	julia_shift(int x, int y, t_fractol *f);
void	fill_color(t_fractol *f, int color, int stripe);
int get_percent_color(int color, double percent);
int interpolate(int startcolor, int endcolor, double fraction);

/*  Events   */
int key_event(int keycode, t_fractol *mlx);
int mouse_event(int keycode, int x, int y, t_fractol *mlx);

/* Initialization */
void	clean_init(t_fractol *f);
void	init_img(t_fractol *f);
void	reinit_img(t_fractol *f);
void	init(t_fractol *f, char **av);
void	get_orientation(t_fractol *f);

/*  Utils   */
void	get_colors(t_fractol *f, int ac, char **av);
int	ft_atox_color(t_fractol *f, char *color);
double	ft_atof(char *str);
int	end_fractol(t_fractol *mlx);
int	 msg(char *str1, char *str2, int errno);
void help_msg(void);
void	print_controls(void);
void	clean_exit(int error_code, t_fractol *f);

#endif
