#include"wifi.h"
#include<string.h>
#include<sys/sem.h>
pthread_mutex_t m1;
void semaphore_unlock(void);
void semaphore_lock(void);
extern sem_id;
void *parse_wifi(void *ptr)
{
	FILE *fp1,*fp2;
	int line_num = 1;
	int find_result = 0;
	char temp[100];
	fp1 = fopen("data.txt","r");
	//fp2 = fopen(ptr,"a+");
	//fp2 = fopen("wifi_data.txt","a+");
	semaphore_lock();

	fp2 = fopen("common_data.txt","a+");
	pthread_mutex_lock(&m1);
	while(fgets(temp, 100, fp1) != NULL) {
<<<<<<< HEAD
		if(strstr(temp, "wifi = ")) 
			fwrite(temp,1,strlen(temp),fp2);
		
=======
		if(strstr(temp, "wifi = "))
			fwrite(temp,1,strlen(temp),fp2);
>>>>>>> 508fcf92881526150ca4ec5662c60ae931b09097
	}
	pthread_mutex_unlock(&m1);
	semctl(sem_id, 0 , SETVAL ,0);
	semaphore_unlock();

/*	fclose(fp1);*/
	fclose(fp2);
}
