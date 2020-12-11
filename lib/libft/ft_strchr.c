/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <k1990121@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 02:22:16 by sanghpar          #+#    #+#             */
/*   Updated: 2020/10/05 02:59:42 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int n)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == n)
		{
			return ((char *)(str + i));
		}
		i++;
	}
	if (str[i] == n)
		return ((char *)(str + i));
	return ((char *)0);
}
