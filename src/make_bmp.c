/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:11:38 by sanghpar          #+#    #+#             */
/*   Updated: 2021/01/04 14:11:40 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	make_header(int fd, int width, int height)
{
	unsigned char	header[54];
	int				size;
	unsigned char	aa[2];
	unsigned int	*tmp;

	aa[0] = 66;
	aa[1] = 77;
	size = width * height * 4;
	ft_memset(header, 0, 54);
	ft_memcpy(header, aa, 2);
	tmp = (unsigned int *)&header[2];
	*tmp = 54 + size;
	tmp = (unsigned int *)&header[10];
	*tmp = 54;
	tmp = (unsigned int *)&header[14];
	*tmp = 40;
	tmp = (unsigned int *)&header[18];
	*tmp = width;
	tmp = (unsigned int *)&header[22];
	*tmp = height;
	tmp = (unsigned int *)&header[26];
	*tmp = 1;
	tmp = (unsigned int *)&header[28];
	*tmp = g_game.img2->bpp;
	write(fd, header, 54);
}

void	write_data(int fd, int width, int height)
{
	int x;
	int y;

	y = height;
	while (y >= 0)
	{
		x = 0;
		while (x < width)
		{
			write(fd, &g_game.img2->data[get_calc_index2(x, y, g_game.img2)],
				4);
			x++;
		}
		y--;
	}
}
