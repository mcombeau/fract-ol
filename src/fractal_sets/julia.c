#include "../../includes/fractol.h"

/*
    Z = Z * Z + c
*/
int julia(t_fractol *f, double zr, double zi, double cr, double ci, int x, int y)
{
    int     i;
    int     is_in_set;
    double  tmp;

    is_in_set = 1;
    i = 0;
    while (i < MAX_ITERATIONS)
    {
        if ((zr * zr + zi * zi) > 4.0)
        {
            is_in_set = 0;
            break;
        }
        tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
        i++;
    }
    if (is_in_set)
        mlx_pixel_put(f->mlx, f->win, x, y, 0x9E114B);
    return (i);
}