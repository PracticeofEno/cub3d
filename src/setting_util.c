#include "cub3d.h"

int mlx_setting()
{
    if (!(game.mlx = mlx_init()))
      return (-1);
    if (!(game.mlx2 = mlx_init()))
      return (-1);
    printf("OK (use_xshm %d pshm_format %d)\n",((t_xvar *)game.mlx)->use_xshm,((t_xvar *)game.mlx)->pshm_format);
    if (!(game.win = mlx_new_window(game.mlx,map_width * TILE_SIZE, map_height * TILE_SIZE, "2d map")))
      return (-1);
    if (!(game.img = (t_img *)mlx_new_image(game.mlx, map_width * TILE_SIZE, map_height * TILE_SIZE)))
      return (-1);
    if (!(game.win2 = mlx_new_window(game.mlx2, map_width * TILE_SIZE, map_height * TILE_SIZE, "3d")))
      return (-1);
    if (!(game.img2 = (t_img *)mlx_new_image(game.mlx2, map_width * TILE_SIZE, map_height * TILE_SIZE)))
      return (-1);
    mlx_hook(game.win, KeyPress, KeyPressMask, key_pressed, 0);
    mlx_hook(game.win, KeyRelease, KeyReleaseMask, key_released, 0);
    return (0);
}

void player_init()
{
    player.radius = 3;
    player.turn_direction = 0;
    player.walk_direction = 0;
    player.rotation_angle = PI / 2;
    player.move_speed = 1;
    player.rotation_speed = 2 * (PI / 180);
}

void player_setting()
{
    int i;
    int j;

    i = 0;
    while (i < map_height)
    {
        j = 0;
        while (j < map_width)
        {
            if (game.map[i][j] == 'N' || game.map[i][j] == 'W' ||
                game.map[i][j] == 'E' || game.map[i][j] == 'S')
            {
                player.x = (j * TILE_SIZE);
                player.y = (i * TILE_SIZE);
            }
            j++;
        }
        i++;
    }
    player_init();
}

void *temp(void *p)
{
    return (p);
}

double get_distance(double x1, double y1, double x2, double y2)
{
    return (sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))));
}