/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:35:51 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/08 13:35:58 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fractol.h"

void    zoom(t_fractol *f, double zoom)
{
    double	center_r;
	double	center_i;

	center_r = f->min_r - f->max_r;
	center_i = f->max_i - f->min_i;
	f->max_r = f->max_r + (center_r - zoom * center_r) / 2;
	f->min_r = f->max_r + zoom * center_r;
	f->min_i = f->min_i + (center_i - zoom * center_i) / 2;
	f->max_i = f->min_i + zoom * center_i;
}

void    move(t_fractol *f, double distance, char direction)
{
    double	center_r;
	double	center_i;

	center_r = f->max_r - f->min_r;
	center_i = f->max_i - f->min_i;
	if (direction == 'R')
	{
		f->min_r += center_r * distance;
		f->max_r += center_r * distance;
	}
	else if (direction == 'L')
	{
		f->min_r -= center_r * distance;
		f->max_r -= center_r * distance;
	}
	else if (direction == 'D')
	{
		f->min_i += center_i * distance;
		f->max_i += center_i * distance;
	}
	else if (direction == 'U')
	{
		f->min_i -= center_i * distance;
		f->max_i -= center_i * distance;
	}
}

int key_event(int keycode, t_fractol *mlx)
{
/*   char *keycode_str;

   keycode_str = ft_itoa(keycode);
   ft_putendl_fd(keycode_str, 2);
   free(keycode_str);
*/    if (keycode == KEY_ESC)
    {
        end_fractol(mlx);
        return (0);
    }
    else if (keycode == KEY_PLUS)
        zoom(mlx, 0.5);
    else if (keycode == KEY_MINUS)
        zoom(mlx, 2);
    else if (keycode == KEY_UP || keycode == KEY_W)
        move(mlx, 0.2, 'U');
    else if (keycode == KEY_DOWN || keycode == KEY_S)
        move(mlx, 0.2, 'D');
    else if (keycode == KEY_LEFT || keycode == KEY_A)
        move(mlx, 0.2, 'L');
    else if (keycode == KEY_RIGHT || keycode == KEY_D)
        move(mlx, 0.2, 'R');
    else if (keycode == KEY_SPACE)
        color_shift(mlx);
    else
        return (0);
    render(mlx);
    return (0);
}

int mouse_event(int keycode, int x, int y, t_fractol *mlx)
{
/*    char *keycode_str;

    keycode_str = ft_itoa(keycode);
    ft_putendl_fd(keycode_str, 2);
    free(keycode_str);
*/    if (keycode == MOUSE_WHEEL_UP)
    {
        zoom(mlx, 0.5);
        x -= WIDTH / 2;
        y -= HEIGHT /2;
        if (x < 0)
            move(mlx, (double)x * -1 / WIDTH, 'L');
        else if (x > 0)
            move(mlx, (double)x / WIDTH, 'R');
        if (y < 0)
            move(mlx, (double)y * -1 / HEIGHT, 'U');
        else if (y > 0)
            move (mlx, (double)y / HEIGHT, 'D');
    }
    else if (keycode == MOUSE_WHEEL_DOWN)
        zoom(mlx, 2);
    else if (keycode == MOUSE_BTN)
    {
        if (mlx->set == JULIA)
            julia_shift(x, y, mlx);
/*        if (mlx->julia_toggle == 1)
            mlx->julia_toggle = 0;
        else
            mlx->julia_toggle = 1;
*/    }
    else
        return(0);
    render(mlx);
    return(0);
}
