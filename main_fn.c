#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>
#include<signal.h>
#include<sys/types.h>

pthread_t tid[3];
//pthread_mutex_t m1,m2,m3;

int main(void)
{
	
char *buf=malloc(50);
	void (*fp[3])(void)={BT,WIFI,GPS};
	int itr,itr1,pid,pro;
	for(itr1=0;itr1<2;itr1++)
	{
	pid=fork();
	if(pid==0)
		pro=0;
	else
		pro=1;//wait

	sprintf(buf,"proc%d_%d.txt",itr1+1,pro);
	//child process
	for(itr=0;itr<3;itr++)
	        pthread_create( tid[itr] , NULL , fp[itr]() , (void *)buf);
	for(itr=0;itr<3;itr++)
        pthread_join(tid[itr],NULL);        
	}



}
/*	pthread_create( tid1 , NULL , BT , NULL);
	pthread_create( tid2 , NULL , WIFI , NULL);
	pthread_create (tid3 ,NULL ,GPS ,NULL )

	pthread_mutex_init(&m1,NULL);
	pthread_mutex_init(&m2,NULL);
	pthread_mutex_init(&m3,NULL);

	pthread_join(tid1,NULL);	
	pthread_join(tid2,NULL);	
	pthread_join(tid3,NULL);	*/
    	
