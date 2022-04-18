/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_special.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:10:18 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/18 15:44:55 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Notice: These color scheme functions were created purely by accident,
	and may not always work well with every color provided. They rely on
	pushing past FFFFFF or 000000 which can have some unpredictable results.
	
	When they do work, they	create very interesting and beautiful
	colorings, though, which is why they have not been cut from this
	project.

	Typically, they work well with middling colors, especially ones like:
		9966FF	33FF33	FF6666	CCCC00	CC6600
	
	But they don't work too well with edge colors like:
		000000	FFFFFF	00FF00	FF0000	0000FF	FFFF00
*/

#include "fractol.h"

void	set_color_opposites(t_fractol *f, int color)
{
	int	i;
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = (color >> 0) & 0xFF;
	i = -1;
	while (++i < MAX_ITERATIONS)
	{
		f->palette[i] = 0;
		r += i % 0xFF;
		g += i % 0xFF;
		b += i % 0xFF;
		f->palette[i] = 0xFF << 24 | r << 16 | g << 8 | b;
	}
	f->palette[MAX_ITERATIONS - 1] = 0;
}

void	set_color_contrasted(t_fractol *f, int color)
{
	int	i;
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = (color >> 0) & 0xFF;
	i = -1;
	while (++i < MAX_ITERATIONS)
	{
		f->palette[i] = 0;
		if (r != 0xFF)
			r += i % 0xFF;
		if (g != 0xFF)
			g += i % 0xFF;
		if (b != 0xFF)
			b += i % 0xFF;
		f->palette[i] = 0xFF << 24 | r << 16 | g << 8 | b;
	}
	f->palette[MAX_ITERATIONS - 1] = 0;
}

void	set_color_graphic(t_fractol *f, int color)
{
	int	i;
	int	rgb[3];

	rgb[0] = (color >> 16) & 0xFF;
	rgb[1] = (color >> 8) & 0xFF;
	rgb[2] = (color >> 0) & 0xFF;
	i = -1;
	while (rgb[0] < 0x33 || rgb[1] < 0x33 || rgb[2] < 0x33)
	{
		if (rgb[0] != 0xFF)
			rgb[0]++;
		if (rgb[1] != 0xFF)
			rgb[1]++;
		if (rgb[2] != 0xFF)
			rgb[2]++;
	}
	while (++i < MAX_ITERATIONS)
	{
		f->palette[i] = 0;
		rgb[0] -= i % 0xFF;
		rgb[1] -= i % 0xFF;
		rgb[2] -= i % 0xFF;
		f->palette[i] = 0xFF << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2];
	}
	f->palette[MAX_ITERATIONS - 1] = 0;
}
