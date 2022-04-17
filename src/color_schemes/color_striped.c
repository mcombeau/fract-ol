/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_striped.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:05:39 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/17 17:09:12 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
NOTES:

Complementary
A complementary color scheme is a two-color combination consisting of a base color (H0) and another color (H1) that is 180 degrees apart from H0 on the color wheel.
formula: H1 = |(H0 + 180 degrees) - 360 degrees|

Split Complementary
A split-complementary color scheme is a three-color combination that consists of a base color (H0) and two colors (H1 and H2) that are 150 degrees and 210 degrees apart from H0 respectively.
formula: H1 = |(H0 + 150 degrees) - 360 degrees|
formula: H2 = |(H0 + 210 degrees) - 360 degrees|

Triadic
This is a three-color combination that consists of a base color (H0) and two colors (H1 and H2) that are 120 degrees and 240 degrees apart from H0 respectively.
formula: H1 = |(H0 + 120 degrees) - 360 degrees|
formula: H2 = |(H0 + 240 degrees) - 360 degrees|

Tetradic
A four-color combination that consists of a base color (H0) and three colors (H1, H2, and H3) that are 90 degrees, 180 degrees, and 270 degrees apart from H0 respectively.
formula: H1 = |(H0 + 90 degrees) - 360 degrees|
formula: H2 = |(H0 + 180 degrees) - 360 degrees|
formula: H3 = |(H0 + 270 degrees) - 360 degrees|

Analagous
Analagous color schemes use a combination consisting of a base color (H0) and one or more adjacent colors (30 degrees apart) on the color wheel.
formula: H1 = |(H0 + 30 degrees) - 360 degrees|
formula: H2 = |(H0 + 60 degrees) - 360 degrees|
formula: H3 = |(H0 + 90 degrees) - 360 degrees|

*/
void	fill_color(t_fractol *f, int color, int stripe)
{
	int i;

	i = 0;
	while (i < MAX_ITERATIONS)
	{
		f->color_palette[i] = color;
		i += stripe;
	}
}

// Triad color 1 is 33% away from original color
// Triad color 2 is 66% away from original color
int get_percent_color(int color, double percent)
{
	int r;
	int g;
	int b;
	int tr;
	int tg;
	int tb;
	double percentage;
	
	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = (color >> 0) & 0xFF;
	percentage = (percent / 100) * 256;
	tr = (r + percentage) - 256;
	tg = (g + percentage) - 256;
	tb = (b + percentage) - 256;
	return (0xFF << 24 | tr << 16 | tg << 8 | tb);
}

void	set_color_zebra(t_fractol *f, int color, int color2)
{
	fill_color(f, color, 1);
	fill_color(f, color2, 2);
	f->color_palette[MAX_ITERATIONS - 1] = 0;
}

void	set_color_triad(t_fractol *f, int color)
{
	int		triad[2];

	triad[0] = get_percent_color(color, 33);
	triad[1] = get_percent_color(color, 66);
	fill_color(f, color, 1);
	fill_color(f, triad[0], 2);
	fill_color(f, triad[1], 3);
	f->color_palette[MAX_ITERATIONS - 1] = 0;
}