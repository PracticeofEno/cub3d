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

int	main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
		return (-1);
	else
	{
		if (!(fd = open(argv[1], O_RDONLY)))
		{
			printf("\nError in open\n");
			return (-1);
		}
		if (cub_parse(fd) == -1)
		{
			printf("\nError in parsing\n");
			return (-1);
		}
		if (setting() == -1)
			return (-1);
		mlx_loop_hook(game.mlx, cub3d_start, 0);
		mlx_loop(game.mlx);
	}
	return (0);
}
