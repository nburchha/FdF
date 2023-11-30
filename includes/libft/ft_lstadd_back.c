/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:16:35 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/14 11:17:43 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Adds the node ’new’ at the end of the list
/// @param lst The address of a pointer to the first link of a list.
/// @param new The address of a pointer to the node to be added to the list.
void	ft_lstadd_back(t_node **lst, t_node *new)
{
	if (*lst == NULL)
		ft_lstadd_front(lst, new);
	else
		ft_lstlast(*lst)->next = new;
}
