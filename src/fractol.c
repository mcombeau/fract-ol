/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:19:51 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/12 14:44:38 by mcombeau         ###   ########.fr       */
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
	else
	{
		help_msg();
		exit(1);
	}
}



int	main(int ac, char **av)
{
	t_fractol	f;

	if (ac < 2 || ac > 4)
	{
		help_msg();
		exit(0);
	}
	clean_init(&f);
	get_set(&f, av);
	get_colors(&f, ac, av);
	init(&f, av);
	render(&f);
	mlx_hook(f.win, EVENT_CLOSE_BTN, 0, end_fractol, &f);
	mlx_key_hook(f.win, key_event, &f);
	mlx_mouse_hook(f.win, mouse_event, &f);
	mlx_loop(f.mlx);
}