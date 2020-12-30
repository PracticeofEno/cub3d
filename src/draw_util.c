#include "cub3d.h"

void draw_2d_ray()
{
    int i;
    
    i = 0;
    while (i < num_rays)
    {
        set_t_point(player.x, player.y, rays[i].hit.x, rays[i].hit.y);
        draw_line(game, &p1, &p2, get_color(0,255,0));
        i++;
    }
}

void draw_3d_ray()
{
    int i;
    double distance;
    double dis_projection;
    double wall_strip_height;

    i = 0;
    while (i < num_rays)
    {
        distance = rays[i].distance * cos(rays[i].angle - player.rotation_angle);
        dis_projection = (map_width * TILE_SIZE / 2) / tan(fov_angle / 2);
        wall_strip_height = (TILE_SIZE / distance) * dis_projection;
        p1.x = i * wall_strip_width;
        p1.y = (map_height * TILE_SIZE / 2) - (wall_strip_height / 2);
        p2.x = wall_strip_width;
        p2.y = wall_strip_height;
        draw_rect3(p1, p2, get_color(255,255,255));
        i++;
    }
}

