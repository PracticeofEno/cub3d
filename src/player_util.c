/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:11:24 by sanghpar          #+#    #+#             */
/*   Updated: 2021/01/04 14:11:26 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_g_player(t_game *g_game, int x, int y)
{
	int i;
	int j;
	int index;
	int x_index;

	i = 0;
	index = 0;
	while (i < 2)
	{
		index = (y + i) * g_game->img->size_line;
		index = index + (x * (g_game->img->bpp / 8));
		j = 0;
		while (j < 2)
		{
			x_index = (j * (g_game->img->bpp / 8));
			set_color((unsigned char *)&g_game->img->data[
				index + x_index], 0xFF0000);
			j++;
		}
		i++;
	}
}

void	player_render(void)
{
	draw_g_player(&g_game, g_player.x, g_player.y);
}

void	player_update(void)
{
	double move_step;
	double new_x;
	double new_y;

	g_player.rotation_angle += g_player.turn_direction *
		g_player.rotation_speed;
	g_player.rotation_angle = normalize_angle(g_player.rotation_angle);
	move_step = g_player.walk_direction * g_player.move_speed;
	new_x = g_player.x + cos(g_player.rotation_angle) * move_step;
	new_y = g_player.y + sin(g_player.rotation_angle) * move_step;
	if (is_wall(new_x + 3, new_y + 3) != 1
		&& is_wall(new_x - 3, new_y - 3) != 1)
	{
		g_player.x = new_x;
		g_player.y = new_y;
	}
}

int		key_pressed(int key, void *p)
{
	temp(p);
	if (key == 119)
		g_player.walk_direction = 1;
	else if (key == 115)
		g_player.walk_direction = -1;
	else if (key == 97)
		g_player.turn_direction = -1;
	else if (key == 100)
		g_player.turn_direction = 1;
	return (0);
}

int		key_released(int key, void *p)
{
	temp(p);
	if (key == 119)
		g_player.walk_direction = 0;
	else if (key == 115)
		g_player.walk_direction = 0;
	else if (key == 97)
		g_player.turn_direction = 0;
	else if (key == 100)
		g_player.turn_direction = 0;
	else if (key == 65307)
		exit(1);
	return (0);
}
