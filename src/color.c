/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:35:40 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/20 14:06:56 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* color_shift_special:
*	Extension of the color_shift function. Changes the color pattern.
*	The fractal can then be rendered again with different color
*	effects.
*/
static void	color_shift_special(t_fractol *f)
{
	int	alt_color;

	if (f->color == 0xFFFFFF)
		alt_color = 0xCCCCCC;
	else
		alt_color = f->color;
	if (f->color_pattern == 5)
		set_color_contrasted(f, alt_color);
	else if (f->color_pattern == 6)
		set_color_opposites(f, f->color);
	else if (f->color_pattern == 7)
		set_color_graphic(f, f->color);
	else if (f->color_pattern == 8)
		set_color_multiple(f, (int [8]){0xFF0000, 0xFF7F00, 0xFFFF00,
			0x00FF00, 0x0000FF, 0x4B0082, 0x9400D3, 0xFFFFFF}, 8);
}

/* color_shift_striped:
*	Extension of the color_shift function. Changes the color pattern.
*	The fractal can then be rendered again with different color
*	effects.
*/
static void	color_shift_striped(t_fractol *f)
{
	if (f->color_pattern == 2)
		set_color_zebra(f, f->color);
	else if (f->color_pattern == 3)
		set_color_triad(f, f->color);
	else if (f->color_pattern == 4)
		set_color_tetra(f, f->color);
	else
		color_shift_special(f);
}

/* color_shift:
*	Reinitializes the MLX image and changes the color pattern.
*	The fractal can then be rendered again with different color
*	effects.
*/
void	color_shift(t_fractol *f)
{
	int	alt_color;

	f->color_pattern = (f->color_pattern + 1) % 9;
	reinit_img(f);
	if (f->color == 0x000000)
		alt_color = 0x333333;
	else
		alt_color = f->color;
	if (f->color_pattern == 0)
		set_color_mono(f, alt_color);
	else if (f->color_pattern == 1)
		set_color_multiple(f, (int [4]){0x000000, alt_color,
			get_percent_color(f->color, 50), 0xFFFFFF}, 4);
	else
		color_shift_striped(f);
}
