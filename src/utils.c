/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:21:53 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/16 15:49:32 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	exit_error(int error_code)
{
	exit(error_code);
}

void	clean_exit(int error_code, t_fractol *f)
{
	if (f->color_palette)
	{
		printf("Freeing color palette.\n");
		free(f->color_palette);
	}
	if (f->img)
	{
		printf("Destroying image.\n");
		mlx_destroy_image(f->mlx, f->img);
	}
	if (f->win && f->mlx)
	{
		printf("Destroying window.\n");
		mlx_destroy_window(f->mlx, f->win);
	}
	if (f->mlx)
	{
		printf("Ending loop.\n");
		mlx_loop_end(f->mlx);
	}
	exit(error_code);
}

int	msg(char *str1, char *str2, int errno)
{
	ft_putstr_fd("Fractol: ", 2);
	ft_putstr_fd(str1, 2);
	ft_putendl_fd(str2, 2);
	return (errno);
}

void	print_fractol_options(void)
{
	ft_putendl_fd("+===============  Available Fractals  ===============+", 1);
	ft_putendl_fd("Which fractal would you like to view?", 1);
	ft_putendl_fd("\tM - Mandelbrot", 1);
	ft_putendl_fd("\tJ - Julia", 1);
	ft_putendl_fd("\tB - Burning Ship", 1);
	ft_putendl_fd("\tT - Tricorn", 1);
	ft_putendl_fd("\e[36mUsage example:\t./fractol <type>\n\t\t./fractol M\e[0m", 1);
	ft_putstr_fd("\nFor Julia, you may specify starting values for the\ninitial fractal shape. ", 1);
	ft_putendl_fd("Values must be between\n -2.0 and 2.0 and must contain a decimal point.", 1);
	ft_putendl_fd("\e[36mUsage example:\t./fractol J\n\t\t./fractol J 0.285 0.0\e[0m", 1);
	ft_putendl_fd("\n+===============  Color Display  ====================+", 1);
	ft_putendl_fd("Pick a display color by providing a hexadecimal code.", 1);
	ft_putendl_fd("The hex color code must be formatted as RRGGBB:", 1);
	ft_putendl_fd("\tWhite:\tFFFFFF\t\tBlack:\t000000", 1);
	ft_putendl_fd("\tRed:\tFF0000\t\tGreen:\t00FF00", 1);
	ft_putendl_fd("\tBlue:\t0000FF\t\tYellow:\tFFFF00", 1);
	ft_putendl_fd("Other interesting colors:", 1);
	ft_putendl_fd("\tPurple:\t9933FF\t\tOrange:\tCC6600", 1);
	ft_putendl_fd("\tPink:\tFF3399\t\tTurquoise: 00FF80\t", 1);
	ft_putstr_fd("\e[36mUsage example:\t", 1);
	ft_putendl_fd("./fractol <type> <primary_color> <secondary_color>", 1);
	ft_putendl_fd("\t\t./fractol M 0066FF\n\t\t./fractol M 0066FF 00FF00\e[0m", 1);
	ft_putendl_fd("\nFor Julia, you can only specify colors after\nthe starting values.", 1);
	ft_putendl_fd("\e[36mUsage example:\t./fractol J -0.8 0.156 00FFFF CC6600\e[0m", 1);
}

void	print_controls(void)
{
	ft_putendl_fd("\n+===============  Controls  =========================+", 1);
	ft_putendl_fd("WASD or arrow keys\tmove view.", 1);
	ft_putendl_fd("+/- or scroll wheel\tzoom in and out.", 1);
	ft_putendl_fd("Spacebar\t\tchange the color scheme.", 1);
	ft_putendl_fd("Click\t\t\tshift Julia set [Julia only].", 1);
	ft_putendl_fd("1, 2, 3, 4\t\tswitch fractals.", 1);
	ft_putendl_fd("ESC or close window\tquit fract-ol.", 1);
	ft_putendl_fd("+====================================================+\n", 1);
}

void	help_msg(void)
{
	ft_putendl_fd("\n+====================================================+", 1);
	ft_putendl_fd("|                     FRACT-OL                       |", 1);
	ft_putendl_fd("+====================================================+\n", 1);
	print_fractol_options();
}

int	end_fractol(t_fractol *mlx)
{
	clean_exit(0, mlx);
}
