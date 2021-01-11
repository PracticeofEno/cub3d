/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_util1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 04:52:14 by sanghpar          #+#    #+#             */
/*   Updated: 2021/01/10 04:55:37 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			check_sp_list(t_list *tmp, t_ray ray)
{
	int		x;
	int		y;
	t_ray	*l_ray;

	while (tmp)
	{
		l_ray = (t_ray *)(tmp)->content;
		x = (int)(floor(ray.hit.x) / g_tile_size);
		y = (int)(floor(ray.hit.y) / g_tile_size);
		if (l_ray->hit.x == x && l_ray->hit.y == y)
			return (-1);
		tmp = (tmp)->next;
	}
	return (1);
}

void		make_sp_list(t_list **sp_list)
{
	int		i;

	i = 0;
	while (i < g_num_rays)
	{
		if (g_sp_rays[i].hit_tf == true &&
			g_sp_rays[i].distance < g_rays[i].distance)
		{
			if (check_sp_list(*sp_list, g_sp_rays[i]) == 1)
			{
				g_sp_rays[i].hit.x = (int)(floor(g_sp_rays[i].hit.x) /
					g_tile_size);
				g_sp_rays[i].hit.y = (int)(floor(g_sp_rays[i].hit.y) /
					g_tile_size);
				ft_lstadd_back(sp_list, ft_lstnew((void *)&g_sp_rays[i]));
			}
		}
		i++;
	}
}

void		sort_list(t_list **sp_list)
{
	int		count;
	void	*swap;
	int		i;
	t_list	*tmg_p2;

	i = 0;
	tmg_p2 = *sp_list;
	count = ft_lstsize(tmg_p2);
	while (i < count && count > 1)
	{
		tmg_p2 = *sp_list;
		while (tmg_p2 && tmg_p2->next)
		{
			if (((t_ray *)tmg_p2->content)->distance <
					((t_ray *)tmg_p2->next->content)->distance)
			{
				swap = tmg_p2->content;
				tmg_p2->content = tmg_p2->next->content;
				tmg_p2->next->content = swap;
			}
			tmg_p2 = tmg_p2->next;
		}
		i++;
	}
}

void		draw_sprite(void)
{
	t_list	*sp_list;
	t_list	*tmp;

	sp_list = 0x00;
	make_sp_list(&sp_list);
	if (sp_list)
		sort_list(&sp_list);
	set_distance(sp_list);
	test(sp_list);
	while (sp_list)
	{
		tmp = sp_list;
		sp_list = sp_list->next;
		free(tmp);
	}
}
