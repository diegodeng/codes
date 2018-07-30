#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>

#include<netinet/in.h>

#define MAXLINE 4096

/**
 * int socket(int domain, int type, int protocol);
 * vim /etc/protocols see the what means of the number
 */

/**
 * int bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
 * 	         struct sockaddr {
                sa_family_t sa_family;
			    char        sa_data[14];
		     }
	struct sockaddr_in {
	    sa_family_t    sin_family;  address family: AF_INET 
		in_port_t      sin_port;	port in network byte order 
		struct in_addr sin_addr;  	internet address 
	};

 */

/**
 *  int listen(int sockfd, int backlog);
 */

/**
 * int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
 * 
 */

int main(int argc,char *agrv[])
{
	int listenfd, connfd;
	struct sockaddr_in serveraddr;
	char buff[4096];
	int n,ret = 0;

	listenfd = socket(AF_INET,SOCK_STREAM,0);
	if(listenfd == -1){
		 printf("create socket error: %s(errno: %d)\n",strerror(errno),errno);
		 exit(0);
	}
	memset(&serveraddr,0,sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(6666);

	ret = bind(listenfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
	if(ret == -1){
		printf("bind socket error: %s(errno: %d)\n",strerror(errno),errno);
		exit(0);
	}
	
	ret = listen(listenfd,10);
	if(ret == -1){
		printf("listen socket error: %s(errno: %d)\n",strerror(errno),errno);
		exit(0);
	}

	printf("======waiting for client's request======\n");
	while(1){
		connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);
		if(connfd == -1){
			printf("accept socket error: %s(errno: %d)",strerror(errno),errno);
			        continue;
		}
		n = recv(connfd, buff, MAXLINE, 0);
		buff[n] = '\0';
		printf("recv msg from client: %s\n", buff);
		close(connfd);
	}
	
	close(listenfd);
	return 0;
}
