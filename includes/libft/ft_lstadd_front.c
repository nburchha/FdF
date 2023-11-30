/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:26:37 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/14 11:17:38 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Adds the node ’new’ at the beginning of the list.
/// @param lst The address of a pointer to the first link of a list.
/// @param new The address of a pointer to the node to be added to the list.
void	ft_lstadd_front(t_node **lst, t_node *new)
{
	new->next = *lst;
	*lst = new;
}

// int	main(void)
// {
// 	t_node	*lst;
// 	t_node	*new;

// 	lst = ft_lstnew("hallo");
// 	new = ft_lstnew("tschuess");
// 	printf("%s\n", lst->content);
// 	ft_lstadd_front(&lst, new);
// 	printf("%s\n", lst->content);
// 	printf("%s\n", (lst->next)->content);
// 	free(new);
// 	return (0);
// }