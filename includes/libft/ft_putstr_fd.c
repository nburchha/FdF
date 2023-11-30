/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:43:44 by nburchha          #+#    #+#             */
/*   Updated: 2023/10/12 15:52:06 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Outputs the string ’s’ to the given file descriptor.
/// @param s The string to output.
/// @param fd The file descriptor on which to write.
void	ft_putstr_fd(char *s, int fd)
{
	while (*s != '\0')
		ft_putchar_fd(*s++, fd);
}
