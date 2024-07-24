#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// int main(int ac , char **av, char **env)
// {

// if (printf("%d \n " ,access("/nfs/homes/asebaai/Desktop/pipe/t/apa.txt",
			X_OK)))
			{
				//     printf("Nqdr nqra l fichier\n");
				// } else {
				//     perror("bash ");
				// }
				// }

				// int main()
				// {
				//     char *str = malloc(2);
				//     str[0] = 'd';
				//     str[1] = 0;
				//     printf("%p\n", str);
				//     printf("%s\n", str);
				//     pid_t pid = fork();
				// if (pid < 0) {
				//     // Error occurred
				//     fprintf(stderr, "Fork failed\n");
				//     return (1);
				// } else if (pid == 0) {
				//     // Child processp
				//     printf("im a child :%p\n", str);
				//     str[0] = 'x';
				//     printf("im a child :%s\n", str);

				// }else
				// {
				//     printf("im a parent :%s\n", str);
				//     while(1);
				// }
				// }

				// #include <fcntl.h>

				// int main() {
				//     int fd = open("file.txt", O_WRONLY | O_CREAT, 0644);
				//     dup2(fd, STDOUT_FILENO);
				//     close(fd);

				//     printf("Had l ktiba ghadi tmchi l file.txt\n");
				//     return (0);
				// }

				// #include <fcntl.h>

				// int main() {
				//     int fd = open("output.txt", O_WRONLY | O_CREAT, 0644);

				//     if (fork() == 0) {  // Child process
				//         dup2(fd, STDOUT_FILENO);
				//         close(fd);
				//         execlp("ls", "ls", NULL);
				//     }

				//     close(fd);
				//     wait(NULL);
				//     return (0);
				// }

				// int main() {
				//     pid_t pid = fork();

				//     if (pid == -1) {
				//         perror("fork");
				//         return (1);
				//     } else if (pid == 0) {
				//         // Child process
				//         char *args[] = {"ls", "-l", NULL};
				//         char *env[] = {NULL};

				//         execve("/bin/ls", args, env);

				//         // Ila wselna l hna, kayn chi mochkil
				//         perror("execve");
				//         return (1);
				//     } else {
				//         // Parent process
				//         printf("L child process PID: %d\n", pid);
				//         wait(NULL);
				//         printf("L child process sala\n");
				//     }

				//     return (0);
				// }

				// #include <unistd.h>
				// #include <stdio.h>
				// #include <string.h>

				// int main() {
				//     int pipefd[2];
				//     char buf[20];

				//     if (pipe(pipefd) == -1) {
				//         perror("pipe");
				//         return (1);
				//     }

				//     write(pipefd[1], "Salam!", 7);
				//     read(pipefd[0], buf, 7);

				//     printf("9rit men l pipe: %s\n", buf);

				//     close(pipefd[0]);
				//     close(pipefd[1]);

				//     return (0);
				// }

				// #include <unistd.h>
				// #include <stdio.h>
				// #include <string.h>

				// int main() {
				//     int pipefd[2];
				//     pid_t pid;
				//     char buf[20];

				//     if (pipe(pipefd) == -1) {
				//         perror("pipe");
				//         return (1);
				//     }

				//     pid = fork();

				//     if (pid == -1) {
				//         perror("fork");
				//         return (1);
				//     } else if (pid == 0) {  // Child process
				//         close(pipefd[1]);  // Close unused write end
				//         read(pipefd[0], buf, 20);
				//         printf("L child 9ra: %s\n", buf);
				//         close(pipefd[0]);
				//     } else {  // Parent process
				//         close(pipefd[0]);  // Close unused read end
				//         write(pipefd[1], "Salam men l parent!", 20);
				//         close(pipefd[1]);
				//         wait(NULL);
				//     }

				//     return (0);
				// }

				// #include <unistd.h>
				// #include <stdio.h>

				// int main() {
				//     if (unlink("/bin/mount") == -1) {
				//         perror("unlink");
				//         return (1);
				//     }
				//     printf("L fichier tsupprima b nja7\n");
				//     return (0);
				// }

				// #include <unistd.h>
				// #include <fcntl.h>
				// #include <stdio.h>

				// int main() {
				//     int fd = open("/nfs/homes/asebaai/Desktop/pipe/t/temp_file.txt",
		O_CREAT | O_RDWR, 0644);
		//     if (fd == -1) {
		//         perror("open");
		//         return (1);
		//     }
		//     // Knsupprimi l fichier, walakin mazal mfto7
		//     if (unlink("/nfs/homes/asebaai/Desktop/pipe/t/temp_file.txt") ==
			-1) {
		//         perror("unlink");
		//         close(fd);
		//         return (1);
		//     }

		//     // Mazal n9der nkteb f l fichier
		//     write(fd, "Salam", 5);

		//     // Melli ghadi nsed l fichier, l'espace dyalo ghadi yt7rer
		//     close(fd);

		//     printf("L fichier tsupprima,
			walakin 9derna nktbo fih 9bel ma ytsed\n");
		//     return (0);
		// }

		// #include <sys/wait.h>
		// #include <unistd.h>
		// #include <stdio.h>

		// int main() {
		//     pid_t pid = fork();

		//     if (pid == -1) {
		//         perror("fork");
		//         return (1);
		//     } else if (pid == 0) {
		//         // Child process
		//         printf("Ana l child process (PID: %d)\n", getpid());
		//         sleep(2);
		//         return (-1);
		//     } else {
		//         // Parent process
		//         int status;
		//         pid_t child_pid = waitpid(pid, &status, 0);

		//         if (child_pid == -1) {
		//             perror("waitpid");
		//             return (1);
		//         }

		//         if (WEXITSTATUS(status)) {
		//             printf("L child (PID: %d) 5rej b status: %d\n",
			child_pid,
	WEXITSTATUS(status));
	//         }
	//     }

	//     return (0);
	// }