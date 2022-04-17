/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:35:40 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/17 17:29:22 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_shift(t_fractol *f)
{
	f->color_pattern = (f->color_pattern + 1) % 8;
	reinit_img(f);
	if (f->color_pattern == 0)
		set_color_triad(f, f->main_color);
	else if (f->color_pattern == 1)
		set_color_mono(f, f->main_color);
	else if (f->color_pattern == 2)
		set_color_multiple(f, (int [4]){0x000000, f->main_color,
			f->second_color, 0xFFFFFF}, 4);
	else if (f->color_pattern == 3)
		set_color_zebra(f, f->main_color, f->second_color);
	else if (f->color_pattern == 4)
		set_color_contrasted(f, f->main_color);
	else if (f->color_pattern == 5)
		set_color_opposites(f, f->main_color);
	else if (f->color_pattern == 6)
		set_color_graphic(f, f->main_color);
	else if (f->color_pattern == 7)
		set_color_multiple(f, (int [8]){0xFF0000, 0xFF7F00, 0xFFFF00,
			0x00FF00, 0x0000FF, 0x4B0082, 0x9400D3, 0xFFFFFF}, 8);
}
