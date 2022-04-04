
#include "../includes/fractol.h"

// Need select_set function

void    get_set(t_fractol *f, char **av)
{
    if (av[1][0] == 'M' || av[1][0] == 'm' || av[1][0] == '1')
        f->set = MANDELBROT;
    else if (av[1][0] == 'J' || av[1][0] == 'j' || av[1][0] == '2')
        f->set = JULIA;
    else if (av[1][0] == 'B' || av[1][0] == 'b' || av[1][0] == '3')
        f->set = BURNING_SHIP;
    else if (av[1][0] == 'T' || av[1][0] == 't' || av[1][0] == '4')
        f->set = TRICORN;
    else
    {
        help_msg();
        exit(1);
    }
}

void    init_img(t_fractol *f)
{
    int     pixel_bits;
    int     line_bytes;
    int     endian;
    char    *buf;

    f->color_scheme = malloc(sizeof(int) * MAX_ITERATIONS + 1);
    if (!(f->color_scheme))
    {
        exit(msg("Error initializing color scheme.", "", 1));
    }
    f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
    if (!(f->img))
    {
        mlx_destroy_window(f->mlx, f->win);
        free(f->color_scheme);
        exit(msg("image creation error.", "", 1));
    }
    buf = mlx_get_data_addr(f->img, &pixel_bits, &line_bytes, &endian);
    f->buf = buf;
}

void    init(t_fractol *f, char **av)
{
    get_set(f, av);
    f->mlx = mlx_init();
    if (!f->mlx)
        exit_error(msg("MLX: error connecting to mlx.", "", 1));
    f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
    if (!f->win)
        exit_error(msg("MLX: error creating window.", "", 1));
    f->min_r = -2.0;
    f->max_r = 1.0;
    f->min_i = -1.5;
    f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
    f->cr = 0.353;
    f->ci = 0.288;
    init_img(f);
    set_colors(f, 76, 0, 159);
}

int main(int ac, char **av)
{
    t_fractol f;

    if (ac != 2)
    {
        help_msg();
        exit(0);
    }
    init(&f, av);
    mlx_hook(f.win, EVENT_CLOSE_BTN, 0, end_fractol, &f);
    mlx_key_hook(f.win, key_event, &f);
    mlx_mouse_hook(f.win, mouse_event, &f);
    render(&f);
    mlx_loop(f.mlx);
}