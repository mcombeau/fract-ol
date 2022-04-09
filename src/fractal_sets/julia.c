/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:37:34 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/09 14:50:18 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
    Z = Z * Z + c
*/
int	julia_shift(int x, int y, t_fractol *f)
{
	f->cr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
	f->ci = f->min_i + (double)y * (f->max_i - f->min_i) / HEIGHT;
	printf("Julia: cr = %f, ci = %f\n", f->cr, f->ci);
	render(f);
	return (0);
}

int	julia(t_fractol *f, double zr, double zi, double cr, double ci)
{
	int		n;
	double	tmp;

	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		n++;
	}
	return (n);
}
