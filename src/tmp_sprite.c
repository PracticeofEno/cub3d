#include "cub3d.h"

void calc_ray_sprite()
{
	int col_id;
    int i;
    double ray_angle;

    col_id = 0;
    i = 0;
    ray_angle = player.rotation_angle - (fov_angle / 2);
    while (i < num_rays)
    {
        sp_rays[i].angle = normalize_angle(ray_angle);
        cast_ray_sprite(ray_angle, col_id);
        ray_angle = ray_angle + (fov_angle / num_rays);
        i++;
        col_id++;
    }
}