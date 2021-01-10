/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:11:01 by sanghpar          #+#    #+#             */
/*   Updated: 2021/01/04 14:11:05 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double		d2r(void)
{
	return (player.rotation_angle * (PI / 180.0));
}

void		default_setting(void)
{
	fov_angle = 60 * (PI / 180);
	wall_strip_width = 1;
	num_rays = (map_width * tile_size) / wall_strip_width;
	rays = (t_ray *)malloc((num_rays) * sizeof(t_ray));
	sp_rays = (t_ray *)malloc((num_rays) * sizeof(t_ray));
	if (rays == 0 || sp_rays == 0)
		exit(1);
}

int			setting(void)
{
	if (mlx_setting() == -1)
	{
		ft_putstr("mlx init or new window error");
		return (-1);
	}
	if (texture_check() == -1)
	{
		ft_putstr("texture error");
		return (-1);
	}
	player_setting();
	default_setting();
	return (0);
}

void		update(void)
{
	player_update();
}

void		render(void)
{
	reset_img();
	mlx_put_image_to_window(game.mlx, game.win2, game.img2, 0, 0);
	update();
	draw_2d_map();
	player_render();
	calc_ray();
	draw_2d_ray();
	draw_3d_ray();
	calc_ray_sprite();
	draw_sprite();
}
