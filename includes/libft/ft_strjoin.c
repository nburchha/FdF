/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:50:31 by nburchha          #+#    #+#             */
/*   Updated: 2023/10/15 22:46:39 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief allocates, returns new string which is concatenated s1 + s2
/// @param s1 prefix string
/// @param s2 suffix string
/// @return new string, NULL if the allocation fails
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	size_s3;

	size_s3 = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = ft_calloc(size_s3, sizeof(char));
	if (s3 == NULL)
		return (NULL);
	ft_strlcpy(s3, s1, size_s3);
	ft_strlcat(s3, s2, size_s3);
	return (s3);
}
