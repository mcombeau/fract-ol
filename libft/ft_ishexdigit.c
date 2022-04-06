/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:53:06 by mcombeau          #+#    #+#             */
/*   Updated: 2021/12/02 14:40:52 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
	DESCRIPTION :
	The function ft_ishexdigit checks whether c is a hexadecimal digit character or not.

	RETURN VALUE:
	Non-zero if c is a hexadecimal digit, zero if not.
*/
int	ft_ishexdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
    c = ft_toupper(c);
    if (c >= 'A' && c <= 'F')
        return (c);
    else
	    return (0);
}
