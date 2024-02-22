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

void	handle_that_bitch(int signal)
{
	// when receiving a Signal transform the bit passed frol client
	// make an int of value o and pass the bit value into it
	static int bit;
	static int storage;
	if(signal == SIGUSR1)//olny enter if one if found in client
	{
		storage |= (1 << bit);
	}
	bit++;
	if(bit == 8)
	{
		printf("%c", storage);
		bit = 0;
		storage = 0;//not neede its redudant but its good practice, wtf
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
	printf("Pleas
	
	e wait for signal motherfucker\n");
	while (argc == 1)
	{
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
		pause();
	}
	
	return 0;
}