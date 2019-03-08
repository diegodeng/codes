#include "lib.h"

int main(int argc, char *argv[])
{
	int listenfd, connfd;
	struct sockaddr_in servaddr;
	char buff[MAXLINE];
	time_t ticks;
	
	listenfd = Socket(AF_INET,SOCK_STREAM,0);
	
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(6666);
	
	Bind(listenfd,(SA *)&servaddr,sizeof(servaddr));
	
	Listen(listenfd,LISTENQ);  
	logd("listen began ......\r\n");
	for( ; ; ){
		connfd = Accept(listenfd,(SA *)NULL, NULL);
		ticks = time(NULL);
		snprintf(buff,sizeof(buff),"%.24s\r\n",ctime(&ticks));
		Write(connfd,buff,strlen(buff));

		Close(connfd);
	}
	
	Close(listenfd);
    return 0;
}
