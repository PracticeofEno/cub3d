/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 04:57:02 by sanghpar          #+#    #+#             */
/*   Updated: 2021/01/10 04:57:05 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_ray_sprite(void)
{
	int		col_id;
	int		i;
	double	ray_angle;

	col_id = 0;
	i = 0;
	ray_angle = g_player.rotation_angle - (g_fov_angle / 2);
	while (i < g_num_rays)
	{
		g_sp_rays[i].angle = normalize_angle(ray_angle);
		cast_ray_sprite(g_sp_rays[i].angle, col_id);
		ray_angle = ray_angle + (g_fov_angle / g_num_rays);
		i++;
		col_id++;
	}
}
