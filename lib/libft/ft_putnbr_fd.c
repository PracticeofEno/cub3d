/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 20:20:58 by sanghpar          #+#    #+#             */
/*   Updated: 2020/10/07 03:50:34 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putdig_fd(unsigned int n, int fd)
{
	if (n > 9)
		ft_putdig_fd(n / 10, fd);
	ft_putchar_fd('0' + (n % 10), fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int i;

	if (n < 0 && (i = -n))
	{
		ft_putchar_fd('-', fd);
	}
	else
	{
		i = n;
	}
	ft_putdig_fd(i, fd);
}
