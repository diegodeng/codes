#ifndef _LIB_H_
#define _LIB_H_

#include	<sys/types.h>	/* basic system data types */
#include	<sys/socket.h>	/* basic socket definitions */
#include	<sys/time.h>	/* timeval{} for select() */
#include	<time.h>		/* timespec{} for pselect() */
#include	<sys/time.h>	/* includes <time.h> unsafely */
#include	<time.h>		/* old system? */
#include	<netinet/in.h>	/* sockaddr_in{} and other Internet defns */
#include	<arpa/inet.h>	/* inet(3) functions */
#include	<errno.h>
#include	<fcntl.h>		/* for nonblocking */
#include	<netdb.h>
#include	<signal.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<sys/stat.h>	/* for S_xxx file mode constants */
#include	<sys/uio.h>		/* for iovec{} and readv/writev */
#include	<unistd.h>
#include	<sys/wait.h>
#include	<sys/un.h>		/* for Unix domain sockets */
#include	<sys/select.h>	/* for convenience */
#include	<sys/param.h>	/* OpenBSD prereq for sysctl.h */
#include	<sys/sysctl.h>
#include	<poll.h>		/* for convenience */
#include	<strings.h>		/* for convenience */
/* Three headers are normally needed for socket/file ioctl's:
 * <sys/ioctl.h>
 */
#include	<sys/ioctl.h>
#include	<pthread.h>
#include	<sys/mman.h>


#define logd printf

/* Following could be derived from SOMAXCONN in <sys/socket.h>, but many
   kernels still #define it as 5, while actually supporting many more */
#define	LISTENQ		1024	/* 2nd argument to listen() */
/* Miscellaneous constants */
#define	MAXLINE		4096	/* max text line length */
#define	BUFFSIZE	8192	/* buffer size for reads and writes */
#define	SERV_PORT		 9988			/* TCP and UDP */
#define	SERV_PORT_STR	"9988"			/* TCP and UDP */

/* Following shortens all the typecasts of pointer arguments: */
#define	SA	struct sockaddr

/*
 * Standard I/O wrapper functions
 */
void Fclose(FILE *fp);
FILE * Fdopen(int fd, const char *type);
char * Fgets(char *ptr, int n, FILE *stream);
FILE * Fopen(const char *filename, const char *mode);
void Fputs(const char *ptr, FILE *stream);


/*
 * Socket wrapper functions.
 */
int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr);
void Bind(int fd, const struct sockaddr *sa, socklen_t salen);
void Connect(int fd, const struct sockaddr *sa, socklen_t salen);
void Getpeername(int fd, struct sockaddr *sa, socklen_t *salenptr);
void Getsockname(int fd, struct sockaddr *sa, socklen_t *salenptr);
void Getsockopt(int fd, int level, int optname, void *optval, socklen_t *optlenptr);
void Listen(int fd, int backlog);
int Poll(struct pollfd *fdarray, unsigned long nfds, int timeout);
ssize_t Recv(int fd, void *ptr, size_t nbytes, int flags);
ssize_t Recvfrom(int fd, void *ptr, size_t nbytes, int flags,
		 struct sockaddr *sa, socklen_t *salenptr);
ssize_t Recvmsg(int fd, struct msghdr *msg, int flags);
int Select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds,
       struct timeval *timeout);
void Send(int fd, const void *ptr, size_t nbytes, int flags);
void Sendto(int fd, const void *ptr, size_t nbytes, int flags,
	   const struct sockaddr *sa, socklen_t salen);
void Sendmsg(int fd, const struct msghdr *msg, int flags);
void Setsockopt(int fd, int level, int optname, const void *optval, socklen_t optlen);
void Shutdown(int fd, int how);
int Sockatmark(int fd);
int Socket(int family, int type, int protocol);


/*
 * unix wrapper functions.
 */
void * Calloc(size_t n, size_t size);
void Close(int fd);
void Dup2(int fd1, int fd2);
int Fcntl(int fd, int cmd, int arg);
void Gettimeofday(struct timeval *tv, void *foo);
int Ioctl(int fd, int request, void *arg);
pid_t Fork(void);
void * Malloc(size_t size);
void * Mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset);
int Open(const char *pathname, int oflag, mode_t mode);
void Pipe(int *fds);
ssize_t Read(int fd, void *ptr, size_t nbytes);
void Sigaddset(sigset_t *set, int signo);
void Sigdelset(sigset_t *set, int signo);
void Sigemptyset(sigset_t *set);
void Sigfillset(sigset_t *set);
int Sigismember(const sigset_t *set, int signo);
void Sigpending(sigset_t *set);
void Sigprocmask(int how, const sigset_t *set, sigset_t *oset);
char * Strdup(const char *str);
long Sysconf(int name);
void Unlink(const char *pathname);
pid_t Wait(int *iptr);
pid_t Waitpid(pid_t pid, int *iptr, int options);
void Write(int fd, void *ptr, size_t nbytes);
const char *
Inet_ntop(int family, const void *addrptr, char *strptr, size_t len);
void
Inet_pton(int family, const char *strptr, void *addrptr);

/*
 * merge some row funciton for protocal independent
 */
char *Sock_ntop(const struct sockaddr *sa, socklen_t salen);
void Writen(int fd, void *ptr, size_t nbytes);
ssize_t Readn(int fd, void *ptr, size_t nbytes);
ssize_t Readline(int fd, void *ptr, size_t maxlen);

/* 
 * prototypes for our own library functions 
 */
void str_echo(int sockfd);
void str_cli(FILE *, int);


#endif /*_LIB_H_*/
