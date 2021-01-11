/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:12:29 by sanghpar          #+#    #+#             */
/*   Updated: 2021/01/04 14:12:30 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		mlx_setting(void)
{
	if (!(g_game.win = mlx_new_window(g_game.mlx,
		g_map_width * g_tile_size, g_map_height * g_tile_size, "2d g_map")))
		return (-1);
	if (!(g_game.img = (t_img *)mlx_new_image(g_game.mlx,
		g_map_width * g_tile_size, g_map_height * g_tile_size)))
		return (-1);
	if (!(g_game.win2 = mlx_new_window(g_game.mlx2,
		g_map_width * g_tile_size, g_map_height * g_tile_size, "3d")))
		return (-1);
	if (!(g_game.img2 = (t_img *)mlx_new_image(g_game.mlx2,
		g_map_width * g_tile_size, g_map_height * g_tile_size)))
		return (-1);
	mlx_hook(g_game.win, KeyPress, KeyPressMask, key_pressed, 0);
	mlx_hook(g_game.win, KeyRelease, KeyReleaseMask, key_released, 0);
	mlx_hook(g_game.win, ClientMessage, DestroyNotify, window_close, 0);
	return (0);
}

void	g_player_init(void)
{
	g_player.radius = 3;
	g_player.turn_direction = 0;
	g_player.walk_direction = 0;
	g_player.move_speed = 2;
	g_player.rotation_speed = 2 * (PI / 180);
}

void	player_setting(void)
{
	int i;
	int j;

	i = 0;
	while (i < g_map_height)
	{
		j = 0;
		while (j < g_map_width)
		{
			if (g_game.map[i][j] == 'N' || g_game.map[i][j] == 'W' ||
				g_game.map[i][j] == 'E' || g_game.map[i][j] == 'S')
			{
				g_player.x = (j * g_tile_size);
				g_player.y = (i * g_tile_size);
				set_angle(g_game.map[i][j]);
			}
			j++;
		}
		i++;
	}
	g_player_init();
}

void	*temp(void *p)
{
	return (p);
}

double	get_distance(double x1, double y1, double x2, double y2)
{
	return (sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))));
}
