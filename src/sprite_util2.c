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
		ray->hit.x = (ray->hit.x * tile_size) + ((double)tile_size / 2);
		ray->hit.y = (ray->hit.y * tile_size) + ((double)tile_size / 2);
		ray->distance = get_distance(player.x, player.y,
										ray->hit.x, ray->hit.y);
		sprite_angle = normalize_angle(atan2(ray->hit.y - player.y,
										ray->hit.x - player.x));
		tmp->min_angle = (sprite_angle - atan2((double)tile_size / 2,
										ray->distance));
		tmp->max_angle = (sprite_angle + atan2((double)tile_size / 2,
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

	wall_strip_height = (tile_size / ((t_ray *)(tmp->content))->distance) *
		(((map_width * tile_size) / 2) / tan(fov_angle / 2));
	ix = ray.angle - tmp->min_angle;
	iy = y;
	dx = (texture.item->width / (tmp->max_angle - tmp->min_angle));
	dy = (texture.item->height / wall_strip_height);
	if ((texture.item->data[get_calc_index2((int)(ix * dx),
							(int)(iy * dy), (texture.item))]) != 0)
		ft_memmove(&game.img2->data[index],
		&texture.item->data[get_calc_index2((int)(ix * dx), (int)(iy * dy),
		(texture.item))], 4);
	return (0);
}

void	draw_item2(t_point p1, t_point p2, t_ray ray, t_list *tmp)
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

	dis_proejction = ((map_width * tile_size) / 2) / tan(fov_angle / 2);
	wsh = (tile_size / ((t_ray *)tmp->content)->distance) * dis_proejction;
	p1.x = i * wall_strip_width;
	p1.y = ((double)(map_height * tile_size) / 2) - (wsh / 2);
	if (p1.y < 0)
		p1.y = 0;
	p2.x = wall_strip_width;
	p2.y = wsh;
	if (p2.y > tile_size * map_height)
		p2.y = tile_size * map_height;
	draw_item2(p1, p2, ray, tmp);
}

void	test(t_list *sp_list)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (i < num_rays)
	{
		tmp = sp_list;
		while (tmp)
		{
			if (tmp->min_angle <= sp_rays[i].angle
				&& tmp->max_angle >= sp_rays[i].angle)
			{
				draw_item(tmp, sp_rays[i], i);
			}
			tmp = tmp->next;
		}
		i++;
	}
}
