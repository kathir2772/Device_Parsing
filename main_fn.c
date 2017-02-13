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

pthread_t tid[3];
extern pthread_mutex_t m1,m2,m3;
void fork_call();

int cnt = 0;

void usr_defned(int sig_num)
{	
	fork_call();

}

void fork_call()
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
	struct sigaction sa;

	sa.sa_handler = usr_defned;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags=0;	

	sigaction(SIGINT,&sa,0);
	pthread_mutex_init(&m1,NULL);
	while(1);

	//int itr1=0,itr2,pid,pro;
	//for(itr1=0;itr1<2;itr1++)
	//{
	//pid=fork();
	//if(pid==0)
	//	pro=0;
	//else
	//	pro=1;//wait

//	for(itr2 = 0;itr2< 3;itr2++)
	//sprintf(buf,"proc%d_%d.txt",itr1+1,pro);
	//child process
	//for(itr=0;itr<3;itr++)
	  //      pthread_create( &tid[itr] , NULL , fp[itr] ,(void *)buf);

//	}
//


}
    	
