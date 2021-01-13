/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_sprite2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 04:57:33 by sanghpar          #+#    #+#             */
/*   Updated: 2021/01/10 04:57:34 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	calc_h_ray_s(t_point interc, t_point step, t_point *hp, int d)
{
	t_point	next_h_p;

	next_h_p.x = interc.x;
	next_h_p.y = interc.y;
	hp->sprite_hit = false;
	while (next_h_p.x >= 0 && next_h_p.x < (g_map_width * g_tile_size)
			&& next_h_p.y >= 0 && next_h_p.y < (g_map_height * g_tile_size))
	{
		if (is_wall(next_h_p.x, next_h_p.y - ((!d) ? 1 : 0)) == 2)
		{
			hp->sprite_hit = true;
			hp->x = next_h_p.x;
			hp->y = next_h_p.y - ((!d) ? 1 : 0);
			break ;
		}
		else
		{
			next_h_p.x += step.x;
			next_h_p.y += step.y;
		}
	}
}

static void		horizontal_check_s(t_point *hit_point, double angle)
{
	t_point	intercept;
	t_point	step;
	int		rfd;
	int		rfr;

	angle = normalize_angle(angle);
	rfd = angle > 0 && angle < PI;
	rfr = (angle < 0.5 * PI || angle > 1.5 * PI);
	intercept.y = floor(g_player.y / g_tile_size) * g_tile_size;
	if (rfd)
		intercept.y += g_tile_size;
	intercept.x = g_player.x + (intercept.y - g_player.y) / tan(angle);
	step.y = g_tile_size;
	if (!(rfd))
		step.y = step.y * -1;
	step.x = g_tile_size / tan(angle);
	if (!(rfr) && step.x > 0)
		step.x = step.x * -1;
	if ((rfr) && step.x < 0)
		step.x = step.x * -1;
	calc_h_ray_s(intercept, step, hit_point, rfd);
}

static void		calc_v_ray_s(t_point interc, t_point step, t_point *hp, int r)
{
	t_point	next_h_p;

	next_h_p.x = interc.x;
	next_h_p.y = interc.y;
	hp->sprite_hit = false;
	while (next_h_p.x >= 0 && next_h_p.x < (g_map_width * g_tile_size)
			&& next_h_p.y >= 0 && next_h_p.y < (g_map_height * g_tile_size))
	{
		if (is_wall(next_h_p.x - ((!r) ? 1 : 0), next_h_p.y) == 2)
		{
			hp->sprite_hit = true;
			hp->x = next_h_p.x - ((!r) ? 1 : 0);
			hp->y = next_h_p.y;
			break ;
		}
		else
		{
			next_h_p.x += step.x;
			next_h_p.y += step.y;
		}
	}
}

static void		vertical_check_s(t_point *hit_point, double angle)
{
	t_point intercept;
	t_point step;
	int		rfd;
	int		rfr;

	angle = normalize_angle(angle);
	rfd = angle > 0 && angle < PI;
	rfr = (angle < 0.5 * PI || angle > 1.5 * PI);
	intercept.x = floor(g_player.x / g_tile_size) * g_tile_size;
	if (rfr)
		intercept.x += g_tile_size;
	intercept.y = g_player.y + (intercept.x - g_player.x) * tan(angle);
	step.x = g_tile_size;
	if (!(rfr))
		step.x = step.x * -1;
	step.y = g_tile_size * tan(angle);
	if (!(rfd) && step.y > 0)
		step.y = step.y * -1;
	if ((rfd) && step.y < 0)
		step.y = step.y * -1;
	calc_v_ray_s(intercept, step, hit_point, rfr);
	temp(&step.y);
}

double			cast_ray_sprite(double angle, int col_id)
{
	t_point h_hit;
	t_point v_hit;
	double	h_dis;
	double	v_dis;

	horizontal_check_s(&h_hit, angle);
	vertical_check_s(&v_hit, angle);
	if (h_hit.sprite_hit == true)
		h_dis = get_distance(g_player.x, g_player.y, h_hit.x, h_hit.y);
	else
		h_dis = 999999999;
	if (v_hit.sprite_hit == true)
		v_dis = get_distance(g_player.x, g_player.y, v_hit.x, v_hit.y);
	else
		v_dis = 999999999;
	if (h_dis < v_dis)
	{
		norminette_bypass2(col_id, h_hit, h_dis, h_hit.sprite_hit);
		return (h_dis);
	}
	else
	{
		norminette_bypass2(col_id, v_hit, v_dis, v_hit.sprite_hit);
		return (v_dis);
	}
}
