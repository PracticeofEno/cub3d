/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <k1990121@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 07:49:43 by sanghpar          #+#    #+#             */
/*   Updated: 2020/10/10 01:35:56 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;

	i = 0;
	if (!dest && !src)
	{
		return (NULL);
	}
	while (n > 0)
	{
		((char *)dest)[i] = ((const char *)src)[i];
		i++;
		n--;
	}
	return (dest);
}
