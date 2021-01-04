/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:11:38 by sanghpar          #+#    #+#             */
/*   Updated: 2021/01/04 14:11:40 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int cub3d_start()
{
    update();
    render();
    mlx_put_image_to_window(game.mlx, game.win, game.img, 0, 0);
    mlx_put_image_to_window(game.mlx, game.win2, game.img2, 0, 0);
    return (0);
}
