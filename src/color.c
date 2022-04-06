# include "../includes/fractol.h"


//Good mono colors : 0xCC6600 (orange), 0x00ff80 (green)

void    set_color_mono(t_fractol *f, int color)
{
    int i;
    int r;
    int g;
    int b;

    r = 0;
    g = 0;
    b = 0;
    i = 0;
    while (i <= (MAX_ITERATIONS / 2))
    {
        r += ((color >> 16) & 0xFF) / (MAX_ITERATIONS / 2);
        g += ((color >> 8) & 0xFF) / (MAX_ITERATIONS / 2);
        b += ((color >> 0) & 0xFF) / (MAX_ITERATIONS / 2);
        f->color_palette[i] = 0xFF << 24 | r << 16 | g << 8 | b;
        i++;
    }
    while (i <= MAX_ITERATIONS)
    {
        r += (0xFF - r) / MAX_ITERATIONS;
        g += (0xFF - g) / MAX_ITERATIONS;
        b += (0xFF - b) / MAX_ITERATIONS;
        f->color_palette[i] = 0xFF << 24 | r << 16 | g << 8 | b;
        i++;
    }
    f->color_palette[MAX_ITERATIONS] = 0;
}

void    set_color_zebra(t_fractol *f, int color)
{
    int i;
    int r;
    int g;
    int b;
    int op_color;

    op_color = (color & 0x000000) | (~color & 0xFFFFFF);
    i = 0;
    while (i <= MAX_ITERATIONS)
    {
        f->color_palette[i] = op_color;
        i = i + 2;
    }
    i = 1;
    while (i <= MAX_ITERATIONS)
    {
        f->color_palette[i] = color;
        i = i + 2;
    }
    f->color_palette[MAX_ITERATIONS] = 0;
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
        f->color_palette[i] = 0;
        r += i % 0xFF;
        g += i % 0xFF;
        b += i % 0xFF;
        f->color_palette[i] = 0xFF << 24 | r << 16 | g << 8 | b;
    }
    f->color_palette[MAX_ITERATIONS] = 0;
}

void    set_color_graphic(t_fractol *f, int color)
{
    int i;
    int r;
    int g;
    int b;

    
    r = (color >> 16) & 0xFF;
    g = (color >> 8) & 0xFF;
    b = (color >> 0) & 0xFF;
    i = -1;
    while (r < 0x33 || g < 0x33 || b < 0x33)
    {
        r ++;
        g ++;
        b ++;
    }
    while (++i <= MAX_ITERATIONS)
    {
        f->color_palette[i] = 0;
        r -= i % 0xFF;
        g -= i % 0xFF;
        b -= i % 0xFF;
        f->color_palette[i] = 0xFF << 24 | r << 16 | g << 8 | b;
    }
    f->color_palette[MAX_ITERATIONS] = 0;
}

void    color_shift(t_fractol *f)
{
    f->color_pattern = (f->color_pattern + 1) % 4;
    if (f->color_pattern == 0)
        set_color_mono(f, f->color);
    else if (f->color_pattern == 1)
        set_color_opposites(f, f->color);
    else if (f->color_pattern == 2)
        set_color_graphic(f, f->color);
    else if (f->color_pattern == 3)
        set_color_zebra(f, f->color);
}