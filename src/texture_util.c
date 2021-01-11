/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:11:32 by sanghpar          #+#    #+#             */
/*   Updated: 2021/01/04 14:11:34 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sky(t_point g_p1, t_point g_p2)
{
	int i;
	int j;
	int base;
	int x_index;

	i = 0;
	base = get_calc_index(g_p1.x, 0);
	while (i < g_p1.y)
	{
		j = 0;
		while (j < g_p2.x)
		{
			x_index = get_calc_index(j, i);
			set_color((unsigned char *)&g_game.img2->data[base + x_index],
					get_color(g_md.c->r, g_md.c->g, g_md.c->b));
			j++;
		}
		i++;
	}
}

void	draw_land(t_point g_p1, t_point g_p2)
{
	int i;
	int j;
	int base;
	int x_index;
	int height;

	i = g_p1.y + g_p2.y;
	height = g_tile_size * g_map_height;
	base = get_calc_index(g_p1.x, 0);
	while (i < height)
	{
		j = 0;
		while (j < g_p2.x)
		{
			x_index = get_calc_index(j, i);
			set_color((unsigned char *)&g_game.img2->data[base + x_index],
					get_color(g_md.f->r, g_md.f->g, g_md.f->b));
			j++;
		}
		i++;
	}
}

int		set_angle(char angle)
{
	if (angle == 'S')
		g_player.rotation_angle = (PI * 2) / 4 * 1;
	else if (angle == 'W')
		g_player.rotation_angle = (PI * 2) / 4 * 2;
	else if (angle == 'N')
		g_player.rotation_angle = (PI * 2) / 4 * 3;
	else if (angle == 'E')
		g_player.rotation_angle = (PI * 2) / 4 * 4;
	return (0);
}

int		gtc(int x, int y, t_ray ray, int index)
{
	int	rfd;
	int	rfr;

	rfd = ray.angle > 0 && ray.angle < PI;
	rfr = (ray.angle < 0.5 * PI || ray.angle > 1.5 * PI);
	if (rfd == 1)
		if (rfr == 1)
			dr_tex(x, y, ray, index);
		else
			dl_tex(x, y, ray, index);
	else
	{
		if (rfr == 1)
			ur_tex(x, y, ray, index);
		else
			ul_tex(x, y, ray, index);
	}
	return (0);
}

void	draw_texture(t_point g_p1, t_point g_p2, t_ray ray)
{
	int i;
	int j;
	int index;
	int x_index;

	i = 0;
	index = 0;
	while (i < g_p2.y)
	{
		index = get_calc_index(g_p1.x, g_p1.y + i);
		j = 0;
		while (j < g_p2.x)
		{
			x_index = get_calc_index(j, 0);
			gtc(j, i, ray, index + x_index);
			j++;
		}
		i++;
	}
}
