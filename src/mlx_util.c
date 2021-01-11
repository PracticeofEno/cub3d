/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:11:43 by sanghpar          #+#    #+#             */
/*   Updated: 2021/01/04 14:12:45 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_t_point(double x1, double y1, double x2, double y2)
{
	g_p1.x = x1;
	g_p1.y = y1;
	g_p2.x = x2;
	g_p2.y = y2;
}

int		get_color(int r, int g, int b)
{
	int color;
	int color2;

	color = (b) + (r << 16) + (g << 8);
	color2 = mlx_get_color_value(g_game.mlx, color);
	return (color2);
}

void	set_color(unsigned char *dp, int color)
{
	int i;

	i = 4;
	while (i--)
		*(dp + i) = ((unsigned char *)(&color))[i];
}

int		get_calc_index(int x, int y)
{
	int index;

	index = 0;
	index = (y) * g_game.img->size_line;
	index = index + (x * (g_game.img->bpp / 8));
	return (index);
}

void	draw_line(t_game g_game, t_point *g_p1, t_point *g_p2, int color)
{
	double dx;
	double dy;
	double step;

	dx = g_p2->x - g_p1->x;
	dy = g_p2->y - g_p1->y;
	if (fabs(dx) > fabs(dy))
		step = abs(dx);
	else
		step = abs(dy);
	dx = dx / step;
	dy = dy / step;
	while (fabs(g_p2->x - g_p1->x) > 0.00001 ||
		fabs(g_p2->y - g_p1->y) > 0.00001)
	{
		set_color((unsigned char *)&g_game.img->data[
			get_calc_index((int)g_p1->x, (int)(g_p1->y))], color);
		g_p1->x = g_p1->x + dx;
		g_p1->y = g_p1->y + dy;
	}
}
