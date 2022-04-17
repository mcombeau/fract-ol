/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_interpolated.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:06:07 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/17 17:13:33 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Interpolation = (endValue - startValue) * stepNumber / lastStepNumber + startValue
int interpolate(int startcolor, int endcolor, double fraction)
{
	int start_r;
	int start_g;
	int start_b;
	int end_r;
	int end_g;
	int end_b;

	start_r = ((startcolor >> 16) & 0xFF);
	start_g = ((startcolor >> 8) & 0xFF);
	start_b = ((startcolor >> 0) & 0xFF);
	end_r = ((endcolor >> 16) & 0xFF);
	end_g = ((endcolor >> 8) & 0xFF);
	end_b = ((endcolor >> 0) & 0xFF);
	start_r = (end_r - start_r) * fraction + start_r;
	start_g = (end_g - start_g) * fraction + start_g;
	start_b = (end_b - start_b) * fraction +start_b;
	return (0xFF << 24 | start_r << 16 | start_g << 8 | start_b);
}

void	set_color_multiple(t_fractol *f, int colors[4], int n)
{
	int		i;
	int		j;
	int		x;
	double	fraction;

	i = 0;
	x = 0;
	while (i < MAX_ITERATIONS)
	{
		j = 0;
		while ((i + j) < MAX_ITERATIONS && j < (MAX_ITERATIONS / (n - 1)))
		{
			fraction = (double)j / (MAX_ITERATIONS / (n - 1));
			f->color_palette[i + j] = interpolate(colors[x], colors[x + 1], fraction);
			j++;
		}
		x++;
		i += j;
	}
	f->color_palette[MAX_ITERATIONS - 1] = 0;
}