#include "../../includes/fractol.h"

int tricorn(t_fractol *f, double cr, double ci, int x, int y)
{
    int     n;
    int     is_in_set;
    double  zr;
    double  zi;
    double  tmp;

    zr = cr;
    zi = ci;
    is_in_set = 1;
    n = 0;
    while (n < MAX_ITERATIONS)
    {
        if ((zr * zr + zi * zi) > 4.0)
        {
            is_in_set = 0;
            break;
        }
        tmp = zr * zr - zi * zi + cr;
        zi = -2 * zr * zi + ci;
        zr = tmp;
        n++;
    }
    if (is_in_set)
        mlx_pixel_put(f->mlx, f->win, x, y, 0x9E114B);
    return (n);
}