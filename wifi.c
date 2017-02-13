#include"wifi.h"
#include<string.h>
pthread_mutex_t m1;
void *parse_wifi(void *ptr)
{
	FILE *fp1,*fp2;
	int line_num = 1;
	int find_result = 0;
	char temp[100];
	fp1 = fopen("data.txt","r");
	fp2 = fopen(ptr,"a+");
//	pthread_mutex_lock(&m1);
	while(fgets(temp, 100, fp1) != NULL) {
		if((strstr(temp, "wifi = ")) != NULL) {
			fwrite(temp,1,strlen(temp)+1,fp2);
			//printf("A match found on line: %d\n", line_num);
			//printf("\n%s\n", temp);
			//find_result++;
			//line_num++;
		}
		line_num++;
	}
//	pthread_mutex_unlock(&m1);
/*	fclose(fp1);
	fclose(fp2);*/
}
/*
int main(void)
{
	parse_wifi();
}*/
