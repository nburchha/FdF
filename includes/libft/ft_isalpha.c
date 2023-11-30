/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:34:27 by nburchha          #+#    #+#             */
/*   Updated: 2023/10/15 20:45:30 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief alphabetic char test
/// @return 1 if alphabetic char as input, 0 if not alphabetic
int	ft_isalpha(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

// capital letters 65 <= x <= 90
// lower case letters 97 <= x <= 122