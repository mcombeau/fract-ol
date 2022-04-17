/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:19:51 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/17 16:24:00 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_set(t_fractol *f, char **av)
{
	if (av[1][0] == 'M' || av[1][0] == 'm' || av[1][0] == '1')
		f->set = MANDELBROT;
	else if (av[1][0] == 'J' || av[1][0] == 'j' || av[1][0] == '2')
		f->set = JULIA;
	else if (av[1][0] == 'B' || av[1][0] == 'b' || av[1][0] == '3')
		f->set = BURNING_SHIP;
	else if (av[1][0] == 'T' || av[1][0] == 't' || av[1][0] == '4')
		f->set = TRICORN;
	else if (av[1][0] == 'X' || av[1][0] == 'x' || av[1][0] == '5')
		f->set = MANDELBOX;
	else
	{
		help_msg();
		clean_exit(1, f);
	}
}

void	get_julia_starting_values(t_fractol *f, int ac, char **av)
{
	if (f->set != JULIA || ac == 2)
	{
		f->kr = -0.766667;
		f->ki = -0.090000;
		return ;
	}
	if (ac == 3)
		clean_exit(msg("error: ", "No second Julia value provided.", 1), f);
	if (!ft_strchr(av[2], '.'))
		clean_exit(msg(av[2], ": is not a valid Julia value.", 1), f);
	if (!ft_strchr(av[3], '.'))
		clean_exit(msg(av[3], ": is not a valid Julia value.", 1), f);
	f->kr = ft_atof(av[2]);
	f->ki = ft_atof(av[3]);
	if (f->kr > 2.0 || f->kr < -2.0)
		clean_exit(msg(av[2], ": is not a valid Julia value.", 1), f);
	if (f->ki >= 2.0 || f->ki <= -2.0)
		clean_exit(msg(av[3], ": is not a valid Julia value.", 1), f);
}

void	handle_args(t_fractol *f, int ac, char **av)
{
	get_set(f, av);
	get_julia_starting_values(f, ac, av);
	get_colors(f, ac, av);
}

int	main(int ac, char **av)
{
	t_fractol	f;

	if (ac < 2)
	{
		help_msg();
		clean_exit(1, NULL);
	}
	clean_init(&f);
	handle_args(&f, ac, av);
	init(&f);
	render(&f);
	print_controls();
	mlx_hook(f.win, EVENT_CLOSE_BTN, 0, end_fractol, &f);
	mlx_key_hook(f.win, key_event, &f);
	mlx_mouse_hook(f.win, mouse_event, &f);
	mlx_loop(f.mlx);
}
