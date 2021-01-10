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

void	reset_img(void)
{
	int i;
	int j;
	int width;
	int height;

	width = map_width * tile_size;
	height = map_height * tile_size;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			set_color((unsigned char *)&game.img2->data[get_calc_index(j, i)],
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
	while (i < num_rays)
	{
		set_t_point(player.x, player.y, rays[i].hit.x, rays[i].hit.y);
		draw_line(game, &p1, &p2, get_color(0, 255, 0));
		i++;
	}
}

void	draw_3d_ray(void)
{
	int		i;
	double	distance;
	double	dis_projection;
	double	wall_strip_height;

	i = 0;
	while (i < num_rays)
	{
		distance = rays[i].distance *
			cos(rays[i].angle - player.rotation_angle);
		dis_projection = ((map_width * tile_size) / 2) / tan(fov_angle / 2);
		wall_strip_height = (tile_size / distance) * dis_projection;
		p1.x = i * wall_strip_width;
		p1.y = ((double)(map_height * tile_size) / 2) - (wall_strip_height / 2);
		if (p1.y < 0)
			p1.y = 0;
		p2.x = wall_strip_width;
		p2.y = wall_strip_height;
		if (p2.y > tile_size * map_height)
			p2.y = tile_size * map_height;
		draw_cols(p1, p2, rays[i]);
		i++;
	}
}

void	norminette_bypass(int col_id, t_point hit_p, double hit_dis, bool ht)
{
	rays[col_id].hit.x = hit_p.x;
	rays[col_id].hit.y = hit_p.y;
	rays[col_id].distance = hit_dis;
	rays[col_id].hit_tf = ht;
}

void	norminette_bypass2(int col_id, t_point hit_p, double hit_dis, bool ht)
{
	sp_rays[col_id].hit.x = hit_p.x;
	sp_rays[col_id].hit.y = hit_p.y;
	sp_rays[col_id].distance = hit_dis;
	sp_rays[col_id].hit_tf = ht;
}
