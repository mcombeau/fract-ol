# include "../includes/fractol.h"

// Need color selection function

void    render(t_fractol *f)
{
    int x;
    int y;
    double  cr;
    double  ci;
    int nb_iter;

    mlx_clear_window(f->mlx, f->win);
    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            // Map pixel coordinate to real/imaginary point
            cr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
            ci = f->min_i + (double)y * (f->max_i - f->min_i) / HEIGHT;
            if (f->set == MANDELBROT)
                mandelbrot(f, cr, ci, x, y);
            else if (f->set == JULIA)
                julia(f, cr, ci, f->cr, f->ci, x, y);
            else if (f->set == BURNING_SHIP)
                burning_ship(f, cr, ci, x, y);
            else if (f->set == TRICORN)
                tricorn(f, cr, ci, x, y);
            x++;
        }
        y++;
    }
}