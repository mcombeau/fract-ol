# include "../includes/fractol.h"

void    change_color(t_fractol *f)
{
    f->color = (f->color + 1) % 4;
    printf("Color scheme sould be %d/n", f->color);
    if (f->color == 0)
        set_color_opposites(f, 0xCCCC00);
    else if (f->color == 1)
        set_color_opposites(f, 0x9966FF);
    else if (f->color == 2)
        set_color_opposites(f, 0xFF6666);
    else if (f->color == 3)
        set_color_zebra(f, 0xFFFFFF);
}

void    set_color_random(t_fractol *f)
{
    int i;

    i = 0;
    while (i <= MAX_ITERATIONS)
    {
        f->colors[i] = rand();
        i++;
    }
    f->colors[MAX_ITERATIONS] = 0;
}

void    set_color_zebra(t_fractol *f, int color)
{
    int i;
    int r;
    int g;
    int b;

    if (color == 0x000000)
        color = 0x010101;
    if (color == 0xFFFFFF)
        color = 0xEEEEEE;
    r = (color >> 16) & 0xFF;
    g = (color >> 8) & 0xFF;
    b = (color >> 0) & 0xFF;
    i = -1;
    while (++i <= MAX_ITERATIONS)
    {
        r = 255 - (r++ % 255);
        g = 255 - (g++ % 255);
        b = 255 - (b++ % 255);
        f->colors[i] = 0xFF << 24 | r << 16 | g << 8 | b;
    }
    f->colors[MAX_ITERATIONS] = 0;
}

/* set_color_opposites:
    This set of colors repeat itself over and over, turning from
    one sharp color to the next. The colors are usually opposites on
    the color wheel. Does not work well with pure edge colors like
    yellow (FFFF00), red (FF0000) or blue (0000FF). 
    Cool starting colors are:
        0xFFFFFF: white, results in white/grey/black scheme
        0x9966FF: purple, recults in orange/green/purple scheme
        0x33FF33: green, results in purple/green scheme
        0xFF6666: red, results in red/bluegreen scheme
        0xCCCC00: yellow, results in yellow/blye scheme.
*/
void    set_color_opposites(t_fractol *f, int color)
{
    int i;
    int r;
    int g;
    int b;

    r = (color >> 16) & 0xFF;
    g = (color >> 8) & 0xFF;
    b = (color >> 0) & 0xFF;
    i = -1;
    while (++i <= MAX_ITERATIONS)
    {
        f->colors[i] = 0;
        r = r + (i % 255);
        g = g + (i % 255);
        b = b + (i % 255);
        f->colors[i] = 0xFF << 24 | r << 16 | g << 8 | b;
    }
    f->colors[MAX_ITERATIONS] = 0;
}

void    set_color_scheme(t_fractol *f, int r, int g, int b)
{
    int i;
    int c;

    i = -1;
    while (++i <= MAX_ITERATIONS)
    {
        c = (i * 255 / (MAX_ITERATIONS));
        f->colors[i] = 0;
        if (r)
            f->colors[i] += 256 * 256 * c;
        if (g)
            f->colors[i] += 256 * c;
        if (b)
            f->colors[i] += c;
    }
    f->colors[MAX_ITERATIONS] = 0;
}

/* set_pixel_color:
    Add a color to one pixel of the image map.
    Color int is in the form of 0xAARRGGBB, but stored from right
    to left. There are 8 bits encoding each color component,
    Alpha (Transparency), Red, Green and Blue.
    Bit shifting:
        - BB >> 0   (0x000000FF)
        - GG >> 8   (0x0000FF00)
        - RR >> 16  (0x00FF0000)
        - AA >> 24  (0xFF000000)
    There are 32 bits per pixel, and 8 bits per color channel.
*/
void    set_pixel_color(t_fractol *f, int x, int y, int color)
{
        f->buf[x * 4 + y * WIDTH * 4] = color;
	    f->buf[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
	    f->buf[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
	    f->buf[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
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
                nb_iter = mandelbrot(f, cr, ci);
            else if (f->set == JULIA)
                nb_iter = julia(f, cr, ci, f->cr, f->ci);
            else if (f->set == BURNING_SHIP)
                nb_iter = burning_ship(f, cr, ci);
            else if (f->set == TRICORN)
                nb_iter = tricorn(f, cr, ci);
            set_pixel_color(f, x, y, f->colors[nb_iter]);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}