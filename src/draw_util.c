/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:12:12 by sanghpar          #+#    #+#             */
/*   Updated: 2021/01/04 14:12:13 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	reset_img(t_img *img)
{
	int i;
	int j;
	int width;
	int height;

	width = g_map_width * g_tile_size;
	height = g_map_height * g_tile_size;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			set_color((unsigned char *)&img->data[get_calc_index(j, i)],
				get_color(0, 0, 0));
			j++;
		}
		i++;
	}
}

void	draw_2d_ray(void)
{
	int i;

	i = 0;
	set_t_point(g_player.x, g_player.y, g_rays[i].hit.x, g_rays[i].hit.y);
	draw_line(g_game, &g_p1, &g_p2, get_color(0, 255, 0));
	while (i < g_num_rays)
	{
		i++;
	}
	i--;
	set_t_point(g_player.x, g_player.y, g_rays[i].hit.x, g_rays[i].hit.y);
	draw_line(g_game, &g_p1, &g_p2, get_color(0, 255, 0));
}

void	draw_3d_ray(void)
{
	int		i;
	double	distance;
	double	dis_projection;
	double	wall_strip_height;

	i = 0;
	while (i < g_num_rays)
	{
		distance = g_rays[i].distance *
			cos(g_rays[i].angle - g_player.rotation_angle);
		dis_projection = ((g_map_width * g_tile_size) / 2)
			/ tan(g_fov_angle / 2);
		wall_strip_height = (g_tile_size / distance) * dis_projection;
		g_p1.x = i * g_wall_strip_width;
		g_p1.y = ((double)(g_map_height * g_tile_size) / 2)
			- (wall_strip_height / 2);
		if (g_p1.y < 0)
			g_p1.y = 0;
		g_p2.x = g_wall_strip_width;
		g_p2.y = wall_strip_height;
		if (g_p2.y > g_tile_size * g_map_height)
			g_p2.y = g_tile_size * g_map_height;
		draw_cols(g_p1, g_p2, g_rays[i]);
		i++;
	}
}

void	norminette_bypass(int col_id, t_point hit_p, double hit_dis, bool ht)
{
	g_rays[col_id].hit.x = hit_p.x;
	g_rays[col_id].hit.y = hit_p.y;
	g_rays[col_id].distance = hit_dis;
	g_rays[col_id].hit_tf = ht;
}

void	norminette_bypass2(int col_id, t_point hit_p, double hit_dis, bool ht)
{
	g_sp_rays[col_id].hit.x = hit_p.x;
	g_sp_rays[col_id].hit.y = hit_p.y;
	g_sp_rays[col_id].distance = hit_dis;
	g_sp_rays[col_id].hit.sprite_hit = ht;
}
