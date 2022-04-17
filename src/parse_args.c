/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:20:37 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/17 16:45:06 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_colors(t_fractol *f, int ac, char **av)
{
	if (f->set == JULIA && (ac == 5 || ac == 6))
	{
		f->main_color = ft_atox_color(f, av[4]);
		if (ac == 6)
			f->second_color = ft_atox_color(f, av[5]);
		else
			f->second_color = f->main_color;
	}
	else if (f->set != JULIA && (ac == 3 || ac == 4))
	{
		f->main_color = ft_atox_color(f, av[2]);
		if (ac == 4)
			f->second_color = ft_atox_color(f, av[3]);
		else
			f->second_color = f->main_color;
	}
	if (ac == 2 || (f->set == JULIA && ac == 4))
	{
		f->main_color = 0x9966FF;
		f->second_color = f->main_color;
	}
	if (f->main_color == f->second_color)
		f->second_color = (f->main_color & 0x000000)
			| (~f->main_color & 0xFFFFFF);
}

int	skip_space_sign_0x(char *color)
{
	int	i;

	i = 0;
	while (ft_isspace(color[i]))
		i++;
	if (color[i] == '+')
		i++;
	if (color[i] == '0' && (color[i + 1]
			&& (color[i + 1] == 'x' || color[i] == 'X')))
		i = i + 2;
	return (i);
}

int	ft_atox_color(t_fractol *f, char *color)
{
	int	i;
	int	x;
	int	n;

	n = 0;
	i = 0;
	i = skip_space_sign_0x(color);
	x = 0;
	while (color[i] && ft_ishexdigit(color[i]))
	{
		if (ft_isdigit(color[i]))
			n = (n * 16) + (color[i] - '0');
		else
			n = (n * 16) + (ft_toupper(color[i]) - 'A' + 10);
		i++;
		x++;
	}
	if (x == 6 && !color[i])
		return (n);
	else
		clean_exit(msg(color, ": invalid hex color.\n", 1), f);
	return (-1);
}

int	skip_space_sign(char *str, int *is_neg)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*is_neg *= -1;
		i++;
	}
	return (i);
}

double	ft_atof(char *str, double nb)
{
	int		i;
	int		is_neg;
	double	div;

	div = 0.1;
	is_neg = 1;
	i = skip_space_sign(str, &is_neg);
	while (str[i] && ft_isdigit(str[i]) && str[i] != '.')
	{
		nb = (nb * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	if (!ft_isdigit(str[i]))
		return (-42);
	while (str[i] && ft_isdigit(str[i]))
	{
		nb = nb + ((str[i] - '0') * div);
		div *= 0.1;
		i++;
	}
	if (str[i] && !ft_isdigit(str[i]))
		return (-42);
	return (nb * is_neg);
}
