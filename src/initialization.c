/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:31:33 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/16 15:57:54 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clean_init(t_fractol *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->img = NULL;
	f->buf = NULL;
	f->set = -1;
	f->min_r = 0;
	f->max_r = 0;
	f->min_i = 0;
	f->max_i = 0;
	f->kr = 0;
	f->ki = 0;
	f->color_palette = NULL;
	f->color_pattern = -1;
	f->main_color = 0;
	f->second_color = 0;
}

void	get_orientation(t_fractol *f)
{
	if (f->set == BURNING_SHIP)
	{
		f->max_i = -1.5;
		f->min_i = f->max_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
	else
	{
		f->min_i = -1.5;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
}

void	init_img(t_fractol *f)
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buf;

	f->color_palette = malloc(sizeof(int) * MAX_ITERATIONS + 1);
	if (!(f->color_palette))
	{
		clean_exit(msg("Error initializing color scheme.", "", 1), f);
	}
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!(f->img))
	{
		mlx_destroy_window(f->mlx, f->win);
		free(f->color_palette);
		clean_exit(msg("image creation error.", "", 1), f);
	}
	buf = mlx_get_data_addr(f->img, &pixel_bits, &line_bytes, &endian);
	f->buf = buf;
}

void	init(t_fractol *f, char **av)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		clean_exit(msg("MLX: error connecting to mlx.", "", 1), f);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
	if (!f->win)
		clean_exit(msg("MLX: error creating window.", "", 1), f);
	f->min_r = -2.0;
	f->max_r = 1.0;
	get_orientation(f);
	init_img(f);
	f->color_pattern = -1;
	color_shift(f);
}