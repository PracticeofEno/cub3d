/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 22:12:40 by sanghpar          #+#    #+#             */
/*   Updated: 2020/10/07 11:40:45 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_sep(char c, char sep)
{
	if (sep == c)
		return (true);
	return (false);
}

int		count_array(char *str, char sep)
{
	int		i;
	bool	flag;
	int		count;

	flag = true;
	count = 0;
	i = 0;
	while (str[i])
	{
		if (is_sep(str[i], sep))
		{
			flag = true;
		}
		else
		{
			if (flag)
			{
				count++;
				flag = false;
			}
		}
		i++;
	}
	return (count);
}

char	*create_arr(char *str, char sep, int *ip)
{
	int		i;
	char	*arr;

	arr = (void *)0;
	i = 0;
	while (str[i] != 0x00)
	{
		if (is_sep(str[i], sep))
			break ;
		i++;
	}
	arr = (char *)malloc((i + 1) * sizeof(char));
	i = 0;
	while (str[i] != 0x00)
	{
		if (is_sep(str[i], sep))
			break ;
		arr[i] = str[i];
		i++;
	}
	*ip = i;
	arr[i] = 0x00;
	return (arr);
}

char	**ft_split(char *str, char charset)
{
	int		size_count;
	char	*r_arr;
	int		index;
	char	**p_arr;

	size_count = count_array(str, charset);
	index = 0;
	p_arr = (char**)malloc((size_count + 1) * sizeof(char *));
	if (p_arr == NULL)
		return (NULL);
	p_arr[size_count] = (void*)0;
	while (*str)
	{
		if (*str == charset)
			str++;
		else
		{
			size_count = 0;
			r_arr = create_arr(str, charset, &size_count);
			str = str + size_count;
			if (r_arr)
				p_arr[index++] = r_arr;
		}
	}
	return (p_arr);
}
