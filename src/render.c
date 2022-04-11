/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:21:20 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/11 15:37:26 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"


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
void	set_pixel_color(t_fractol *f, int x, int y, int color)
{
		f->buf[x * 4 + y * WIDTH * 4] = color;
		f->buf[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
		f->buf[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
		f->buf[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}

void	render(t_fractol *f)
{
	int		x;
	int		y;
	double	pr;
	double	pi;
	int		nb_iter;

	mlx_clear_window(f->mlx, f->win);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			// Map pixel coordinate to real/imaginary point
			pr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
			pi = f->min_i + (double)y * (f->max_i - f->min_i) / HEIGHT;
			if (f->set == MANDELBROT)
				nb_iter = mandelbrot(f, pr, pi);
			else if (f->set == JULIA)
				nb_iter = julia(f, pr, pi);
			else if (f->set == BURNING_SHIP)
				nb_iter = burning_ship(f, pr, pi);
			else if (f->set == TRICORN)
				nb_iter = tricorn(f, pr, pi);
			set_pixel_color(f, x, y, f->color_palette[nb_iter]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
