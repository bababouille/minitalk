
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

int main(int argc, char **argv)
{
	int pid;
	int x = 0;
	
	if (argc == 3)
	{
		pid = atoi(argv[1]);
		while(argv[2][x] != '\0')
		{
			sender(pid, argv[2][x]);
			x++;
		}
		sender(pid, '\n');
	}
	else
	{
		printf("try ./a.out [pid from server] ['message']\n");
		return 1;
	}
}