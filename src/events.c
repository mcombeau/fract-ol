# include "../includes/fractol.h"

int key_event(int keycode, t_fractol *mlx)
{
    char *keycode_str;

    keycode_str = ft_itoa(keycode);
    ft_putendl_fd(keycode_str, 2);
    free(keycode_str);
    if (keycode == KEY_ESC)
    {
        end_fractol(mlx);
        return (0);
    }
}

int mouse_event(int keycode, int x, int y, t_fractol *mlx)
{
//    ft_putendl_fd("Click.", 2);
    return(0);
}