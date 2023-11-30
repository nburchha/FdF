/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:11:03 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/14 11:17:04 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief creates and allocates new node. if the allocation fails it returns
/// 0 and deletes content
/// @return node or NULL, if allocation fails
static t_node	*ft_lstnewdel(void *content, void (*del)(void *))
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
	{
		del(content);
		return (NULL);
	}
	node->content = content;
	node->next = NULL;
	return (node);
}

/// @brief Iterates the list ’lst’ and applies the function ’f’ on the content
/// of each node. Creates a new list resulting of the successive applications
/// of the function ’f’. The ’del’ function is used to delete the content of a
/// node if needed
/// @param lst The address of a pointer to a node.
/// @param f The address of the function used to iterate on the list.
/// @param del  The address of the function used to delete the content of a
/// node if needed.
/// @return The new list. NULL if the allocation fails.
t_node	*ft_lstmap(t_node *lst, void *(*f)(void *), void (*del)(void *))
{
	t_node	*new;
	t_node	*tmp;

	new = NULL;
	if (lst)
	{
		tmp = ft_lstnewdel(f(lst->content), del);
		if (!tmp)
			return (NULL);
		new = tmp;
		while (lst->next != NULL)
		{
			lst = lst->next;
			tmp->next = ft_lstnewdel(f(lst->content), del);
			if (!tmp->next)
			{
				ft_lstclear(&new, del);
				return (NULL);
			}
			tmp = tmp->next;
		}
	}
	return (new);
}
