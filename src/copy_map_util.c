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
			if (map[i][j] == '0' || map[i][j] == '2' || map[i][j] == 'W'
			|| map[i][j] == 'E' || map[i][j] == 'N' || map[i][j] == 'S')
				if (uni_test(i, j, width, height) == -1)
					return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

void	copy_map(char **map, t_list *lst)
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
			map[i][j] = ((char *)lst->content)[j];
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
