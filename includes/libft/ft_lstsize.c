/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:03:07 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/14 11:16:56 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Counts the number of nodes in a list.
/// @param lst The beginning of the list.
/// @return The length of the list
int	ft_lstsize(t_node *lst)
{
	int		i;
	t_node	*tmp;

	if (lst == NULL)
		return (0);
	tmp = lst;
	i = 1;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
