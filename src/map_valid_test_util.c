/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_test_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:11:18 by sanghpar          #+#    #+#             */
/*   Updated: 2021/01/04 14:11:20 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int			get_content_width(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\t')
			i = i + 3;
		i++;
	}
	return (i);
}

static int			get_g_map_width(t_list *lst)
{
	int max;
	int size;

	max = 0;
	size = 0;
	while (lst)
	{
		size = get_content_width((char *)lst->content);
		if (max < size)
			max = size;
		lst = lst->next;
	}
	if (max == 0)
		return (-1);
	return (max);
}

static int			get_g_map_height(t_list *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	if (i == 0)
		return (-1);
	return (i);
}

char				**map_valid_test(t_list *lst)
{
	int	i;

	i = 0;
	g_map_width = get_g_map_width(lst);
	g_map_height = get_g_map_height(lst);
	if (g_map_width == -1 && g_map_height == -1)
		return (0);
	if (!(g_map = (char**)malloc(sizeof(char *) * g_map_height)))
		return (0);
	while (i < g_map_height)
	{
		if (!(g_map[i] = (char*)malloc(sizeof(char) * g_map_width)))
			return (0);
		i++;
	}
	copy_map(g_map, lst);
	if (check_valid_map(g_map_width, g_map_height) == -1)
		return (0);
	return (g_map);
}

int					is_wall(int x, int y)
{
	int x1;
	int y1;

	if (x < 0 || x > g_map_width * g_tile_size)
		return (1);
	if (y < 0 || y > g_map_height * g_tile_size)
		return (1);
	x1 = floor(x / g_tile_size);
	y1 = floor(y / g_tile_size);
	if (g_map[y1][x1] == '1')
		return (1);
	else if (g_map[y1][x1] == '2')
		return (2);
	else
		return (0);
}
