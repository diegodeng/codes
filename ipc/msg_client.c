#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>


#define MSG_KEY			0x00113322		/*key_t key for msagges queue */

struct msgbuf {
	long mtype;       /* message type, must be > 0 */
	char mtext[256];    /* message data */
};


int main(int argc, char *argv[])
{
	int msqid ;
	struct msgbuf msg;

	msqid = msgget(MSG_KEY, IPC_CREAT | 0666);
	if (msqid == -1) {
		perror("msgget");
		exit(EXIT_FAILURE);
	}

	printf("Client Pid = %d \n",getpid());
	//add a massege	
	msg.mtype = 888;   //888 is client msg type
	if(argc == 2){
		sprintf(msg.mtext,argv[1]);
	}else{
		sprintf(msg.mtext," Hello,I'm Client Porc pid = %d\n",getpid());
	}
	msgsnd(msqid,&msg,sizeof(msg.mtext),0);

	//rcv a massege
	msgrcv(msqid,&msg,sizeof(msg.mtext),999,0);
	printf("Client Proc mtype = %d, mtext = %s\n",msg.mtype,msg.mtext);
    exit(EXIT_SUCCESS);
}



