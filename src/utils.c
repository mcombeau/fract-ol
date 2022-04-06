# include "../includes/fractol.h"

void    exit_error(int error_code)
{
    exit(error_code);
}

int    msg(char *str1, char *str2, int errno)
{
    ft_putstr_fd("Fractol: ", 2);
    ft_putstr_fd(str1, 2);
    ft_putendl_fd(str2, 2);
    return (errno);
}

void help_msg(void)
{
    ft_putendl_fd("\n+==========================================================+", 1);
    ft_putendl_fd("|                       FRACT-OL                           |", 1);
    ft_putendl_fd("+==========================================================+\n", 1);
    ft_putendl_fd("+==================  Available Fractals  ==================+", 1);
    ft_putendl_fd("Which fractal would you like to view?", 1);
    ft_putendl_fd("\tM - Mandelbrot", 1);
    ft_putendl_fd("\tJ - Julia", 1);
    ft_putendl_fd("\tB - Burning Ship", 1);
    ft_putendl_fd("\tT - Tricorn", 1);
    ft_putendl_fd("\e[36mUsage example: ./fractol M\e[0m", 1);
    ft_putendl_fd("\n+==================  Color Display  =======================+", 1);
    ft_putendl_fd("Pick a display color by providing a hexadecimal code.", 1);
    ft_putendl_fd("The hex color code must be formatted as RRGGBB. For example:", 1);
    ft_putendl_fd("\tWhite:\tFFFFFF\t\tBlack:\t000000", 1);
    ft_putendl_fd("\tRed:\tFF0000\t\tGreen:\t00FF00", 1);
    ft_putendl_fd("\tBlue:\t0000FF\t\tYellow:\tFFFF00", 1);
    ft_putendl_fd("Other interesting colors:", 1);
    ft_putendl_fd("\tPurple:\t9933FF\t\tOrange:\tCC6600", 1);
    ft_putendl_fd("\tPink:\tFF3399\t\tTurquoise: 00FF80\t", 1);
    ft_putendl_fd("\e[36mUsage example: ./fractol M 0066FF\e[0m", 1);
}

int    end_fractol(t_fractol *mlx)
{
    mlx_destroy_window(mlx->mlx, mlx->win);
    if (mlx->color_palette != NULL)
        free(mlx->color_palette);
    exit(msg("Closed.", "", 0));
}