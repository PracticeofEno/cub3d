#include "cub3d.h"

int cub3d_start()
{
    update();
    render();
    mlx_put_image_to_window(game.mlx, game.win, game.img, 0, 0);
    mlx_put_image_to_window(game.mlx, game.win2, game.img2, 0, 0);
    return (0);
}