#include "lib.h"

/*
 * Standard I/O wrapper functions
 */
void Fclose(FILE *fp)
{
	if (fclose(fp) != 0)
		logd("fclose error\r\n");
	
}
FILE * Fdopen(int fd, const char *type)
{
	FILE	*fp;

	if ( (fp = fdopen(fd, type)) == NULL)
		logd("fdopen error\r\n");

	return(fp);
}
char * Fgets(char *ptr, int n, FILE *stream)
{
	char	*rptr;

	if ( (rptr = fgets(ptr, n, stream)) == NULL && ferror(stream))
		logd("fgets error\r\n");

	return (rptr);
}
FILE * Fopen(const char *filename, const char *mode)
{
	FILE	*fp;

	if ( (fp = fopen(filename, mode)) == NULL)
		logd("fopen error\r\n");

	return(fp);
}
void Fputs(const char *ptr, FILE *stream)
{
	if (fputs(ptr, stream) == EOF)
		logd("fputs error\r\n");
}

/*
 * Socket wrapper functions.
 */
int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
	int		n;
	
again:
	if ( (n = accept(fd, sa, salenptr)) < 0) {
		if (errno == ECONNABORTED)
			goto again;
		else
			logd("accept error\r\n");
	}
	return(n);
}
void Bind(int fd, const struct sockaddr *sa, socklen_t salen)
{
	if (bind(fd, sa, salen) < 0)
		logd("bind error\r\n");
}
void Connect(int fd, const struct sockaddr *sa, socklen_t salen)
{
	if (connect(fd, sa, salen) < 0)
		logd("connect error\r\n");
}
void Getpeername(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
	if (getpeername(fd, sa, salenptr) < 0)
		logd("getpeername error\r\n");
}
void Getsockname(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
	if (getsockname(fd, sa, salenptr) < 0)
		logd("getsockname error\r\n");
}
void Getsockopt(int fd, int level, int optname, void *optval, socklen_t *optlenptr)
{
	if (getsockopt(fd, level, optname, optval, optlenptr) < 0)
		logd("getsockopt error\r\n");
}
/* include Listen */
void Listen(int fd, int backlog)
{
	char	*ptr;

		/*4can override 2nd argument with environment variable */
	if ( (ptr = getenv("LISTENQ")) != NULL)
		backlog = atoi(ptr);

	if (listen(fd, backlog) < 0)
		logd("listen error\r\n");
}
/* end Listen */
int Poll(struct pollfd *fdarray, unsigned long nfds, int timeout)
{
	int		n;

	if ( (n = poll(fdarray, nfds, timeout)) < 0)
		logd("poll error\r\n");

	return(n);
}
ssize_t Recv(int fd, void *ptr, size_t nbytes, int flags)
{
	ssize_t		n;

	if ( (n = recv(fd, ptr, nbytes, flags)) < 0)
		logd("recv error\r\n");
	return(n);
}
ssize_t Recvfrom(int fd, void *ptr, size_t nbytes, int flags,
		 struct sockaddr *sa, socklen_t *salenptr)
{
	ssize_t		n;

	if ( (n = recvfrom(fd, ptr, nbytes, flags, sa, salenptr)) < 0)
		logd("recvfrom error\r\n");
	return(n);
}
ssize_t Recvmsg(int fd, struct msghdr *msg, int flags)
{
	ssize_t		n;

	if ( (n = recvmsg(fd, msg, flags)) < 0)
		logd("recvmsg error\r\n");
	return(n);
}
int Select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds,
       struct timeval *timeout)
{
	int		n;

	if ( (n = select(nfds, readfds, writefds, exceptfds, timeout)) < 0)
		logd("select error\r\n");
	return(n);		/* can return 0 on timeout */
}

void Send(int fd, const void *ptr, size_t nbytes, int flags)
{
	if (send(fd, ptr, nbytes, flags) != (ssize_t)nbytes)
		logd("send error\r\n");
}

void Sendto(int fd, const void *ptr, size_t nbytes, int flags,
	   const struct sockaddr *sa, socklen_t salen)
{
	if (sendto(fd, ptr, nbytes, flags, sa, salen) != (ssize_t)nbytes)
		logd("sendto error\r\n");
}
void Sendmsg(int fd, const struct msghdr *msg, int flags)
{
	unsigned int	i;
	ssize_t			nbytes;

	nbytes = 0;	/* must first figure out what return value should be */
	for (i = 0; i < msg->msg_iovlen; i++)
		nbytes += msg->msg_iov[i].iov_len;

	if (sendmsg(fd, msg, flags) != nbytes)
		logd("sendmsg error\r\n");
}
void Setsockopt(int fd, int level, int optname, const void *optval, socklen_t optlen)
{
	if (setsockopt(fd, level, optname, optval, optlen) < 0)
		logd("setsockopt error\r\n");
}
void Shutdown(int fd, int how)
{
	if (shutdown(fd, how) < 0)
		logd("shutdown error\r\n");
}
int Sockatmark(int fd)
{
	int		n;

	if ( (n = sockatmark(fd)) < 0)
		logd("sockatmark error\r\n");
	return(n);
}
/* include Socket */
int Socket(int family, int type, int protocol)
{
	int		n;

	if ( (n = socket(family, type, protocol)) < 0)
		logd("socket error\r\n");
	return(n);
}
/* end Socket */
void Socketpair(int family, int type, int protocol, int *fd)
{
	int		n;

	if ( (n = socketpair(family, type, protocol, fd)) < 0)
		logd("socketpair error\r\n");
}

/*
 * unix wrapper functions.
 */
void * Calloc(size_t n, size_t size)
{
	void	*ptr;

	if ( (ptr = calloc(n, size)) == NULL)
		logd("calloc error\r\n");
	return(ptr);
}

void Close(int fd)
{
	if (close(fd) == -1)
		logd("close error\r\n");
}

void Dup2(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
		logd("dup2 error\r\n");
}

int Fcntl(int fd, int cmd, int arg)
{
	int	n;

	if ( (n = fcntl(fd, cmd, arg)) == -1)
		logd("fcntl error\r\n");
	return(n);
}

void Gettimeofday(struct timeval *tv, void *foo)
{
	if (gettimeofday(tv, foo) == -1)
		logd("gettimeofday error\r\n");
	return;
}

int Ioctl(int fd, int request, void *arg)
{
	int		n;

	if ( (n = ioctl(fd, request, arg)) == -1)
		logd("ioctl error\r\n");
	return(n);	/* streamio of I_LIST returns value */
}

pid_t Fork(void)
{
	pid_t	pid;

	if ( (pid = fork()) == -1)
		logd("fork error\r\n");
	return(pid);
}

void * Malloc(size_t size)
{
	void	*ptr;

	if ( (ptr = malloc(size)) == NULL)
		logd("malloc error\r\n");
	return(ptr);
}

void * Mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset)
{
	void	*ptr;

	if ( (ptr = mmap(addr, len, prot, flags, fd, offset)) == ((void *) -1))
		logd("mmap error\r\n");
	return(ptr);
}

int Open(const char *pathname, int oflag, mode_t mode)
{
	int		fd;

	if ( (fd = open(pathname, oflag, mode)) == -1)
		logd("open error for %s\r\n", pathname);
	return(fd);
}

void Pipe(int *fds)
{
	if (pipe(fds) < 0)
		logd("pipe error\r\n");
}

ssize_t Read(int fd, void *ptr, size_t nbytes)
{
	ssize_t		n;

	if ( (n = read(fd, ptr, nbytes)) == -1)
		logd("read error\r\n");
	return(n);
}

void Sigaddset(sigset_t *set, int signo)
{
	if (sigaddset(set, signo) == -1)
		logd("sigaddset error\r\n");
}

void Sigdelset(sigset_t *set, int signo)
{
	if (sigdelset(set, signo) == -1)
		logd("sigdelset error\r\n");
}

void Sigemptyset(sigset_t *set)
{
	if (sigemptyset(set) == -1)
		logd("sigemptyset error\r\n");
}

void Sigfillset(sigset_t *set)
{
	if (sigfillset(set) == -1)
		logd("sigfillset error\r\n");
}

int Sigismember(const sigset_t *set, int signo)
{
	int		n;

	if ( (n = sigismember(set, signo)) == -1)
		logd("sigismember error\r\n");
	return(n);
}

void Sigpending(sigset_t *set)
{
	if (sigpending(set) == -1)
		logd("sigpending error\r\n");
}

void Sigprocmask(int how, const sigset_t *set, sigset_t *oset)
{
	if (sigprocmask(how, set, oset) == -1)
		logd("sigprocmask error\r\n");
}

char * Strdup(const char *str)
{
	char	*ptr;

	if ( (ptr = strdup(str)) == NULL)
		logd("strdup error\r\n");
	return(ptr);
}

long Sysconf(int name)
{
	long	val;

	errno = 0;		/* in case sysconf() does not change this */
	if ( (val = sysconf(name)) == -1)
		logd("sysconf error\r\n");
	return(val);
}

void Unlink(const char *pathname)
{
	if (unlink(pathname) == -1)
		logd("unlink error for %s\r\n", pathname);
}

pid_t Wait(int *iptr)
{
	pid_t	pid;

	if ( (pid = wait(iptr)) == -1)
		logd("wait error\r\n");
	return(pid);
}

pid_t Waitpid(pid_t pid, int *iptr, int options)
{
	pid_t	retpid;

	if ( (retpid = waitpid(pid, iptr, options)) == -1)
		logd("waitpid error\r\n");
	return(retpid);
}

void Write(int fd, void *ptr, size_t nbytes)
{
	if (write(fd, ptr, nbytes) != nbytes)
		logd("write error\r\n");
}
