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
	return (g_player.rotation_angle * (PI / 180.0));
}

void		default_setting(void)
{
	g_fov_angle = 60 * (PI / 180);
	g_wall_strip_width = 1;
	g_num_rays = (g_map_width * g_tile_size) / g_wall_strip_width;
	g_rays = (t_ray *)malloc((g_num_rays) * sizeof(t_ray));
	g_sp_rays = (t_ray *)malloc((g_num_rays) * sizeof(t_ray));
	if (g_rays == 0 || g_sp_rays == 0)
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
		ft_putstr("g_texture error");
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
	mlx_put_image_to_window(g_game.mlx, g_game.win2, g_game.img2, 0, 0);
	update();
	draw_2d_map();
	player_render();
	calc_ray();
	draw_2d_ray();
	draw_3d_ray();
	calc_ray_sprite();
	draw_sprite();
}
