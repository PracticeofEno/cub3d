/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:25:19 by sanghpar          #+#    #+#             */
/*   Updated: 2020/10/10 07:20:43 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (lst == 0)
		return ((void *)0);
	tmp = lst;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	return (tmp2);
}
