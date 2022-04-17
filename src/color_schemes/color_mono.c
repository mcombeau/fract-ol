/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mono.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:06:13 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/17 17:07:52 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//Good mono colors : 0xCC6600 (orange), 0x00ff80 (green)
void	set_color_mono(t_fractol *f, int color)
{
	int		i;
	int		j;
	double	fraction;
	int		color1;
	int		color2;

	color1 = 0x000000;
	color2 = color;
	i = 0;
	while (i < MAX_ITERATIONS)
	{
		j = 0;
		while (j < MAX_ITERATIONS / 2)
		{
			fraction = (double)j / (MAX_ITERATIONS / 2);
			f->color_palette[i + j] = interpolate(color1, color2, fraction);
			j++;
		}
		color1 = color;
		color2 = 0xFFFFFF;
		i += j;
	}
	f->color_palette[MAX_ITERATIONS -1] = 0;
}