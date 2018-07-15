#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>


#define TEST_SEMAPHORE 	1  			/*test semaphore*/
#define	SEM_KEY			0x00668877  /*key_t semaphore*/

/*use for semctl init the semaphore*/
union semun {
	int              val;    /* Value for SETVAL */
	struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
	unsigned short  *array;  /* Array for GETALL, SETALL */
	struct seminfo  *__buf;  /* Buffer for IPC_INFO(Linux-specific) */
};

/**
 * Create Semaphore
 * int semget(key_t key, int nsems, int semflg);
 * semflg = IPC_CREAT | 0666 | ... 
 * */
int create_sem(key_t key,int nsems,int semflg)
{
	 int sem_id; 
	 sem_id = semget(key,nsems,semflg);
	 if(sem_id == -1){
		perror("Create Semaphore Failed");
		return -1;
	 }
	 return sem_id;
}

/**
 * Init Semaphore
 * int semctl(int semid, int semnum, int cmd, ...);
 * cmd = SETVAL
 * */
int init_sem(int sem_id,int value)
{
	union semun tmp;
	tmp.val = value;
	if(semctl(sem_id,0,SETVAL,tmp) < 0){
		perror("init semaphore error");
		return -1;
	}
	return 0;
}


/**
 * delete semaphore
 * int semctl(int semid, int semnum, int cmd, ...);
 * cmd = IPC_RMID
 * */
int del_sem(int sem_id)
{
	union semun tmp;
	if(semctl(sem_id,0,IPC_RMID,tmp) == -1){
		perror("delete semaphore error");
		return -1;
	}
	return 0;
}

/**
 * semaphore P handle
 * int semop(int semid, struct sembuf *sops, size_t nsops);
 * */
int sem_p(int sem_id)
{
	struct sembuf sops;
	sops.sem_num= 0;
	sops.sem_op = -1;
	sops.sem_flg  = SEM_UNDO;
	
	if(semop(sem_id,&sops,1) == -1){
		perror("semop p handle error");
		return -1;
	}
	return 0;
}


/**
 * semaphore V handle
 * int semop(int semid, struct sembuf *sops, size_t nsops);
 * */
int sem_v(int sem_id)
{
	struct sembuf sops;
	sops.sem_num= 0;
	sops.sem_op = 1;
	sops.sem_flg  = SEM_UNDO;
	
	if(semop(sem_id,&sops,1) == -1){
		perror("semop v handle error");
		return -1;
	}
	return 0;
}

#if TEST_SEMAPHORE
int main(void)
{
	int sem_id;
	pid_t	pid;
	
	sem_id = create_sem(SEM_KEY,1,IPC_CREAT| IPC_EXCL | 0666);
	if(sem_id == -1){
		printf("crate sem failed\n");
		return -1;
	}
	init_sem(sem_id,0); //init value equles 0 ,resource busy
	
	pid = fork();
	if(pid == -1){
		printf("fork error\n");
		return -1;
	}
	
	if(pid == 0){ /*child proc*/
		sleep(5);
		printf("Child proc pid = %d, father proc pid = %d \n",
				getpid(),getppid());
		sem_v(sem_id);  /*relase res*/
		
	}else {			/*parent proc*/
		sem_p(sem_id);  //waitting res
		printf("Parent proc pid = %d \n",getpid());
		sem_v(sem_id);
		del_sem(sem_id);
	}

	return 0;
}
#endif
