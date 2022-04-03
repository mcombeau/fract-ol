
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
    else
    {
        help_msg();
        exit(1);
    }
}

void    init(t_fractol *f, char **av)
{
    get_set(f, av);
    f->min_r = -2.0;
    f->max_r = 1.0;
    f->min_i = -1.2;
    f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
    f->cr = 0.353;
    f->ci = 0.288;
//    f->min_i = -1.0 * HEIGHT / WIDTH;
//    f->max_i = 1.0 * HEIGHT / WIDTH;
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
    f.mlx = mlx_init();
    if (!f.mlx)
        exit_error(msg("MLX: error connecting to mlx.", "", 1));
    f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Fractol");
    if (!f.win)
        exit_error(msg("MLX: error creating window.", "", 1));
    mlx_hook(f.win, EVENT_CLOSE_BTN, 0, end_fractol, &f);
    mlx_key_hook(f.win, key_event, &f);
    mlx_mouse_hook(f.win, mouse_event, &f);
    render(&f);
    mlx_loop(f.mlx);
}