/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_special.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:10:18 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/17 17:12:47 by mcombeau         ###   ########.fr       */
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
		f->color_palette[i] = 0;
		r += i % 0xFF;
		g += i % 0xFF;
		b += i % 0xFF;
		f->color_palette[i] = 0xFF << 24 | r << 16 | g << 8 | b;
	}
	f->color_palette[MAX_ITERATIONS - 1] = 0;
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
		f->color_palette[i] = 0;
		if (r != 0xFF)
			r += i % 0xFF;
		if (g != 0xFF)
			g += i % 0xFF;
		if (b != 0xFF)
			b += i % 0xFF;
		f->color_palette[i] = 0xFF << 24 | r << 16 | g << 8 | b;
	}
	f->color_palette[MAX_ITERATIONS - 1] = 0;
}

void	set_color_graphic(t_fractol *f, int color)
{
	int	i;
	int	r;
	int	g;
	int	b;

	
	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = (color >> 0) & 0xFF;
	i = -1;
	while (r < 0x33 || g < 0x33 || b < 0x33)
	{
		if (r != 0xFF)
			r++;
		if (g != 0xFF)
			g++;
		if (b != 0xFF)
			b++;
	}
	while (++i < MAX_ITERATIONS)
	{
		f->color_palette[i] = 0;
		r -= i % 0xFF;
		g -= i % 0xFF;
		b -= i % 0xFF;
		f->color_palette[i] = 0xFF << 24 | r << 16 | g << 8 | b;
	}
	f->color_palette[MAX_ITERATIONS - 1] = 0;
}