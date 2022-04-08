/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:20:37 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/08 16:20:44 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fractol.h"

void	get_colors(t_fractol *f, int ac, char **av)
{
	if (ac == 3 || ac == 4)
	{
		f->main_color = get_color_arg(f, av[2]);
		if (ac == 4)
			f->second_color = get_color_arg(f, av[3]);
		else
			f->second_color = f->main_color;
	}
	if (ac == 2)
	{
		f->main_color = 0x9966FF;
		f->second_color = f->main_color;
	}
	if (f->main_color == f->second_color)
		f->second_color = (f->main_color & 0x000000) | (~f->main_color & 0xFFFFFF);
}

int	get_color_arg(t_fractol *f, char *color)
{
	int i;
	int x;
	int n;

	n = 0;
	i = 0;
	while (ft_isspace(color[i]))
		i++;
	if (color[i] == '+')
		i++;
	if (color[i] == '0' && (color[i + 1] && (color[i + 1] == 'x' || color[i] == 'X')))
		i = i + 2;
	x = 0;
	while(color[i] && ft_ishexdigit(color[i]))
	{
		if (ft_isdigit(color[i]))
			n = (n * 16) + (color[i] - '0');
		else
		{
			n = (n * 16) + (ft_toupper(color[i]) - 'A' + 10);
		}
		i++;
		x++;
	}
	if (x == 6 && !color[i])
		return (n);
	else
	{
		msg(color, ": invalid hex color.\n", 1);
		help_msg();
		exit(1);
	}
}
