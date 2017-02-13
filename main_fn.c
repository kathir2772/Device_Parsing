#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>
#include<signal.h>
#include<sys/types.h>
#include"Blue_tooth.h"
#include"GPS_Header.h"
#include"wifi.h"
#include<sys/sem.h>

pthread_t tid[3];
extern pthread_mutex_t m1;
void fork_call(void);
void  semaphore_lock(void);
void semaphore_unlock(void);
int sem_id;

int cnt = 0;

void usr_defned(int sig_num)
{	
	fork_call();

}

void fork_call(void)
{
	cnt++;
	printf("\n fork_cnt ___%d\n",cnt);
	int itr,itr1;
	int v;

	void *(*fp[3])(void *) = { parse_bt , parse_wifi, parse_gps };
	char *buf=malloc(50);
	
	pid_t pid;
	pid = fork();
	
	if(pid == 0)
	{	
		for(itr = 0;itr < 3 ;itr++)
	       		pthread_create( &tid[itr] , NULL , fp[itr] ,(void *)buf);
	
		for(itr1 = 0; itr1 < 3; itr1++)
	      		pthread_join(tid[itr1],NULL);        
	}
	else
		wait(&v);
}


int main(void)
{
	sem_id = semget((key_t)134, 2, 0666 | IPC_CREAT); 	
	struct sigaction sa;

	sa.sa_handler = usr_defned;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags=0;	

	sigaction(SIGINT,&sa,0);
	pthread_mutex_init(&m1,NULL);
	while(1);


}

void  semaphore_lock(void)
{
	struct sembuf v;

	v.sem_num = 0;
	v.sem_op = -1;
	v.sem_flg = SEM_UNDO;

	if (semop(sem_id, &v, 1) == -1) {
		perror("Thread1:semop failure Reason:");
		exit(-1);
	}

}

void semaphore_unlock(void)
{
	struct sembuf v;
	v.sem_num = 0;
	v.sem_op = 1;
	v.sem_flg = SEM_UNDO;

	if (semop(sem_id, &v, 1) == -1) {
		perror("Thread1:semop failure Reason:");
		exit(-1);
	}
}

