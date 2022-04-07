# include "../includes/fractol.h"


// Interpolation = (endValue - startValue) * stepNumber / lastStepNumber + startValue
int interpolate(int startcolor, int endcolor, double fraction)
{
    int start_r;
    int start_g;
    int start_b;
    int end_r;
    int end_g;
    int end_b;

    start_r = ((startcolor >> 16) & 0xFF);
    start_g = ((startcolor >> 8) & 0xFF);
    start_b = ((startcolor >> 0) & 0xFF);
    end_r = ((endcolor >> 16) & 0xFF);
    end_g = ((endcolor >> 8) & 0xFF);
    end_b = ((endcolor >> 0) & 0xFF);
    start_r = (end_r - start_r) * fraction + start_r;
    start_g = (end_g - start_g) * fraction + start_g;
    start_b = (end_b - start_b) * fraction +start_b;
    return (0xFF << 24 | start_r << 16 | start_g << 8 | start_b);
}

//Good mono colors : 0xCC6600 (orange), 0x00ff80 (green)
void    set_color_mono(t_fractol *f, int color)
{
    int i;
    int j;
    double fraction;
    int color1;
    int color2;

    color1 = 0x000000;
    color2 = color;
    i = 0;
    while (i < MAX_ITERATIONS)
    {
        j = 0;
        while (j < MAX_ITERATIONS / 2)
        {
            fraction = (double)j / (MAX_ITERATIONS / 2);
            f->color_palette[i + j] = interpolate(color1, color2, fraction);
            j++;
        }
        color1 = color;
        color2 = 0xFFFFFF;
        i += j;
    }
    f->color_palette[MAX_ITERATIONS] = 0;
}

void    set_color_multiple(t_fractol *f, int colors[4], int n)
{
    int i;
    int j;
    int x;
    double fraction;

    i = 0;
    x = 0;
    while (i <= MAX_ITERATIONS)
    {
        j = 0;
        while ((i + j) <= MAX_ITERATIONS && j < (MAX_ITERATIONS / (n - 1)))
        {
            fraction = (double)j / (MAX_ITERATIONS / (n - 1));
            f->color_palette[i + j] = interpolate(colors[x], colors[x + 1], fraction);
            j++;
        }
        x++;
        i += j;
    }
    f->color_palette[MAX_ITERATIONS] = 0;
}

// Triad color 1 is 33% away from original color
// Triad color 2 is 66% away from original color
int get_percent_color(int color, double percent)
{
    int r;
    int g;
    int b;
    int tr;
    int tg;
    int tb;
    double percentage;
    
    printf("Get triad...\n");
    r = (color >> 16) & 0xFF;
    g = (color >> 8) & 0xFF;
    b = (color >> 0) & 0xFF;
    printf("\tColor r = %x, g = %x, b = %x\n", r, g, b);
    percentage = (percent / 100) * 256;
    printf("\tPercent = %f\n", percent);
    printf("\tPercentage = %f\n", percentage);
    tr = (r + percentage) - 256;
    tg = (g + percentage) - 256;
    tb = (b + percentage) - 256;
    printf("\tr + percentage = %x\n\tg + percentage = %x\n\tb + percentage = %x\n", tr, tg, tb);
    return (0xFF << 24 | tr << 16 | tg << 8 | tb);
}

void    fill_color(t_fractol *f, int color, int stripe)
{
    int i;

    i = 0;
    while (i < MAX_ITERATIONS)
    {
        f->color_palette[i] = color;
        i += stripe;
    }
}

void    set_color_zebra(t_fractol *f, int color, int color2)
{
    fill_color(f, color, 1);
    fill_color(f, color2, 2);
    f->color_palette[MAX_ITERATIONS] = 0;
}

void    set_color_triad(t_fractol *f, int color)
{
    int i;
    int triad[2];

    triad[0] = get_percent_color(color, 33);
    triad[1] = get_percent_color(color, 66);
    printf("Color =\t%#.6x\nTriad 1 =\t%#.6x\nTriad 2 =\t%#.6x\n", color, triad[0], triad[1]);
    fill_color(f, color, 1);
    fill_color(f, triad[0], 2);
    fill_color(f, triad[1], 3);
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
        0xCCCC00: yellow, results in yellow/blue scheme.
*/
/*
    Work on this function, gives weird results with edge cases like
        FF00FF FF0000 0000FF etc.
    Limit the F side, or modulo maybe.
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

void    set_color_contrasted(t_fractol *f, int color)
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
        if (r != 0xFF)
            r += i % 0xFF;
        if (g != 0xFF)
            g += i % 0xFF;
        if (b != 0xFF)
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
        if (r != 0xFF)
            r++;
        if (g != 0xFF)
            g++;
        if (b != 0xFF)
            b++;
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
    f->color_pattern = (f->color_pattern + 1) % 8;
    if (f->color_pattern == 0)
        set_color_triad(f, f->main_color);
    else if (f->color_pattern == 1)
        set_color_mono(f, f->main_color);
    else if (f->color_pattern == 2)
        set_color_multiple(f, (int[4]){0x000000, f->main_color, f->second_color, 0xFFFFFF}, 4);
    else if (f->color_pattern == 3)
        set_color_zebra(f, f->main_color, f->second_color);
    else if (f->color_pattern == 4)
        set_color_contrasted(f, f->main_color);
    else if (f->color_pattern == 5)
        set_color_opposites(f, f->main_color);
    else if (f->color_pattern == 6)
        set_color_graphic(f, f->main_color);
    else if (f->color_pattern == 7)
        set_color_multiple(f, (int[8]){0xFF0000, 0xFF7F00, 0xFFFF00, 
                                        0x00FF00, 0x0000FF, 0x4B0082, 
                                        0x9400D3, 0xFFFFFF}, 8);
}