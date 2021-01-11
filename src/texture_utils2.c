/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:12:05 by sanghpar          #+#    #+#             */
/*   Updated: 2021/01/04 14:12:06 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_color2(unsigned char *dp, unsigned char *color)
{
	int i;

	i = 4;
	while (i--)
		*(dp + i) = *(color + i);
}

t_img	*dl_tex(int x, int y, t_ray ray, int index)
{
	double	mx;
	double	my;
	double	kx;
	double	ky;
	t_img	*tex;

	mx = fmod(ray.hit.x, g_tile_size);
	my = fmod(ray.hit.y, g_tile_size);
	if (mx == 0)
	{
		tex = g_texture.we;
		ky = tex->height / g_p2.y;
		kx = tex->width / g_tile_size;
		ft_memmove(&g_game.img2->data[index],
&tex->data[get_calc_index2(tex->width - my * kx, (y + (x - x)) * ky, tex)], 4);
	}
	else if (my == 0)
	{
		tex = g_texture.so;
		ky = tex->height / g_p2.y;
		kx = tex->width / g_tile_size;
		ft_memmove(&g_game.img2->data[index],
&tex->data[get_calc_index2(tex->width - mx * kx, y * ky, tex)], 4);
	}
	return (0);
}

t_img	*dr_tex(int x, int y, t_ray ray, int index)
{
	double	mx;
	double	my;
	double	kx;
	double	ky;
	t_img	*tex;

	mx = fmod(ray.hit.x, g_tile_size);
	my = fmod(ray.hit.y, g_tile_size);
	if (mx == 0)
	{
		tex = g_texture.ea;
		ky = tex->height / g_p2.y;
		kx = tex->width / g_tile_size;
		ft_memmove(&g_game.img2->data[index],
&tex->data[get_calc_index2(my * kx, (y + (x - x)) * ky, tex)], 4);
	}
	else if (my == 0)
	{
		tex = g_texture.so;
		ky = tex->height / g_p2.y;
		kx = tex->width / g_tile_size;
		ft_memmove(&g_game.img2->data[index],
&tex->data[get_calc_index2(tex->width - mx * kx, y * ky, tex)], 4);
	}
	return (0);
}

t_img	*ul_tex(int x, int y, t_ray ray, int index)
{
	double	mx;
	double	my;
	double	kx;
	double	ky;
	t_img	*tex;

	mx = fmod(ray.hit.x, g_tile_size);
	my = fmod(ray.hit.y, g_tile_size);
	if (my == 0)
	{
		tex = g_texture.no;
		ky = tex->height / g_p2.y;
		kx = tex->width / g_tile_size;
		ft_memmove(&g_game.img2->data[index],
&tex->data[get_calc_index2(mx * kx, y * ky, tex)], 4);
	}
	else if (mx == 0)
	{
		tex = g_texture.we;
		ky = tex->height / g_p2.y;
		kx = tex->width / g_tile_size;
		ft_memmove(&g_game.img2->data[index],
&tex->data[get_calc_index2(tex->width - my * kx, (y + (x - x)) * ky, tex)], 4);
	}
	return (0);
}

t_img	*ur_tex(int x, int y, t_ray ray, int index)
{
	double	mx;
	double	my;
	double	kx;
	double	ky;
	t_img	*tex;

	mx = fmod(ray.hit.x, g_tile_size);
	my = fmod(ray.hit.y, g_tile_size);
	if (my == 0)
	{
		tex = g_texture.no;
		ky = tex->height / g_p2.y;
		kx = tex->width / g_tile_size;
		ft_memmove(&g_game.img2->data[index],
&tex->data[get_calc_index2(mx * kx, y * ky, tex)], 4);
	}
	else if (mx == 0)
	{
		tex = g_texture.ea;
		ky = tex->height / g_p2.y;
		kx = tex->width / g_tile_size;
		ft_memmove(&g_game.img2->data[index],
&tex->data[get_calc_index2(my * kx, (y + (x - x)) * ky, tex)], 4);
	}
	return (0);
}
