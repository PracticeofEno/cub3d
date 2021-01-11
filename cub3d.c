/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 04:41:19 by sanghpar          #+#    #+#             */
/*   Updated: 2021/01/10 04:42:18 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save_bmp(void)
{
	int		fd;

	update();
	render();
	mlx_put_image_to_window(g_game.mlx, g_game.win, g_game.img, 0, 0);
	mlx_put_image_to_window(g_game.mlx, g_game.win2, g_game.img2, 0, 0);
	if (!(fd = open("save.bmp", O_WRONLY | O_CREAT | O_TRUNC)))
		exit(1);
	make_header(fd, g_game.img2->width, g_game.img2->height);
	write_data(fd, g_game.img2->width, g_game.img2->height);
	close(fd);
}

int		check_save(char *argv)
{
	int fd;

	if (!(fd = open(argv, O_RDONLY)))
	{
		ft_putstr("file open error");
		exit(1);
	}
	if (cub_parse(fd) == -1)
	{
		ft_putstr("Error\n");
		exit(1);
	}
	if (setting() == -1)
	{
		ft_putstr("Error\n");
		exit(1);
	}
	return (fd);
}

int		check_save2(char *argv1, char *argv2)
{
	int fd;

	if (!(fd = open(argv1, O_RDONLY)))
	{
		ft_putstr("file open error");
		exit(1);
	}
	if (cub_parse(fd) == -1)
	{
		ft_putstr("Error\n");
		exit(1);
	}
	if (setting() == -1)
	{
		ft_putstr("Error\n");
		exit(1);
	}
	if (ft_strcmp(argv2, "--save") == 0)
	{
		save_bmp();
		exit(1);
	}
	return (fd);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
	{
		check_save2(argv[1], argv[2]);
		return (-1);
	}
	else if (argc == 2)
	{
		check_save(argv[1]);
		mlx_loop_hook(g_game.mlx, cub3d_start, 0);
		mlx_loop(g_game.mlx);
	}
	return (0);
}
