/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 02:48:27 by sanghpar          #+#    #+#             */
/*   Updated: 2020/10/12 01:58:17 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char	*)malloc((len + 1) * sizeof(char));
	if (!tmp || s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	tmp[len] = 0x00;
	while (len && s[start])
	{
		tmp[i] = s[start];
		i++;
		start++;
		len--;
	}
	return (tmp);
}
