/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 10:37:51 by sanghpar          #+#    #+#             */
/*   Updated: 2020/10/10 07:58:58 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			break ;
		if (s2[i] == 0x00 || s1[i] == 0x00)
			break ;
		i++;
	}
	if (s2[i] == s1[i])
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
