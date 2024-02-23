
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define DEBUG 0  // Set this to 1 to enable debugging, 0 to disable

#define debug_printf(fmt, ...) \
            do { if (DEBUG) fprintf(stderr, "[%s:%d] " fmt, __FILE__, __LINE__, ##__VA_ARGS__); } while (0)
void handle_that_bitch(int signal)
{
	static int bit;
	static int storage;

	if(signal == SIGUSR1)//only enter if 1 is found in client
	{
		storage |= (1 << bit);
	}
	bit++;
	if(bit == 8)
	{
		if(storage == 0)
		{
			exit(0);
		}
		printf("%c", storage);
		bit = 0;
		storage = 0;
	}

}
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

void	senderpid(int pid, pid_t my_pid)
{
	int bit;
	bit = 0;
	// x = 	00000000
	// c = 	01010101
	// check c for 1 and send sigusr1 if correct
	// doit bit by bit
	
	while(bit < (sizeof(my_pid)* 8))
	{
		if ((my_pid & (1 << bit)) != 0)
		{
			debug_printf("plus de detail 1\n");
			if (kill(pid, SIGUSR1) == -1)
			{
				perror("Error sending SIGUSR1");
                exit(EXIT_FAILURE);
			}
		}
		else
		{
			debug_printf("plus de detail aussi0\n");
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
	pid_t my_pid;
	my_pid = getpid();
	debug_printf("mon pid %u\n",my_pid);
	
	if (argc == 3)
	{
		if(signal(SIGUSR1, handle_that_bitch) == SIG_ERR)
		{
			perror("Error setting up signal handler for SIGUSR1");
        	exit(EXIT_FAILURE);
		}
		if(signal(SIGUSR2, handle_that_bitch) == SIG_ERR)
		{
			perror("Error setting up signal handler for SIGUSR1");
        	exit(EXIT_FAILURE);
		}
		pid = atoi(argv[1]);
		while(argv[2][x] != '\0')
		{
			sender(pid, argv[2][x]);
			x++;
		}
		sender(pid, '\n');
		sender(pid, 0);
		senderpid(pid, my_pid);

		while (1)
		{
			pause();
		}
	}
	else
	{
		printf("try ./a.out [pid from server] ['message']\n");
		return 1;
	}
}