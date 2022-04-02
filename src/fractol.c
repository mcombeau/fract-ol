
#include "../includes/fractol.h"


int main(int ac, char **av)
{
    void    *mlx_ptr;
    void    *win_ptr;
    (void)ac;
    (void)av;
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 600, 300, "Test");
    mlx_pixel_put(mlx_ptr, win_ptr, 600/2, 300/2, 0xFFFFFF);
    mlx_loop(mlx_ptr);
    return (0);
}