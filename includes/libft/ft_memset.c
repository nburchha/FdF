/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:44:23 by nburchha          #+#    #+#             */
/*   Updated: 2023/10/08 13:57:39 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	given_char;

	i = 0;
	given_char = (unsigned char) c;
	while (i < len)
	{
		((char *)b)[i] = given_char;
		i++;
	}
	return (b);
}
