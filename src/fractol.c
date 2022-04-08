/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:19:51 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/08 16:19:55 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// Need select_set function

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

void	init_img(t_fractol *f)
{
	int	 pixel_bits;
	int	 line_bytes;
	int	 endian;
	char	*buf;

	f->color_palette = malloc(sizeof(int) * MAX_ITERATIONS + 1);
	if (!(f->color_palette))
	{
		exit(msg("Error initializing color scheme.", "", 1));
	}
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!(f->img))
	{
		mlx_destroy_window(f->mlx, f->win);
		free(f->color_palette);
		exit(msg("image creation error.", "", 1));
	}
	buf = mlx_get_data_addr(f->img, &pixel_bits, &line_bytes, &endian);
	f->buf = buf;
	printf("pixels_per_bits = %d\n", pixel_bits);
}

void	init(t_fractol *f, char **av)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		exit_error(msg("MLX: error connecting to mlx.", "", 1));
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
	if (!f->win)
		exit_error(msg("MLX: error creating window.", "", 1));
	f->min_r = -2.0;
	f->max_r = 1.0;
	f->min_i = -1.5;
	f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	f->julia_toggle = 1;
	f->cr = -0.766667;
	f->ci = -0.090000;
	init_img(f);
	f->color_pattern = -1;
	color_shift(f);
}

int main(int ac, char **av)
{
	t_fractol f;

	if (ac < 2 || ac > 4)
	{
		help_msg();
		exit(0);
	}
	get_set(&f, av);
	get_colors(&f, ac, av);
	init(&f, av);
	render(&f);
	mlx_hook(f.win, EVENT_CLOSE_BTN, 0, end_fractol, &f);
	mlx_key_hook(f.win, key_event, &f);
	mlx_mouse_hook(f.win, mouse_event, &f);
	mlx_loop(f.mlx);
}
