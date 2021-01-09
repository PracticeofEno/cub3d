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

int		check_sp_list(t_list *tmp, t_ray ray)
{
	int		x;
	int		y;
	t_ray	*l_ray;

	while (tmp)
	{
		l_ray = (t_ray *)(tmp)->content;
		x = (int)(floor(ray.hit.x) / tile_size);
		y = (int)(floor(ray.hit.y) / tile_size);
		if (l_ray->hit.x == x && l_ray->hit.y == y)
			return (-1);
		tmp = (tmp)->next;
	}
	return (1);
}

void	make_sp_list(t_list **sp_list)
{
	int	i;

	i = 0;
    while (i < num_rays)
    {
		if (sp_rays[i].hit_tf == true && sp_rays[i].distance < rays[i].distance)
		{
			if (check_sp_list(*sp_list, sp_rays[i]) == 1)
			{
				sp_rays[i].hit.x = (int)(floor(sp_rays[i].hit.x) / tile_size);
				sp_rays[i].hit.y = (int)(floor(sp_rays[i].hit.y) / tile_size);
				ft_lstadd_back(sp_list, ft_lstnew((void *)&sp_rays[i]));
			}
		}
        i++;
    }
}

void	sort_list(t_list **sp_list)
{
	int		count;
	void	*swap;
	int		i;
	t_list	*tmp2;

	i = 0;
	tmp2 = *sp_list;
	count = ft_lstsize(tmp2);
	while (i < count && count > 1)
	{
		tmp2 = *sp_list;
		while (tmp2 && tmp2->next)
		{
			if (((t_ray *)tmp2->content)->distance <
					((t_ray *)tmp2->next->content)->distance)
			{
				swap = tmp2->content;
				tmp2->content = tmp2->next->content;
				tmp2->next->content = swap;
			}
			tmp2 = tmp2->next;
		}
		i++;
	}
}

void	draw_sprite()
{
	t_list *sp_list;

	sp_list = 0x00;
	make_sp_list(&sp_list);
	if (sp_list)
		sort_list(&sp_list);
	set_distance(sp_list);
	test(sp_list);
}
