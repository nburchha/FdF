/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:36:20 by nburchha          #+#    #+#             */
/*   Updated: 2023/10/18 17:00:45 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief tests wether n is < 0 and assigns positive value of n to unsigned int
/// @return 0 if n is positive, 1 if n is negative
int	ft_handle_negative(int	*ptr_n, unsigned int *ptr_u_n)
{
	if (*ptr_n < 0)
	{
		*ptr_u_n = (unsigned int)(*ptr_n * -1);
		return (1);
	}
	*ptr_u_n = *ptr_n;
	return (0);
}

/// @brief divides n i times by 10 to count how many digits n has
int	ft_count_digits(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

/// @brief Allocates (with malloc(3)) and returns a string
/// representing the integer received as an argument.
/// Negative numbers are handled.
/// @param n the integer to convert
/// @return the string representing the integer, NULL if the allocation fails
char	*ft_itoa(int n)
{
	int				negative;
	char			*result;
	int				nbr_len;
	int				i;
	unsigned int	u_n;

	nbr_len = 0;
	negative = ft_handle_negative(&n, &u_n);
	if (negative == 1)
		nbr_len++;
	nbr_len += ft_count_digits(u_n);
	result = ft_calloc(nbr_len + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	if (negative == 1)
		result[0] = '-';
	i = nbr_len - 1;
	while (i >= 0)
	{
		result[i--] = (char)(u_n % 10) + '0';
		u_n /= 10;
		if (u_n == 0)
			i = -1;
	}
	return (result);
}
