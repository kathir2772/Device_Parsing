#include<stdio.h>
#include<stdlib.h>
struct gps_data
{
	int Lat;
	int Long;
	char GMT[10];
	char speed[10];
};

void *parse_gps(void *ptr);
