/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:12:25 by sanghpar          #+#    #+#             */
/*   Updated: 2021/01/04 14:12:26 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	splits_length(char **splits)
{
	int i;

	i = 0;
	while (splits[i])
		i++;
	return (i);
}

static int	try_r(char **splits)
{
	int arr_length;
	int width;
	int height;
	int max_size_x;
	int max_size_y;

	mlx_get_screen_size(g_game.mlx, &max_size_x, &max_size_y);
	arr_length = splits_length(splits);
	if (arr_length != 3)
		return (-1);
	width = ft_atoi(splits[1]);
	height = ft_atoi(splits[2]);
	if (width == 0 || height == 0)
		return (-1);
	g_md.width = width;
	g_md.height = height;
	if (g_md.width > max_size_x)
		g_md.width = max_size_x;
	if (g_md.height > max_size_y)
		g_md.height = max_size_y;
	return (0);
}

static int	try_g_texture(char **splits)
{
	int arr_length;

	arr_length = splits_length(splits);
	if (arr_length != 2)
		return (-1);
	if (ft_strcmp(splits[0], "NO") == 0)
		g_md.north = ft_strdup(splits[1]);
	else if (ft_strcmp(splits[0], "SO") == 0)
		g_md.south = ft_strdup(splits[1]);
	else if (ft_strcmp(splits[0], "WE") == 0)
		g_md.west = ft_strdup(splits[1]);
	else if (ft_strcmp(splits[0], "EA") == 0)
		g_md.east = ft_strdup(splits[1]);
	else if (ft_strcmp(splits[0], "S") == 0)
		g_md.sprite = ft_strdup(splits[1]);
	else if (ft_strcmp(splits[0], "F") == 0)
		g_md.south = ft_strdup(splits[1]);
	else if (ft_strcmp(splits[0], "C") == 0)
		g_md.south = ft_strdup(splits[1]);
	return (0);
}

static int	try_color(char **splits)
{
	int arr_length;

	arr_length = splits_length(splits);
	if (arr_length != 2)
		return (-1);
	if (ft_strcmp(splits[0], "F") == 0)
		return (make_color(splits[1], &g_md.f));
	else if (ft_strcmp(splits[0], "C") == 0)
		return (make_color(splits[1], &g_md.c));
	return (0);
}

int			set_env_data(char **splits)
{
	if (ft_strcmp(splits[0], "R") == 0)
		return (try_r(splits));
	else if (ft_strcmp(splits[0], "NO") == 0)
		return (try_g_texture(splits));
	else if (ft_strcmp(splits[0], "SO") == 0)
		return (try_g_texture(splits));
	else if (ft_strcmp(splits[0], "WE") == 0)
		return (try_g_texture(splits));
	else if (ft_strcmp(splits[0], "EA") == 0)
		return (try_g_texture(splits));
	else if (ft_strcmp(splits[0], "S") == 0)
		return (try_g_texture(splits));
	else if (ft_strcmp(splits[0], "F") == 0)
		return (try_color(splits));
	else if (ft_strcmp(splits[0], "C") == 0)
		return (try_color(splits));
	return (0);
}
