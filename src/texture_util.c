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

void	draw_sky(t_point p1, t_point p2)
{
	int i;
	int j;
	int base;
	int x_index;

	i = 0;
	base = get_calc_index(p1.x, 0);
	while (i < p1.y)
	{
		j = 0;
		while (j < p2.x)
		{
			x_index = get_calc_index(j, i);
			set_color((unsigned char *)&game.img2->data[base + x_index],
					get_color(md.c->r, md.c->g, md.c->b));
			j++;
		}
		i++;
	}
}

void	draw_land(t_point p1, t_point p2)
{
	int i;
	int j;
	int base;
	int x_index;
	int height;

	i = p1.y + p2.y;
	height = tile_size * map_height;
	base = get_calc_index(p1.x, 0);
	while (i < height)
	{
		j = 0;
		while (j < p2.x)
		{
			x_index = get_calc_index(j, i);
			set_color((unsigned char *)&game.img2->data[base + x_index],
					get_color(md.f->r, md.f->g, md.f->b));
			j++;
		}
		i++;
	}
}

int		set_angle(char angle)
{
	if (angle == 'S')
		player.rotation_angle = (PI * 2) / 4 * 1;
	else if (angle == 'W')
		player.rotation_angle = (PI * 2) / 4 * 2;
	else if (angle == 'N')
		player.rotation_angle = (PI * 2) / 4 * 3;
	else if (angle == 'E')
		player.rotation_angle = (PI * 2) / 4 * 4;
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

void	draw_texture(t_point p1, t_point p2, t_ray ray)
{
	int i;
	int j;
	int index;
	int x_index;

	i = 0;
	index = 0;
	while (i < p2.y)
	{
		index = get_calc_index(p1.x, p1.y + i);
		j = 0;
		while (j < p2.x)
		{
			x_index = get_calc_index(j, 0);
			gtc(j, i, ray, index + x_index);
			j++;
		}
		i++;
	}
}
