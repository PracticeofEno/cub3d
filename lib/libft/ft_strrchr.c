/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <k1990121@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 02:22:16 by sanghpar          #+#    #+#             */
/*   Updated: 2020/10/05 03:22:33 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int n)
{
	int			i;
	const char	*last;

	i = 0;
	last = NULL;
	while (str[i])
	{
		if (str[i] == n)
		{
			last = str + i;
		}
		i++;
	}
	if (str[i] == n)
		return ((char *)(str + i));
	if (last != NULL)
		return ((char *)last);
	return ((char *)0);
}
