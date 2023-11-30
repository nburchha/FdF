/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:19:29 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/29 15:28:11 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	read_chars(char **save_read, int fd);
static int	check_leftover_and_read(char **save_read, char **leftover, int fd);

char	*get_next_line(int fd)
{
	char		*save_read;
	static char	*leftover = NULL;
	int			chars_read;

	if (check_leftover_and_read(&save_read, &leftover, fd) == 1)
		return (free(save_read), NULL);
	chars_read = BUFFER_SIZE;
	while (ft_strchr2(save_read, '\n') == -1 && chars_read > 0)
	{
		chars_read = read_chars(&save_read, fd);
		if (chars_read == -1)
			return (NULL);
	}
	if (chars_read == 0 && ft_strlen2(save_read) == 0)
		return (NULL);
	else if (chars_read == 0)
		return (save_read);
	if (ft_strchr2(save_read, '\n') >= 0 && ft_strchr2(save_read, '\n') \
	!= ft_strlen2(save_read) - 1)
		leftover = ft_strjoin_free_s1(NULL, save_read + \
		ft_strchr2(save_read, '\n') + 1);
	save_read = ft_substr2(save_read, ft_strchr2(save_read, '\n') + 1);
	return (save_read);
}

static int	check_leftover_and_read(char **save_read, char **leftover, int fd)
{
	if (*leftover != NULL)
	{
		*save_read = ft_strjoin_free_s1(*leftover, NULL);
		*leftover = NULL;
	}
	else
		*save_read = NULL;
	if (read(fd, NULL, 0) == -1)
		return (1);
	return (0);
}

static int	read_chars(char **save_read, int fd)
{
	char		read_buf[BUFFER_SIZE + 1];
	int			count_read;

	count_read = read(fd, read_buf, BUFFER_SIZE);
	read_buf[count_read] = '\0';
	if (count_read <= 0)
	{
		if (*save_read != NULL && count_read == -1)
		{
			free(*save_read);
			*save_read = NULL;
		}
		return (count_read);
	}
	*save_read = ft_strjoin_free_s1(*save_read, read_buf);
	if (*save_read == NULL)
		return (-1);
	return (count_read);
}
