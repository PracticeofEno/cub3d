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

int		cub3d_start(void)
{
	update();
	render();
	mlx_put_image_to_window(game.mlx, game.win, game.img, 0, 0);
	mlx_put_image_to_window(game.mlx, game.win2, game.img2, 0, 0);
	return (0);
}

int		is_sprite(int x, int y)
{
	int x1;
	int y1;

	if (x < 0 || x > map_width * tile_size)
		return (1);
	if (y < 0 || y > map_height * tile_size)
		return (1);
	x1 = floor(x / tile_size);
	y1 = floor(y / tile_size);
	if (map[y1][x1] == '2')
		return (1);
	else
		return (0);
}

int		get_calc_index2(int x, int y, t_img *img)
{
	int index;

	index = 0;
	index = (y) * img->size_line;
	index = index + (x * (img->bpp / 8));
	return (index);
}

int		window_close(void)
{
	exit(1);
	return (0);
}
