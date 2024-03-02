/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vade-oli <vade-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:07:56 by vade-oli          #+#    #+#             */
/*   Updated: 2024/03/02 16:01:00 by vade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(unsigned int x, char *b, int *len)
{
	long int	xx;

	xx = x;
	if (xx / 16 == 0)
		ft_putchar(b[xx % 16], len);
	else
	{
		ft_puthex(xx / 16, b, len);
		ft_putchar(b[xx % 16], len);
	}
}
