/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:10:21 by nburchha          #+#    #+#             */
/*   Updated: 2023/10/15 22:50:27 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Applies the function ’f’ to each character of the
/// string ’s’, and passing its index as first argument
/// to create a new string (with malloc(3)) resulting
/// from successive applications of ’f’.
/// @param s The string on which to iterate, 
/// @param f The function to apply to each character
/// @return The string created from the successive applications of ’f’.
/// Returns NULL if the allocation fails.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*cs;
	char	*result;

	i = 0;
	if (!s)
		return (NULL);
	cs = (char *)s;
	result = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!result)
		return (NULL);
	while (s[i])
	{
		result[i] = f(i, cs[i]);
		i++;
	}
	return (result);
}
