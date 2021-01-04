/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:11:24 by sanghpar          #+#    #+#             */
/*   Updated: 2021/01/04 14:11:26 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_player(t_game *game, int x, int y)
{
    int i;
    int j;
    int index;
    int x_index;

    i = 0;
    index = 0;
    while (i < 2)
    {
        index = (y + i) * game->img->size_line;
        index = index + (x * (game->img->bpp / 8));
        j = 0;
        while (j < 2)
        {
            x_index = (j * (game->img->bpp / 8));
            set_color((unsigned char *)&game->img->data[index + x_index], 0xFF0000);
            j++;
        }
        i++;
    }
}

void player_render()
{
    draw_player(&game, player.x, player.y);
    //set_t_point(player.x, player.y, (int)(player.x +
      //  cos(player.rotation_angle) * 30),(int)(player.y + sin(player.rotation_angle) * 30));
    //draw_line(&p1, &p2, get_color(0,255,0));
}

void player_update()
{
    double move_step;
    double new_x;
    double new_y;

    player.rotation_angle += player.turn_direction * player.rotation_speed;
    move_step = player.walk_direction * player.move_speed;
    new_x = player.x + cos(player.rotation_angle) * move_step;
    new_y = player.y + sin(player.rotation_angle) * move_step;
    if (!is_wall(new_x + 3, new_y + 3) && !is_wall(new_x - 3, new_y - 3))
    {
        player.x = new_x;
        player.y = new_y;
    }
}

int key_pressed(int key, void *p)
{
    temp(p);
    if (key == 119)
        player.walk_direction = 1;
    else if (key == 115)
        player.walk_direction = -1;
    else if (key == 97)
        player.turn_direction = -1;
    else if (key == 100)
        player.turn_direction = 1;
    return (0);
}

int key_released(int key, void *p)
{
    temp(p);
    if (key == 119)
     player.walk_direction = 0;
    else if (key == 115)
        player.walk_direction = 0;
    else if (key == 97)
        player.turn_direction = 0;
    else if (key == 100)
        player.turn_direction = 0;
    else if (key == 65307)
        exit(1);
    return (0);
}
