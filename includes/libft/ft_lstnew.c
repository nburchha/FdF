/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:49:40 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/14 11:16:44 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Allocates (with malloc(3)) and returns a new node.
/// The member variable ’content’ is initialized with
/// the value of the parameter ’content’. The variable
/// ’next’ is initialized to NULL.
/// @param content The content to create the node with
/// @return The new node
t_node	*ft_lstnew(void *content)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

// int	main(void)
// {
// 	int	i;
// 	t_node *lst;

// 	i = 2;
// 	lst = ft_lstnew("hallo");
// 	printf("%s", lst->content);
// 	free(lst);
// 	return (0);
// }