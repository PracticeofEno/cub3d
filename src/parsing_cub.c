/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:46:20 by sanghpar          #+#    #+#             */
/*   Updated: 2021/01/10 04:51:56 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		texture_check(void)
{
	if (!(g_texture.ea = (t_img *)mlx_xpm_file_to_image(g_game.mlx,
					g_md.east, &g_texture.ea_w, &g_texture.ea_h)))
		return (-1);
	if (!(g_texture.no = (t_img *)mlx_xpm_file_to_image(g_game.mlx,
					g_md.north, &g_texture.no_w, &g_texture.no_h)))
		return (-1);
	if (!(g_texture.we = (t_img *)mlx_xpm_file_to_image(g_game.mlx,
					g_md.west, &g_texture.we_w, &g_texture.we_h)))
		return (-1);
	if (!(g_texture.so = (t_img *)mlx_xpm_file_to_image(g_game.mlx,
					g_md.south, &g_texture.so_w, &g_texture.so_h)))
		return (-1);
	if (!(g_texture.item = (t_img *)mlx_xpm_file_to_image(g_game.mlx,
					g_md.sprite, &g_texture.so_w, &g_texture.so_h)))
		return (-1);
	return (1);
}

int		check_complete(void)
{
	if (g_md.width != 0 && g_md.height != 0 && g_md.north != 0
	&& g_md.south != 0 && g_md.west != 0 && g_md.east != 0 &&
		g_md.sprite != 0 && g_md.f != 0 && g_md.c != 0)
		return (1);
	return (-1);
}

int		set_data(char *line)
{
	char **splits;

	splits = ft_split(line, ' ');
	if (*splits == 0)
	{
		free_arrs(splits);
		return (0);
	}
	else
	{
		if (set_env_data(splits) == -1)
		{
			free_arrs(splits);
			return (-1);
		}
	}
	free_arrs(splits);
	return (1);
}

int		parse_data(int fd)
{
	char	*line;
	int		i;

	line = 0;
	while ((i = get_next_line(fd, &line)) > 0)
	{
		if (set_data(line) == -1)
		{
			free_buffer(&line);
			return (-1);
		}
		if (check_complete() == 1)
		{
			free_buffer(&line);
			return (1);
		}
		free_buffer(&line);
	}
	return (-1);
}

int		cub_parse(int fd)
{
	int		w_tile;
	int		h_tile;
	t_list	*lst;

	lst = 0;
	if (!(g_game.mlx = mlx_init()))
		return (-1);
	if (!(g_game.mlx2 = mlx_init()))
		return (-1);
	if (parse_data(fd) == -1)
		return (-1);
	if (jump_to_map(fd, &lst) == -1)
		return (-1);
	if ((g_game.map = map_valid_test(lst)) == 0)
		return (-1);
	w_tile = (g_md.width / g_map_width);
	h_tile = (g_md.height / g_map_height);
	g_tile_size = (w_tile < h_tile) ? w_tile : h_tile;
	return (0);
}
