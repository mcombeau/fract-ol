#include "../../includes/fractol.h"

/*
    Z = Z * Z + c
*/
int    julia_shift(int x, int y, t_fractol *f)
{
    if (f->julia_toggle == 1)
    {
        f->cr = f->min_r + f->max_r * (double)x / WIDTH;
        f->ci = f->min_i + f->max_r * (double)y /HEIGHT;
    //    f->cr = -1.5 + 2.5 * (double)x / WIDTH;
    //    f->ci = -1 + 2 * (double)y / HEIGHT;
        printf("Julia: cr = %f, ci = %f\n", f->cr, f->ci);
        render(f);
    }
    return (0);
}

int julia(t_fractol *f, double zr, double zi, double cr, double ci)
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