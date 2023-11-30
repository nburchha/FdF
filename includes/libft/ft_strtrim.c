/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:10:45 by nburchha          #+#    #+#             */
/*   Updated: 2023/10/11 14:24:50 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief allocates a copy of s1 with chars from set removed from start + end
/// @param s1 string to be trimmed
/// @param set reference set of chars to be trimmed
/// @return trimmed string, or NULL if allocation fails
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start_index;
	size_t		end_index;

	if (!s1 || !set)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_strdup(""));
	start_index = 0;
	end_index = (size_t)ft_strlen(s1);
	while (ft_strchr(set, s1[start_index]) != NULL && s1[start_index])
		start_index++;
	while (ft_strchr(set, s1[end_index]) != NULL)
		end_index--;
	end_index++;
	if (start_index > end_index)
		return (NULL);
	return (ft_substr(s1, start_index, end_index - start_index));
}
