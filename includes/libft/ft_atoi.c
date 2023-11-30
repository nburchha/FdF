/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 00:44:20 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/30 15:03:07 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief iterates thru the whitespaces, 
/// @param str 
/// @param ptr_i 
/// @return 1 if number will be positive, -1 if its going to be negative,
/// 0 if the input is not convertible ("-+1214", "- 123")
static int	ft_handle_whitespace(const char *str, int	*ptr_i)
{
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (ft_isdigit(str[i]) != 1)
		sign = 0;
	*ptr_i = i;
	return (sign);
}

int	ft_atoi(const char *str)
{
	int	number;
	int	i;
	int	sign;

	number = 0;
	i = 0;
	sign = ft_handle_whitespace(str, &i);
	while (ft_isdigit(str[i]) == 1)
		number = number * 10 + str[i++] - '0';
	number *= sign;
	return (number);
}

int	ft_atoi_hex(const char *str)
{
	int	number;
	int	i;

	number = 0;
	i = 0;
	while (str[i])
	{
		number *= 16;
		if (str[i] >= '0' && str[i] <= '9')
			number += str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			number += str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			number += str[i] - 'A' + 10;
		i++;
	}
	return (number);
}

