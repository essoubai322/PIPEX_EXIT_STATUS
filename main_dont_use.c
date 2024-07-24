#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(int ac, char **av, char **env)
{
	// char *cmd = "/bin/ls";
	// char **ptr = malloc(2);
	// ptr[0] = malloc (5);
	// ptr[0] = "ls";
	// // ptr[1] = malloc (3);
	// // ptr[1] = "-l";
	// // ptr[2] = malloc (20);
	// // ptr[2] = "-akjefg";
	// ptr[1] = NULL;
	// // int pid = fork();
	// // if (pid == 0)
	// // {
	if (execve("/bin/usr/ls", NULL, env) == -1)
		printf("can't execute\n");
	//     printf("here\n");
	// // }
	// waitpid(pid, NULL, 0);
}