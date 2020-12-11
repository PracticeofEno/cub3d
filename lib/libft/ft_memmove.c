/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <k1990121@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 21:46:32 by sanghpar          #+#    #+#             */
/*   Updated: 2020/10/10 01:38:38 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char	*tmp;
	const char		*s;

	tmp = dest;
	s = src;
	if (dest <= src)
	{
		return (ft_memcpy(dest, src, count));
	}
	else
	{
		tmp = tmp + count;
		s = s + count;
		while (count--)
			*--tmp = *--s;
	}
	return (dest);
}
