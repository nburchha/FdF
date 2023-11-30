/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:26:54 by nburchha          #+#    #+#             */
/*   Updated: 2023/10/15 22:42:01 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief counts how many pointers are needed in pointer array
static int	ft_count_words(const char *s, char delim)
{
	int				i;
	int				count;
	int				flag;

	i = 0;
	count = 0;
	flag = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != delim && (i == 0 || s[i - 1]) && flag == 0)
			flag = ++count;
		if (s[i] == delim && flag != 0)
			flag = 0;
		i++;
	}
	return (count);
}

/// @brief gets start point of string to be split,
/// determines end point by the next delim in s
/// @return splitted string
static char	*ft_make_split_str(const char *s, char delim, int *i)
{
	size_t	size;

	size = *i;
	while (s[*i] != delim && s[*i])
		*i += 1;
	*i -= 1;
	return (ft_substr(s, size, *i - size + 1));
}

/// @brief frees the 2d array in case of a allocation fail
void	*ft_free_split(char **result)
{
	int	i;

	i = 0;
	while (result[i] != NULL)
		free(result[i++]);
	free(result);
	return (NULL);
}

/// @brief Allocates (with malloc(3)) and returns an array
/// of strings obtained by splitting ’s’ using the
/// character ’c’ as a delimiter. The array must end
/// with a NULL pointer.
/// @param s The string to be split.
/// @param c The delimiter character.
/// @return The array of new strings resulting from the split.
/// NULL if the allocation fails.
char	**ft_split(char const *s, char c)
{
	int				word_count;
	char			**result;
	int				i;
	int				j;

	i = -1;
	j = 0;
	if (!s)
		return (NULL);
	word_count = ft_count_words(s, c);
	result = ft_calloc(word_count + 1, sizeof(char *));
	if (result == NULL)
		return (NULL);
	result[word_count] = NULL;
	while (s[++i] && j < word_count)
	{
		if (s[i] != c)
		{
			result[j++] = ft_make_split_str(s, c, &i);
			if (!result[j - 1])
				return (ft_free_split(result));
		}
	}
	return (result);
}
