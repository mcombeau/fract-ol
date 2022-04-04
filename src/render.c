# include "../includes/fractol.h"

void    set_colors(t_fractol *f, int r, int g, int b)
{
    int i;
    int c;

    i = -1;
    while (++i <= MAX_ITERATIONS)
    {
        c = (i * 255 / (MAX_ITERATIONS));
        f->color_scheme[i] = 0;
        if (r)
            f->color_scheme[i] += 256 * 256 * c;
        if (g)
            f->color_scheme[i] += 256 * c;
        if (b)
            f->color_scheme[i] += c;
    }
    f->color_scheme[MAX_ITERATIONS] = 0;
}

void    set_pixel(t_fractol *f, int x, int y, int color)
{
    f->buf[x * 4 + WIDTH * y * 4] = color;
	f->buf[x * 4 + WIDTH * y * 4 + 1] = color >> 8;
	f->buf[x * 4 + WIDTH * y * 4 + 2] = color >> 16;
	f->buf[x * 4 + WIDTH * y * 4 + 3] = color >> 24;
}

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
                nb_iter = mandelbrot(f, cr, ci, x, y);
            else if (f->set == JULIA)
                nb_iter = julia(f, cr, ci, f->cr, f->ci, x, y);
            else if (f->set == BURNING_SHIP)
                nb_iter = burning_ship(f, cr, ci, x, y);
            else if (f->set == TRICORN)
                nb_iter = tricorn(f, cr, ci, x, y);
            set_pixel(f, x, y, f->color_scheme[nb_iter]);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}