#include "cub3d.h"

double d2r()
{
    return (player.rotation_angle * (PI / 180.0));
}

void default_setting()
{
    fov_angle = 60 * (PI / 180);
    wall_strip_width = 1;
    num_rays = (map_width * TILE_SIZE) / wall_strip_width;
    rays = (t_ray *)malloc((num_rays) * sizeof(t_ray));
    if (rays == 0)
        exit(1);
}

int setting()
{
    if (mlx_setting() == -1)
    {
        printf("mlx init or new window error");
        return (-1);
    }
    player_setting();
    default_setting();
    return (0);
}

void update()
{
    player_update();
}

void render()
{
    //t_point a;
    //t_point b;

    //mlx_clear_window(game.mlx, game.win);
    update();
    draw_2d_map();
    player_render();
    calc_ray();
    draw_2d_ray();
    draw_3d_ray();
}