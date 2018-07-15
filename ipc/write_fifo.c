#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>

/**
 * int mkfifo(const char *pathname, mode_t mode);
 */

int main(void)
{
	int i,n, fd ;
	char buf[1024];
	time_t tp;
	
	printf("Process Pid %d\n",getpid());

	fd = open("fifo1",O_WRONLY);
	if( fd == -1){
		perror("open fifo error");
		return -1;
	}
	
	for(i = 0;i < 3; i++){
		time(&tp);
		n = sprintf(buf,"Process %d`s time is %s\n",getpid(),ctime(&tp));
		printf("Send Message %s\n",buf);
		
		if(write(fd,buf,n+1) < 0 ){
			perror("write fifo error");
			close(fd);
			return -1;
		}
		sleep(1);		
	}
	close(fd);
	return 0;
}
