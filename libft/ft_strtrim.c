/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:51:42 by mcombeau          #+#    #+#             */
/*   Updated: 2021/12/03 16:21:52 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_strtrim removes any characters of the given set from
	the beginning and end of the given string s1, and allocates sufficient
	memory to store the trimmed copy of the string.

	RETURN VALUE :
	A pointer to the trimmed copy of the string.
	NULL if the memory allocation fails.
*/

static int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1)
		return (ft_strdup(""));
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (is_set(s1[start], set))
		start++;
	if (start == end)
		return (ft_strdup(""));
	while (is_set(s1[end - 1], set))
		end--;
	return (ft_substr(s1, start, end - start));
}
