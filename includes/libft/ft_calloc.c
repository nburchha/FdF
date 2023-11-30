/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:30:16 by nburchha          #+#    #+#             */
/*   Updated: 2023/10/15 22:07:14 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief allocates and zeroes memory with size and count given
/// @return pointer to the allocated memory
void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	if (size && count * size > SIZE_MAX)
		return (NULL);
	s = malloc(count * size);
	if (s == NULL)
		return (NULL);
	return (ft_memset(s, 0, (int) size * count));
}
