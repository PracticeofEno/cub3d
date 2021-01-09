#include "cub3d.h"

static void		calc_h_ray_s(t_point interc, t_point step, t_point *hp)
{
	t_point	next_h_p;

	next_h_p.x = interc.x;
	next_h_p.y = interc.y;
	hp->sprite_hit = false;
	while (next_h_p.x >= 0 && next_h_p.x < (map_width * tile_size)
			&& next_h_p.y >= 0 && next_h_p.y < (map_height * tile_size))
	{
		if (is_wall(next_h_p.x, next_h_p.y) == 2)
		{
			hp->sprite_hit = true;
			hp->x = next_h_p.x;
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

static void		horizontal_check_s(t_point *hit_point, double angle)
{
	t_point	intercept;
	t_point	step;
	int		rfd;
	int		rfr;

	angle = normalize_angle(angle);
	rfd = angle > 0 && angle < PI;
	rfr = (angle < 0.5 * PI || angle > 1.5 * PI);
	intercept.y = floor(player.y / tile_size) * tile_size;
	if (rfd)
		intercept.y += tile_size;
	intercept.x = player.x + (intercept.y - player.y) / tan(angle);
	step.y = tile_size;
	if (!(rfd))
		step.y = step.y * -1;
	step.x = tile_size / tan(angle);
	if (!(rfr) && step.x > 0)
		step.x = step.x * -1;
	if ((rfr) && step.x < 0)
		step.x = step.x * -1;
	calc_h_ray_s(intercept, step, hit_point);
}

static void		calc_v_ray_s(t_point interc, t_point step, t_point *hp)
{
	t_point	next_h_p;

	next_h_p.x = interc.x;
	next_h_p.y = interc.y;
	hp->sprite_hit = false;
	while (next_h_p.x >= 0 && next_h_p.x < (map_width * tile_size)
			&& next_h_p.y >= 0 && next_h_p.y < (map_height * tile_size))
	{
		if (is_wall(next_h_p.x, next_h_p.y) == 2)
		{
			hp->sprite_hit = true;
			hp->x = next_h_p.x;
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
	intercept.x = floor(player.x / tile_size) * tile_size;
	if (rfr)
		intercept.x += tile_size;
	intercept.y = player.y + (intercept.x - player.x) * tan(angle);
	step.x = tile_size;
	if (!(rfr))
		step.x = step.x * -1;
	step.y = tile_size * tan(angle);
	if (!(rfd) && step.y > 0)
		step.y = step.y * -1;
	if ((rfd) && step.y < 0)
		step.y = step.y * -1;
	calc_v_ray_s(intercept, step, hit_point);
	temp(&step.y);
}

void			cast_ray_sprite(double angle, int col_id)
{
	t_point h_hit;
	t_point v_hit;
	double	h_dis;
	double	v_dis;

	horizontal_check_s(&h_hit, angle);
	vertical_check_s(&v_hit, angle);
	if (h_hit.sprite_hit == true)
		h_dis = get_distance(player.x, player.y, h_hit.x, h_hit.y);
	else
		h_dis = 999999999;
	if (v_hit.sprite_hit == true)
		v_dis = get_distance(player.x, player.y, v_hit.x, v_hit.y);
	else
		v_dis = 999999999;
	if (h_dis < v_dis)
		norminette_bypass2(col_id, h_hit, h_dis, h_hit.sprite_hit);
	else
		norminette_bypass2(col_id, v_hit, v_dis, v_hit.sprite_hit);
}