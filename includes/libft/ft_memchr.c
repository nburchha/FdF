/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:19:20 by nburchha          #+#    #+#             */
/*   Updated: 2023/10/10 10:41:33 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		cc;
	const unsigned char	*cs;
	size_t				i;

	cc = (unsigned char) c;
	cs = (const unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (cs[i] == cc)
			return ((void *)(cs + i));
		i++;
	}
	return (NULL);
}
