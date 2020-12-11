/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 19:01:29 by sanghpar          #+#    #+#             */
/*   Updated: 2020/10/11 22:43:35 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmp2;
	void	*content;

	tmp = 0;
	if (!lst)
		return (tmp);
	while (lst)
	{
		if ((*f))
			content = (*f)(lst->content);
		else
			content = lst->content;
		tmp2 = ft_lstnew(content);
		if (!tmp2)
		{
			ft_lstclear(&tmp, del);
			return (0);
		}
		ft_lstadd_back(&tmp, tmp2);
		lst = lst->next;
	}
	return (tmp);
}
