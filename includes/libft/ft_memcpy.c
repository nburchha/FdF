/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:56:10 by nburchha          #+#    #+#             */
/*   Updated: 2023/10/10 13:49:53 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*casted_dst;
	char	*casted_src;

	if (!dst && !src)
		return (NULL);
	casted_dst = (char *)dst;
	casted_src = (char *)src;
	while (n > 0)
	{
		*casted_dst++ = *casted_src++;
		n--;
	}
	return (dst);
}
