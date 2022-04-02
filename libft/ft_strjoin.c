/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:18:15 by mcombeau          #+#    #+#             */
/*   Updated: 2021/12/06 15:09:40 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_strjoin concatenates the given strings s1 and s2
	and allocates sufficient memory for the newly created string.

	RETURN VALUE :
	A pointer to the new concatenated string.
	NULL if the memory allocation fails.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	len;
	int		i;

	len = ft_strlen(s1) + ft_strlen(s2);
	s = ft_calloc(len + 1, sizeof(char));
	if (!s)
		return (NULL);
	len = 0;
	while (s1[len])
	{
		s[len] = s1[len];
		len++;
	}
	i = 0;
	while (s2[i])
	{
		s[len + i] = s2[i];
		i++;
	}
	return (s);
}
