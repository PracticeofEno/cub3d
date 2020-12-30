#include "cub3d.h"

void draw_rect(t_game *game, int x, int y, int size)
{
    int i;
    int j;
    int index;
    int x_index;

    i = 0;
    index = 0;
    while (i < size)
    {
        index = get_calc_index(x, y + i);
        j = 0;
        while (j < size)
        {
            x_index = get_calc_index(j, 0);
            set_color((unsigned char *)&game->img->data[index + x_index], 0xFFFFFF);
            j++;
        }
        i++;
    }
}

void draw_rect2(int x, int y, int size, int color)
{
    int i;
    int j;
    int index;
    int x_index;

    i = 0;
    index = 0;
    while (i < size)
    {
        index = get_calc_index(x, y + i);
        j = 0;
        while (j < size)
        {
            x_index = get_calc_index(j, 0);
            set_color((unsigned char *)&game.img->data[index + x_index], color);
            j++;
        }
        i++;
    }
}

void draw_rect3(t_point p1, t_point p2, int color)
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
            set_color((unsigned char *)&game.img2->data[index + x_index], color);
            j++;
        }
        i++;
    }
}

void draw_2d_map()
{
    int i;
    int j;
    int location_x;
    int location_y;

    i = 0;
    while (i < map_height)
    {
        j = 0;
        while (j < map_width)
        {
            location_x = j * TILE_SIZE;
            location_y = i * TILE_SIZE;
            if (map[i][j] == '1')
                draw_rect(&game, location_x, location_y, TILE_SIZE);
            else
                draw_rect2(location_x, location_y, TILE_SIZE, get_color(0,0,0));
            j++;
        }
        i++;
    }
}

void calc_ray()
{
    int col_id;
    int i;
    double ray_angle;

    col_id = 0;
    i = 0;
    ray_angle = player.rotation_angle - (fov_angle / 2);
    while (i < num_rays)
    {
        rays[i].angle = normalize_angle(ray_angle);
        cast_ray(ray_angle, col_id);
        ray_angle = ray_angle + (fov_angle / num_rays);
        i++;
        col_id++;
    }
}
