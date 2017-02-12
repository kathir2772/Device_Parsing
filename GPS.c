#include"GPS_Header.h"
#include<string.h>
void parse_gps()
{
	FILE *fp1,*fp2;
	int line_num = 1;
	int find_result = 0;
	char temp[100];
	fp1 = fopen("data.txt","r");
	fp2 = fopen("gps_data.txt","w");
	while(fgets(temp, 100, fp1) != NULL) {
		if((strstr(temp, "GPS = ")) != NULL) {
			fwrite(temp,1,strlen(temp)+1,fp2);
			//printf("A match found on line: %d\n", line_num);
			//printf("\n%s\n", temp);
			//find_result++;
			//line_num++;
		}
		line_num++;
	}
	
}
/*
int main(void)
{
	parse_gps();
}*/
