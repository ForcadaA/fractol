/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 18:25:43 by aforcada          #+#    #+#             */
/*   Updated: 2026/06/05 10:07:25 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
	void (*del)(void *))
{
	t_list	*new;
	t_list	*curr;
	t_list	*node;

	if (!lst)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	node = lst;
	while (node->next)
	{
		curr = ft_lstnew(f(node->next->content));
		if (!curr)
			return (ft_lstclear(&new, del), NULL);
		ft_lstadd_back(&new, curr);
		node = node->next;
	}
	return (new);
}
