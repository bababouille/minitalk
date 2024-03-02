/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vade-oli <vade-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:43:31 by vade-oli          #+#    #+#             */
/*   Updated: 2024/03/01 12:43:31 by vade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

void	handle_that_bitch(int signal)
{
	static int	bit;
	static int	storage;

	if (signal == SIGUSR1)
	{
		storage |= (1 << bit);
	}
	bit++;
	if (bit == 8)
	{
		if (storage == 0)
		{
			exit(0);
		}
		ft_printf("%c", storage);
		bit = 0;
		storage = 0;
	}
}

void	sender(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)) != 0)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				perror("Error sending SIGUSR1");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				perror("Error sending SIGUSR2");
				exit(EXIT_FAILURE);
			}
		}
		bit++;
		usleep(100);
	}
}

void	senderpid(int pid, pid_t my_pid)
{
	int	bit;

	bit = 0;
	while ((size_t)bit < (sizeof(my_pid) * 8))
	{
		if ((my_pid & (1 << bit)) != 0)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				perror("Error sending SIGUSR1");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				perror("Error sending SIGUSR1");
				exit(EXIT_FAILURE);
			}
		}
		bit++;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	pid_t	my_pid;
	int		pid;
	int		x;

	my_pid = getpid();
	x = 0;
	if (argc == 3)
	{
		signal(SIGUSR1, handle_that_bitch);
		signal(SIGUSR2, handle_that_bitch);
		pid = ft_atoi(argv[1]);
		while (argv[2][x] != '\0')
			sender(pid, argv[2][x++]);
		sender(pid, '\n');
		sender(pid, 0);
		senderpid(pid, my_pid);
		while (1)
			pause();
	}
	else
	{
		ft_printf("try ./a.out [pid from server] ['message']\n");
		return (1);
	}
}
