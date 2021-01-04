/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:46:20 by sanghpar          #+#    #+#             */
/*   Updated: 2021/01/04 13:52:36 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		texture_check()
{
	if (!(texture.ea = (t_img *)mlx_xpm_file_to_image(game.mlx, md.east, &texture.ea_w, &texture.ea_h)))
		return (-1);
	if (!(texture.no = (t_img *)mlx_xpm_file_to_image(game.mlx, md.north, &texture.no_w, &texture.no_h)))
		return (-1);
	if (!(texture.we = (t_img *)mlx_xpm_file_to_image(game.mlx, md.west, &texture.we_w, &texture.we_h)))
		return (-1);
	if (!(texture.so = (t_img *)mlx_xpm_file_to_image(game.mlx, md.south, &texture.so_w, &texture.so_h)))
		return (-1);
	if (!(texture.item = (t_img *)mlx_xpm_file_to_image(game.mlx, md.sprite, &texture.so_w, &texture.so_h)))
		return (-1);
	return (1);
}

int		check_complete()
{
	if (md.width != 0 && md.height != 0 && md.north != 0 && md.south != 0
			&& md.west != 0 && md.east != 0 && md.sprite != 0 && md.f != 0 && md.c != 0)
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
	int		i;
    char	*line;
	
	line = 0;
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
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
	t_list	*lst;
	int		w_tile;
	int		h_tile;
	
	lst = 0;
	if (!(game.mlx = mlx_init()))
		return (-1);
	if (!(game.mlx2 = mlx_init()))
		return (-1);
	if (parse_data(fd) == -1)
		return (-1);
	if (jump_to_map(fd, &lst) == -1)
		return (-1);
	if ((game.map = map_valid_test(lst)) == 0)
		return (-1);
	w_tile = (md.width / map_width);
	h_tile = (md.height / map_height);
	tile_size = (w_tile < h_tile) ? w_tile : h_tile;
	return (0);
}
