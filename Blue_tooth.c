#include"Blue_tooth.h"
#include<string.h>
#include<sys/sem.h>
pthread_mutex_t m1;
void semaphore_unlock(void);
void semaphore_lock(void);
extern int sem_id;
void *parse_bt(void *ptr)
{
	FILE *fp1,*fp2;
	int line_num = 1;
	int find_result = 0;
	char temp[100];
	fp1 = fopen("data.txt","r");
	//fp2 = fopen((char *)ptr,"a+");
	//fp2 = fopen("bt_data.txt","a+");
		//	printf("\n%s\n", (char *)ptr);
	semctl(sem_id, 0, SETVAL, 1);
	semaphore_lock();
	fp2 = fopen("common_data.txt","a+");
	pthread_mutex_lock(&m1);
	while(fgets(temp, 100, fp1) != NULL) {
		if(strstr(temp, "BT  = ")) 
			fwrite(temp,1,strlen(temp),fp2);
	}
	pthread_mutex_unlock(&m1);
	semaphore_unlock();

/*fclose(fp1);	*/
fclose(fp2);	
}
