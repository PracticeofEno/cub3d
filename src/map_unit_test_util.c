/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_unit_test_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:40:34 by sanghpar          #+#    #+#             */
/*   Updated: 2021/01/04 13:45:46 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		up_test(int i, int j)
{
	while (i >= 0)
	{
		if (g_map[i][j] == '1')
			return (0);
		i--;
	}
	return (-1);
}

int		down_test(int i, int j, int height)
{
	while (i < height)
	{
		if (g_map[i][j] == '1')
			return (0);
		i++;
	}
	return (-1);
}

int		left_test(int i, int j)
{
	while (j >= 0)
	{
		if (g_map[i][j] == '1')
			return (0);
		j--;
	}
	return (-1);
}

int		right_test(int i, int j, int width)
{
	while (j <= width)
	{
		if (g_map[i][j] == '1')
			return (0);
		j++;
	}
	return (-1);
}

int		uni_test(int i, int j, int width, int height)
{
	if (up_test(i, j) == -1)
		return (-1);
	if (down_test(i, j, height) == -1)
		return (-1);
	if (left_test(i, j) == -1)
		return (-1);
	if (right_test(i, j, width) == -1)
		return (-1);
	return (0);
}
