#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

/**
 *  int pipe(int pipefd[2]);
 *  return 0 if success, otherwise return -1
 * */

int main(int argc, char *argv[])
{
	int fd[2];
	pid_t pid;
	int ret ;
	char buf;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <string>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	ret = pipe(fd);  //create pipe fd 
	if( ret == -1){
		perror("pipe error");
		return -1;
	}

	pid = fork();
	if(pid == -1){
		perror("fork error");
		return -1;
	}

	if(pid == 0){ /*Child proc*/
		printf("I'm the Child proc my pid is %d, and ppid is %d \n",getpid(),getppid());
		close(fd[1]);							/*Child proc close unused write fd[1]  */
		while(read(fd[0], &buf, 1) > 0){		/*Read from pipe fd[0]*/
			write(STDOUT_FILENO, &buf, 1);
		}
		write(STDOUT_FILENO, "\n", 1);
		close(fd[0]);
		printf("Child proc exit \n");
		exit(EXIT_SUCCESS);

	}else { /*father proc*/
		printf("I'm the father proc my pid is %d \n",getpid());
		close(fd[0]);							/* Close unused read end */
		write(fd[1],argv[1],strlen(argv[1]));	/* Parent writes argv[1] to pipe*/
        close(fd[1]);							/* Reader will see EOF */
        wait(NULL);								/* Wait for child */
		printf("Parent proc exit \n");
        exit(EXIT_SUCCESS);
	}
	return 0;
}
