#include "lib.h"

int main(int argc, char *argv[])
{
	int					sockfd, n;
	char				recvline[MAXLINE + 1];
	struct sockaddr_in	servaddr;

	if (argc != 2)
		logd("usage: a.out <IPaddress>\r\n");

	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		logd("socket error\r\n");

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port   = htons(6666);	/* daytime server */
	if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
		logd("inet_pton error for %s\r\n", argv[1]);

	if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
		logd("connect error\r\n");

	while ( (n = read(sockfd, recvline, MAXLINE)) > 0) {
		recvline[n] = 0;	/* null terminate */
		if (fputs(recvline, stdout) == EOF)
			logd("fputs error\r\n");
	}
	if (n < 0)
		logd("read error\r\n");

	exit(0);
}
