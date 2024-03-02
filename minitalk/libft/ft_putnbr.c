/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vade-oli <vade-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:49:23 by vade-oli          #+#    #+#             */
/*   Updated: 2024/03/02 16:01:08 by vade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(long x, int *len)
{
	if (x < 0)
	{
		ft_putchar('-', len);
		x *= -1;
	}
	if (x > 9)
	{
		ft_putnbr(x / 10, len);
		ft_putnbr(x % 10, len);
	}
	else
		ft_putchar(x + '0', len);
}
