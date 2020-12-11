/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 23:04:50 by sanghpar          #+#    #+#             */
/*   Updated: 2020/10/10 06:43:57 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	int		i;
	size_t	len;

	if (dest == NULL || src == NULL)
		return (0);
	len = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (size > 1 && src[i] != 0x00)
		{
			dest[i] = src[i];
			i++;
			size--;
		}
		dest[i] = 0x00;
	}
	return (len);
}
