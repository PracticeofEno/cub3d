/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 03:11:09 by sanghpar          #+#    #+#             */
/*   Updated: 2020/10/09 22:48:00 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_left(const char *s, const char *delset)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (ft_strchr(delset, s[i]) == (char *)0)
			break ;
		i++;
	}
	return (i);
}

static int	get_right(const char *s, const char *delset)
{
	int i;

	i = ft_strlen(s) - 1;
	while (i)
	{
		if (ft_strchr(delset, s[i]) == (char *)0)
			break ;
		i--;
	}
	return (i);
}

char		*ft_strtrim(const char *s, const char *delset)
{
	char	*tmp;
	size_t	i;
	size_t	left;
	size_t	right;

	left = get_left(s, delset);
	if (left == ft_strlen(s))
		return ((char *)ft_calloc(1, 1));
	right = get_right(s, delset);
	i = ft_strlen(s) - 1 - right;
	tmp = ft_substr(s, left, ft_strlen(s) - left - i);
	return (tmp);
}
