/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:49:23 by nburchha          #+#    #+#             */
/*   Updated: 2023/10/11 13:43:37 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief allocates memory for a copy of string s1
/// @param s1 string that is copied
/// @return pointer to copy of s1, if allocation fails NULL
char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	i = ft_strlen(s1) + 1;
	s2 = malloc(i);
	if (s2 == NULL)
		return (NULL);
	ft_strlcpy(s2, s1, i);
	return (s2);
}
