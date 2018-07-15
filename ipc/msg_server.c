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
	struct msqid_ds buf;

	msqid = msgget(MSG_KEY, IPC_CREAT | 0666);
	if (msqid == -1) {
		perror("msgget");
		exit(EXIT_FAILURE);
	}

	printf("Server Pid = %d \n",getpid());
	
	while(1){
		msgrcv(msqid,&msg,sizeof(msg.mtext),888,0);
		printf("Server Recieve mtype = %d,mtext = %s\n",msg.mtype,msg.mtext);
		
		if(msg.mtext == 'q\n'){
			break;
		}

		msg.mtype = 999;
		sprintf(msg.mtext," Hello,I'm Server Porc pid = %d\n",getpid());
		msgsnd(msqid,&msg,sizeof(msg.mtext),0);
	}

	//delete massage queue
	msgctl(msqid,IPC_RMID,&buf);

    exit(EXIT_SUCCESS);
}



