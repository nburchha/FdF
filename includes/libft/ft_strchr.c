/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 09:58:22 by nburchha          #+#    #+#             */
/*   Updated: 2023/10/15 22:43:54 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief locates first occurence of c (converted to char) in string s
/// @param s string that is being searched
/// @param c character to search for, given in int
/// @return pointer to the first occurence of c in s. If there is none, NULL
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
	}
	if (s[i] == (unsigned char)c)
		return ((char *)s + i);
	return (NULL);
}
