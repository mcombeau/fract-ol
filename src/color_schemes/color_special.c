/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_special.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:10:18 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/17 17:41:14 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* set_color_opposites:
	This set of colors repeat itself over and over, turning from
	one sharp color to the next. The colors are usually opposites on
	the color wheel. Does not work well with pure edge colors like
	yellow (FFFF00), red (FF0000) or blue (0000FF). 
	Cool starting colors are:
		0xFFFFFF: white, results in white/grey/black scheme
		0x9966FF: purple, recults in orange/green/purple scheme
		0x33FF33: green, results in purple/green scheme
		0xFF6666: red, results in red/bluegreen scheme
		0xCCCC00: yellow, results in yellow/blue scheme.
*/
/*
	Work on this function, gives weird results with edge cases like
		FF00FF FF0000 0000FF etc.
	Limit the F side, or modulo maybe.
*/
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

// rgb[3] : [0] = red, [1] = green, [2] = blue
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
