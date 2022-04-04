#include "../../includes/fractol.h"

/*
    Z = Z * Z + c
*/
int burning_ship(t_fractol *f, double cr, double ci, int x, int y)
{
    int     n;
    double  zr;
    double  zi;
    double  tmp;

    zr = 0;
    zi = 0;
    n = 0;
    while (n < MAX_ITERATIONS)
    {
        if ((zr * zr + zi * zi) > 4.0)
            break;
        zr = fabs(zr);
        zi = fabs(zi);
        tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
        n++;
    }
    return (n);
}