/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:55:04 by nburchha          #+#    #+#             */
/*   Updated: 2023/10/15 22:38:24 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rec_putnbr(unsigned int n, int fd)
{
	if (n >= 10)
		ft_rec_putnbr(n / 10, fd);
	ft_putchar_fd((char)((n % 10) + '0'), fd);
}

/// @brief Outputs the integer ’n’ to the given file descriptor.
/// @param n The integer to output
/// @param fd  The file descriptor on which to write.
void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	u_n;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		u_n = (unsigned int)(n * -1);
	}
	else
		u_n = (unsigned int) n;
	ft_rec_putnbr(u_n, fd);
}
