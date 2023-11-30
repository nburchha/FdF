/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:03:17 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/23 14:03:30 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Takes as a parameter a node and frees the memory of the node’s
/// content using the function ’del’ given as a parameter and free the node.
/// The memory of ’next’ must not be freed.
/// @param lst The node to free.
/// @param del  The address of the function used to delete the content.
void	ft_lstdelone(t_node *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

// void freeList(t_node *head)
//{if (head) freeList((t_node *)head->next); free(head);}

// int main(void)
// {
// 	t_node * l =  ft_lstnew(malloc(1));
// 	ft_lstdelone(l, free); l = 0;
// 	if (!l)
// 		printf("%p", l);
// 	write(1, "\n", 1);
// 	return (0);
// }