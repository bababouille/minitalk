/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:23:29 by marvin            #+#    #+#             */
/*   Updated: 2024/02/20 14:23:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void	sender(int pid, char c)
{
	int bit;
	bit = 0;
	// x = 	00000000
	// c = 	01010101
	// check c for 1 and send sigusr1 if correct
	// doit bit by bit
	
	while(bit < 8)
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

void	handle_that_bitch(int signal)
{
	// when receiving a Signal transform the bit passed from client
	// make an int of value 0 and pass the bit value into it
	static int bit;
	static int storage;
	static int x;


	if(signal == SIGUSR1)//only enter if 1 is found in client
	{
		storage |= (1 << bit);
	}
	bit++;
	if(bit == 8 && x == 0)
	{
		if (storage == 0)
		{
			x = 1;
		}
		printf("%c", storage);
		bit = 0;
		storage = 0;
	}
	if (bit == (sizeof(pid_t) * 8) && x == 1)//pid_t = 4 byte so 32 bit( sizeof because i am a cool boy)
	{
		//printf("%u\n", storage);
		char nikita[] = "message accepted you motherfucker";
		int n = 0;
		while(nikita[n])
		{
			sender(storage, nikita[n]);
			n++;
		}
		sender(storage, '\n');
		sender(storage, 0);
		x = 0;
		bit = 0;
		storage = 0;
	}
	
}
int main(int argc, char**argv)
{
	(void)argv;
	pid_t pid;
	pid = getpid();
	if (argc != 1)
	{
		printf("No entry allowed from server\n");
		return 0;
	}
	printf("My beautifull pid is: %d\n", pid);
	printf("Please wait for signal motherfucker\n");
	
		//signal() returns a function pointer (SIG_ERR or a pointer to the previous signal handler)
		if(signal(SIGUSR1, handle_that_bitch) == SIG_ERR)
		{
			perror("Error setting up signal handler for SIGUSR1");
        	exit(EXIT_FAILURE);
		}
		else if(signal(SIGUSR2, handle_that_bitch) == SIG_ERR)
		{
			perror("Error setting up signal handler for SIGUSR1");
        	exit(EXIT_FAILURE);
		}
	while (argc == 1)
	{	
		pause();
	}
	return 0;
}