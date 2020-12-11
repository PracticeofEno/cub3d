/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 22:11:06 by sanghpar          #+#    #+#             */
/*   Updated: 2020/10/10 08:10:03 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*joined;
	int		i;
	int		s1_len;
	int		s2_len;

	i = 0;
	if (s1 == 0 && s2 == 0)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1[i] == 0x00)
		return (ft_strdup(s2));
	else if (s2[i] == 0x00)
		return (ft_strdup(s1));
	if (!(joined = (char *)malloc((s1_len + s2_len + 1) * sizeof(char))))
		return (NULL);
	ft_strlcpy(joined, s1, s1_len + 1);
	ft_strlcat(joined + s1_len, s2, s2_len + 1);
	return (joined);
}
