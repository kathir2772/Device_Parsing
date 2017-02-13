INC = -I./include/
#DEV:main_fn.c Blue_tooth.o GPS.o wifi.o
DEV:main_fn.c Blue_tooth.o GPS.o wifi.o
#	gcc $(INC) test_main.c Blue_tooth.o GPS.o wifi.o -o DEV -lpthread 
	gcc $(INC) main_fn.c Blue_tooth.o GPS.o wifi.o -o DEV -lpthread 
Blue_tooth.o:Blue_tooth.c
	gcc -c $(INC) Blue_tooth.c
GPS.o:GPS.c
	gcc -c  $(INC) GPS.c
wifi.o:wifi.c
	gcc  -c $(INC) wifi.c
clean: 
	rm *.o
