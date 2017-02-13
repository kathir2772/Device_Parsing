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
extern pthread_mutex_t m[3];

int main(void)
{
	
char *buf=malloc(50);
	void *(*fp[3])(void *)={parse_bt,parse_wifi,parse_gps};
	int itr= 0,itr1 =0,itr2= 0,pid,pro;
	//for(itr1=0;itr1<2;itr1++)
	//{
	pid=fork();

		if(pid==0)
			pro=0;
		else
			pro=1;//wait

		pthread_mutex_init(&m[itr2],NULL);
		sprintf(buf,"proc%d_%d.txt",itr1+1,pro);
	//child process
	//for(itr=0;itr<3;itr++)
	        pthread_create( &tid[itr] , NULL , fp[itr] ,(void *)buf);
	//for(itr=0;itr<3;itr++)
	        pthread_join(tid[itr],NULL);        
	//for(itr2 = 0;itr2< 3;itr2++)
	//	pthread_mutex_init(&m[itr2],NULL);

	



}
    	
