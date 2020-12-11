/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 00:09:54 by sanghpar          #+#    #+#             */
/*   Updated: 2020/10/08 01:06:45 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*tmp;

	i = 0;
	if (s && f)
	{
		if (!(tmp = (char *)malloc((ft_strlen(s) + 1) * sizeof(char))))
			return (NULL);
		tmp[ft_strlen(s)] = 0x00;
		while (s[i])
		{
			tmp[i] = (*f)(i, s[i]);
			i++;
		}
		return (tmp);
	}
	return (NULL);
}
