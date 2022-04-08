/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:37:44 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/08 13:37:46 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int tricorn(t_fractol *f, double cr, double ci)
{
    int     n;
    double  zr;
    double  zi;
    double  tmp;

    zr = cr;
    zi = ci;
    n = 0;
    while (n < MAX_ITERATIONS)
    {
        if ((zr * zr + zi * zi) > 4.0)
            break;
        tmp = zr * zr - zi * zi + cr;
        zi = -2 * zr * zi + ci;
        zr = tmp;
        n++;
    }
    return (n);
}
