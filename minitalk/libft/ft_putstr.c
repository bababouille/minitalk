/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vade-oli <vade-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:12:19 by vade-oli          #+#    #+#             */
/*   Updated: 2024/03/02 16:01:16 by vade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *x, int *len)
{
	int	index;

	index = 0;
	if (!x)
	{
		*len += write(1, "(null)", 6);
		return ;
	}
	while (x[index] != '\0')
	{
		write(1, &x[index], 1);
		*len += 1;
		index++;
	}
}
