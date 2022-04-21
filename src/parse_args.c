/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:20:37 by mcombeau          #+#    #+#             */
/*   Updated: 2022/04/21 21:52:52 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* skip_space_sign_0x:
*	Skips spaces, '+' sign character and '0x' or '0X'
*	to parse hexadecimal color code strings.
*/
static int	skip_space_sign_0x(char *color)
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

/* ft_atox_color:
*	Translates a hexadecimal color code string into an integer.
*	Valid: "RRGGBB", "0XRRGGBB", "rrggbb", "   +rrggbb"
*	Invalid: "-RRGGBB" "RRGGBB-", "RR GG BB"
*	If the string is not a valid hex color code, an error is displayed.
*	Returns the converted int. -1 if an error occured.
*/
static int	ft_atox_color(t_fractol *f, char *color)
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
		help_msg(f);
	return (-1);
}

/* get_color:
*	Gets the color option provided as argument at program launch.
*	If no color was specified, sets a default value to be used.
*/
void	get_color(t_fractol *f, int ac, char **av)
{
	if (f->set == JULIA && ac == 5)
		f->color = ft_atox_color(f, av[4]);
	else if (f->set != JULIA && ac == 3)
		f->color = ft_atox_color(f, av[2]);
	if (ac == 2 || (f->set == JULIA && ac == 4))
		f->color = 0x9966FF;
}

/* skip_space_sign:
*	Skips spaces, '+' and '-' sign characters and sets the
*	is_neg variable if a '-' sign is detected.
*	Used to parse strings representing float values for Julia.
*/
static int	skip_space_sign(char *str, int *is_neg)
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

/* ft_atof:
*	Converts a string into a float (decimal number). Used to parse
*	Julia starting values given as program arguments.
*	Returns the converted double, or -42 in case of error (Julia accepts
*	values between 2.0 and -2.0 only)
*/
double	ft_atof(char *str)
{
	int		i;
	double	nb;
	int		is_neg;
	double	div;

	nb = 0;
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
