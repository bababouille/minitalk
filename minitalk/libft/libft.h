/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vade-oli <vade-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:27:25 by vade-oli          #+#    #+#             */
/*   Updated: 2024/03/02 16:39:47 by vade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <signal.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char x, int *len);
void	ft_putstr(char *x, int *len);
void	ft_putnbr(long x, int *len);
void	ft_puthex(unsigned int x, char *b, int *len);
void	ft_putptr(size_t x, int *len);
int		ft_atoi(const char *string);

#endif