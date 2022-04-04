#include "../../includes/fractol.h"

/*
    Z = Z * Z + c
*/
int julia(t_fractol *f, double zr, double zi, double cr, double ci, int x, int y)
{
    int     n;
    double  tmp;

    n = 0;
    while (n < MAX_ITERATIONS)
    {
        if ((zr * zr + zi * zi) > 4.0)
            break;
        tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
        n++;
    }
    return (n);
}