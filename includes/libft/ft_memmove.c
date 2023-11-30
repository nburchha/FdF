/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:29:59 by nburchha          #+#    #+#             */
/*   Updated: 2023/10/15 22:36:23 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief copy len bytes from src to dst, handling overlapping
/// @param dst pointer to destination area
/// @param src pointer to source area
/// @param len amount of bytes to move
/// @return pointer to destination
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*casted_dst;
	const unsigned char	*casted_src;

	casted_dst = (unsigned char *)dst;
	casted_src = (const unsigned char *)src;
	if (!dst && !src)
		return (dst);
	if (src > dst)
		ft_memcpy(dst, src, len);
	else
	{
		while (len--)
			casted_dst[len] = casted_src[len];
	}
	return (dst);
}
