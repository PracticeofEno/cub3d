/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:11:47 by sanghpar          #+#    #+#             */
/*   Updated: 2021/01/04 14:11:49 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		draw_rect(t_game *g_game, int x, int y, int size)
{
	int i;
	int j;
	int index;
	int x_index;

	i = 0;
	index = 0;
	while (i < size)
	{
		index = get_calc_index(x, y + i);
		j = 0;
		while (j < size)
		{
			x_index = get_calc_index(j, 0);
			set_color((unsigned char *)&g_game->img->data[index + x_index],
			0xFFFFFF);
			j++;
		}
		i++;
	}
}

void		draw_rect2(int x, int y, int size, int color)
{
	int i;
	int j;
	int index;
	int x_index;

	i = 0;
	index = 0;
	while (i < size)
	{
		index = get_calc_index(x, y + i);
		j = 0;
		while (j < size)
		{
			x_index = get_calc_index(j, 0);
			set_color((unsigned char *)&g_game.img->data[index + x_index],
				color);
			j++;
		}
		i++;
	}
}

void		draw_cols(t_point g_p1, t_point g_p2, t_ray ray)
{
	draw_sky(g_p1, g_p2);
	draw_texture(g_p1, g_p2, ray);
	draw_land(g_p1, g_p2);
}

void		draw_2d_map(void)
{
	int i;
	int j;
	int location_x;
	int location_y;

	i = 0;
	while (i < g_map_height)
	{
		j = 0;
		while (j < g_map_width)
		{
			location_x = j * g_tile_size;
			location_y = i * g_tile_size;
			if (g_map[i][j] == '1')
				draw_rect(&g_game, location_x, location_y, g_tile_size);
			else if (g_map[i][j] == '2')
				draw_rect2(location_x, location_y,
				g_tile_size, get_color(255, 0, 0));
			else
				draw_rect2(location_x, location_y,
				g_tile_size, get_color(0, 0, 0));
			j++;
		}
		i++;
	}
}

void		calc_ray(void)
{
	int		col_id;
	int		i;
	double	ray_angle;

	col_id = 0;
	i = 0;
	ray_angle = g_player.rotation_angle - (g_fov_angle / 2);
	while (i < g_num_rays)
	{
		g_rays[i].angle = normalize_angle(ray_angle);
		cast_ray(ray_angle, col_id);
		ray_angle = ray_angle + (g_fov_angle / g_num_rays);
		i++;
		col_id++;
	}
}
