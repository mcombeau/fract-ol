#include "../includes/fractol.h"

void    get_color_arg(t_fractol *f, char **av)
{
    int i;
    int x;
    int n;

    n = 0;
    i = 0;
    while (ft_isspace(av[2][i]))
        i++;
    if (av[2][i] == '+')
        i++;
    if (av[2][i] == '0' && (av[2][i +1] && (av[2][i + 1] == 'x' || av[2][i] == 'X')))
        i = i + 2;
    x = 0;
    while(av[2][i] && ft_ishexdigit(av[2][i]))
    {
        if (ft_isdigit(av[2][i]))
            n = (n * 16) + (av[2][i] - '0');
        else
        {
            n = (n * 16) + (ft_toupper(av[2][i]) - 'A' + 10);
        }
        i++;
        x++;
    }
    if (x == 6 && !av[2][i])
        f->color = n;
    else
    {
        msg(av[2], ": invalid hex color.\n", 1);
        help_msg();
        exit(1);
    }
}