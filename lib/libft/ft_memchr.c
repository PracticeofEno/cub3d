/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <k1990121@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 08:26:45 by sanghpar          #+#    #+#             */
/*   Updated: 2020/10/06 21:53:24 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *mem, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		if (((char *)mem)[i] == c)
		{
			return ((void *)mem + i);
		}
		i++;
	}
	return (0);
}
