/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 11:48:30 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/17 15:19:55 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
A Mandelbox is a box shaped 3d object with a fractal surface and like the Mandelbrot set,
a Mandelbox set is calculated by applying a formula repeatedly to every point in space.

The Mandelbrot equation is: z = z2 + c

The Mandelbox equation is: v = s * ballFold(r, f*boxFold(v)) + c
where:
– v: 3d point
– boxFold(v) means for each axis a:

if v[a] > 1 
    v[a] =  2 - v[a]
else if v[a] < -1
    v[a] = -2 - v[a]

- ballFold(r, v) means for v's magnitude m:

if m < r
    m = m/r^2
else if m < 1 
    m = 1/m^2	

The standard Mandelbox uses this formula with s=2, r=0.5 and f=1.
https://sites.google.com/site/mandelbox/what-is-a-mandelbox
*/

#include "fractol.h"

double box_fold(double v)
{
	if (v > 1)
		v = 2 - v;
	else if (v < -1)
		v = -2 - v;
	return (v);
}

double	ball_fold(double r, double m)
{
	if (m < r)
		m = m / (r * r);
	else if (m < 1)
		m = 1 / (m * m);
	return (m);
}

int	mandelbox(t_fractol *f, double cr, double ci)
{
	int n;
	double vr;
	double vi;
	double mag;

	vr = cr;
	vi = ci;
	mag = 0;
	n = 0;
	while (n < MAX_ITERATIONS)
	{		
		vr = f->fx * box_fold(vr);
		vi = f->fx * box_fold(vi);
		mag = sqrt(vr * vr + vi * vi);
        vr = vr * f->sx * ball_fold(f->rx, mag) + cr;
        vi = vi * f->sx * ball_fold(f->rx, mag) + ci;
		if (sqrt(mag) > 2)
			break;
		n++;
	}
	return (n);
}
