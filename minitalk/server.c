/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/02/20 14:23:29 by marvin            #+#    #+#             */
/*   Updated: 2024/02/20 14:23:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

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
				perror("Error sending SIGUSR1");
				exit(EXIT_FAILURE);
			}
		}
		bit++;
		usleep(100);
	}
}

void	cutter(int storage)
{
	int			n;
	char		*nikita;

	nikita = "message accepted you motherfucker";
	n = 0;
	while (nikita[n])
		sender(storage, nikita[n++]);
	sender(storage, '\n');
	sender(storage, 0);
}

void	handle_that_bitch(int signal)
{
	static int	bit;
	static int	storage;
	static int	x;	

	if (signal == SIGUSR1)
		storage |= (1 << bit);
	bit++;
	if (bit == 8 && x == 0)
	{
		if (storage == 0)
			x = 1;
		ft_printf("%c", storage);
		bit = 0;
		storage = 0;
	}
	if (bit == (sizeof(pid_t) * 8) && x == 1)
	{
		cutter(storage);
		x = 0; 
		bit = 0; 
		storage = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	(void)argv;
	pid = getpid();
	if (argc != 1)
	{
		ft_printf("No entry allowed from server\n");
		return (0);
	}
	ft_printf("My beautifull pid is: %d\n", pid);
	ft_printf("Please wait for signal motherfucker\n");
	signal(SIGUSR1, handle_that_bitch);
	signal(SIGUSR2, handle_that_bitch);
	while (argc == 1)
	{
		pause();
	}
	return (0);
}
