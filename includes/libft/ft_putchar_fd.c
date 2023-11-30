/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:39:07 by nburchha          #+#    #+#             */
/*   Updated: 2023/10/12 15:43:05 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Outputs the character ’c’ to the given file
/// descriptor.
/// @param c The character to output.
/// @param fd The file descriptor on which to write.
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
