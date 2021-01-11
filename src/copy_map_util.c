/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:11:10 by sanghpar          #+#    #+#             */
/*   Updated: 2021/01/04 14:11:12 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_valid_map(int width, int height)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (g_map[i][j] == '0' || g_map[i][j] == '2' || g_map[i][j] == 'W'
			|| g_map[i][j] == 'E' || g_map[i][j] == 'N' || g_map[i][j] == 'S')
				if (uni_test(i, j, width, height) == -1)
					return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

void	copy_map(char **g_map, t_list *lst)
{
	int i;
	int j;
	int length;

	i = 0;
	while (lst)
	{
		j = 0;
		length = ft_strlen((char*)lst->content);
		while (j < length)
		{
			g_map[i][j] = ((char *)lst->content)[j];
			j++;
		}
		i++;
		lst = lst->next;
	}
}

double	normalize_angle(double angle)
{
	angle = fmod(angle, (PI * 2));
	if (angle < 0)
		angle = (2 * PI) + angle;
	return (angle);
}

double	atan_angle(double angle)
{
	if (angle < 0)
		angle = angle * -1;
	else if (angle > 0)
		angle = (2 * PI) - angle;
	return (angle);
}
