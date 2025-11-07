/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:17:07 by abounoua          #+#    #+#             */
/*   Updated: 2025/11/07 17:26:41 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// TO DO : gerer les erreurs d'allocation avec del et free pour free ce qui a ete alloue jusqu'a maintenant
// Checker f et del

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;

	if (!lst)
		return (NULL);
	else
	{
		new_list = ft_lstnew((*f)(lst->content));
		lst = lst->next;
	}
	while (lst != NULL)
	{
		ft_lstadd_back(&new_list, (*f)(lst->content));
		lst = lst->next;
	}
	return (new_list);
}
