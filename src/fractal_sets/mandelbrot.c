#include "../../includes/fractol.h"

/*
    The Mandelbrot formula is an iterative one:
    At every iteration, Z is squared.
        Z = Z * Z + c
    If the result tends toward infinity, that means it is not part of
    the set. If the result stays small over several iterations, the number
    is part of the set.
        ex.:
            c = 1
            Z = 0;
            Z =  0 *  0 + 1 = 1
            Z =  1 *  1 + 1 = 2
            Z =  2 *  2 + 1 = 5
            Z =  5 *  5 + 1 = 26
            Z = 26 * 26 + 1 = 677
            ... Grows to infinity.
            So 1 is NOT part of the Mandelbrot set.
    
        ex.2:
            c = -1
            Z = 0;
            Z =    0 *    0 + (-1) = -1
            Z = (-1) * (-1) + (-1) = 0
            Z =    0 *    0 + (-1) = -1
            ... Result oscillates between -1 and 0
            So -1 is part of the Mandelbrot set.

    Here we can't compute to infinity but it's safe to say that if the
    absolute value of Z goes above 2, it will tend toward infinity and
    the number won't be part of the Mandelbrot set.

    Since we are working with complex numbers, we need to calculate the
    real number Zr and the imaginary number Zi and evaluate both together.
    Multiplication of 2 complex numbers is complicated:
    (a + bi)2   = (a + bi) * (a + bi)
                = (a * a) + (a * bi) + (a * bi) + (bi * bi)
                = (a * a) - (bi * bi) + 2 * (a * bi)
    So the multiplication formula for the imaginary part is:
                    (a * a) - (b * b)
    And the multiplication formula for the real part is:
                    2 * a * bi

    See:    http://warp.povusers.org/Mandelbrot/
            https://www.mathsisfun.com/algebra/complex-number-multiply.html
*/

/* mandelbrot:
    Checks whether a point is part of the mandelbrot set or not.
    Takes as parameters the real and imaginary coordinates of a point,
    converted previously from a pixel's coordinates.
    Here we color any pixel which is part of the mandelbrot set.
*/
int mandelbrot(t_fractol *f, double cr, double ci, int x, int y)
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
        tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
        n++;
    }
    return (n);
}