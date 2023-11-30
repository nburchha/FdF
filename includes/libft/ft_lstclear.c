/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:56:29 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/20 19:56:13 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Deletes and frees the given node and every successor of that node,
/// using the function ’del’ and free(3). Finally, the pointer to the list must
/// be set to NULL.
/// @param lst The address of a pointer to a node.
/// @param del The address of the function used to delete the content of the
/// node.
void	ft_lstclear(t_node **lst, void (*del)(void *))
{
	t_node	*tmp;

	if (!*lst)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst);
		(*lst) = (*lst)->next;
		ft_lstdelone(tmp, del);
	}
}

// int	main(void)
// {
// 	t_node	*lst;

// 	lst = ft_lstnew(ft_strdup("1.node"));
// 	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("2.node")));
// 	printf("%s\n", (lst->next)->content);
// 	ft_lstclear(&lst, free);
// 	return (0);
// }