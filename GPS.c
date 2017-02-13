#include"GPS_Header.h"
#include<string.h>
pthread_mutex_t m1;
void *parse_gps(void *ptr)
{
	FILE *fp1,*fp2;
	int line_num = 1;
	int find_result = 0;
	char temp[150];
	fp1 = fopen("data.txt","r");
	//fp2 = fopen(ptr,"a+");
	fp2 = fopen("gps_data.txt","a+");
	pthread_mutex_lock(&m1);
	while(fgets(temp, 150, fp1) != NULL) {
		if((strstr(temp, "GPS")) != NULL) 
			{//printf("_%s_%d\n",temp,strlen(temp));
			fwrite(temp,1,strlen(temp)+1,fp2);
			//printf("A match found on line: %d\n", line_num);
			//printf("\n%s\n", temp);
			//find_result++;
			//line_num++;
		}
		line_num++;
	}
	pthread_mutex_unlock(&m1);
/*fclose(fp1);	*/
fclose(fp2);	
}
/*
int main(void)
{
	parse_gps();
}*/
