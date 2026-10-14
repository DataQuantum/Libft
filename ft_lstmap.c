/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabbenit <pabbenit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:04:00 by pabbenit          #+#    #+#             */
/*   Updated: 2026/10/06 16:11:16 by pabbenit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*aux_lst;
	void	*newlst_content;

	if (!lst || !f || !del)
		return (NULL);
	aux_lst = NULL;
	while (lst != NULL)
	{
		newlst_content = f(lst->content);
		new_lst = ft_lstnew(newlst_content);
		if (!new_lst)
		{
			del(newlst_content);
			ft_lstclear(&aux_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&aux_lst, new_lst);
		lst = lst->next;
	}
	return (aux_lst);
}
