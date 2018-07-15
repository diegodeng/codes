#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	int ret = 0;
	int fd,len;
	char buf[1024];

	printf("Process pid = %d \n",getpid());
	
	ret = mkfifo("fifo1",0666);
	if (ret == -1) {
		perror("Creat FIFO Error");
		return -1;
	}

	fd = open("fifo1",O_RDONLY);
	if(fd < 0 ){
		perror("Open fifo1 failed");
		return -1;
	}

	while( (len = read(fd,&buf,1024)) > 0 ) {
		printf("Read message : %s \n",buf);
	}

	close(fd);
	
	return 0;
}
