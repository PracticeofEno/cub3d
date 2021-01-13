/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_util2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 04:56:23 by sanghpar          #+#    #+#             */
/*   Updated: 2021/01/10 04:56:25 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_distance(t_list *sp_list)
{
	double	sprite_angle;
	t_ray	*ray;
	t_list	*tmp;

	tmp = sp_list;
	while (tmp)
	{
		ray = ((t_ray *)(tmp->content));
		ray->hit.x = (ray->hit.x * g_tile_size) + ((double)g_tile_size / 2);
		ray->hit.y = (ray->hit.y * g_tile_size) + ((double)g_tile_size / 2);
		ray->distance = get_distance(g_player.x, g_player.y,
										ray->hit.x, ray->hit.y);
		sprite_angle = normalize_angle(atan2(ray->hit.y - g_player.y,
										ray->hit.x - g_player.x));
		tmp->min_angle = (sprite_angle - atan2((double)g_tile_size / 2,
										ray->distance));
		tmp->max_angle = (sprite_angle + atan2((double)g_tile_size / 2,
										ray->distance));
		tmp = tmp->next;
	}
}

int		check_black_color(int index, int y, t_ray ray, t_list *tmp)
{
	double ix;
	double iy;
	double dx;
	double dy;
	double wall_strip_height;

	wall_strip_height = (g_tile_size / ((t_ray *)(tmp->content))->distance) *
		(((g_map_width * g_tile_size) / 2) / tan(g_fov_angle / 2));
	ix = ray.angle - tmp->min_angle;
	iy = y;
	dx = (g_texture.item->width / (tmp->max_angle - tmp->min_angle));
	dy = (g_texture.item->height / wall_strip_height);
	if ((g_texture.item->data[get_calc_index2((int)(ix * dx),
							(int)(iy * dy), (g_texture.item))]) != 0)
		ft_memmove(&g_game.img2->data[index],
		&g_texture.item->data[get_calc_index2((int)(ix * dx), (int)(iy * dy),
		(g_texture.item))], 4);
	return (0);
}

void	draw_item2(t_point g_p1, t_point g_p2, t_ray ray, t_list *tmp)
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
			check_black_color(index + x_index, i, ray, tmp);
			j++;
		}
		i++;
	}
}

void	draw_item(t_list *tmp, t_ray ray, int i)
{
	double wsh;
	double dis_proejction;

	dis_proejction = ((g_map_width * g_tile_size) / 2) / tan(g_fov_angle / 2);
	wsh = (g_tile_size / ((t_ray *)tmp->content)->distance) * dis_proejction;
	g_p1.x = i * g_wall_strip_width;
	g_p1.y = ((double)(g_map_height * g_tile_size) / 2) - (wsh / 2);
	if (g_p1.y < 0)
		g_p1.y = 0;
	g_p2.x = g_wall_strip_width;
	g_p2.y = wsh;
	if (g_p2.y > g_tile_size * g_map_height)
		g_p2.y = g_tile_size * g_map_height;
	draw_item2(g_p1, g_p2, ray, tmp);
}

void	test(t_list *sp_list)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (i < g_num_rays)
	{
		tmp = sp_list;
		while (tmp)
		{
			if (tmp->max_angle > 2 * PI && g_sp_rays[i].angle < PI / 2)
			{
				tmp->min_angle = tmp->min_angle - 2 * PI;
				tmp->max_angle = tmp->max_angle - 2 * PI;
			}
			if (tmp->min_angle <= g_sp_rays[i].angle
				&& tmp->max_angle >= g_sp_rays[i].angle)
			{
				if (cast_ray(g_sp_rays[i].angle, g_num_rays)
				> cast_ray_sprite(g_sp_rays[i].angle, g_num_rays))
					draw_item(tmp, g_sp_rays[i], i);
			}
			tmp = tmp->next;
		}
		i++;
	}
}
