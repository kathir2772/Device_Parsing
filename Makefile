INC = -I./include/
#DEV:main_fn.c Blue_tooth.o GPS.o wifi.o
DEV:main_fn.c Blue_tooth.o GPS.o wifi.o scan_bt.o
#	gcc $(INC) test_main.c Blue_tooth.o GPS.o wifi.o -o DEV -lpthread 
	gcc $(INC) main_fn.c Blue_tooth.o GPS.o wifi.o scan_bt.o -o DEV -lpthread -lbluetooth
Blue_tooth.o:Blue_tooth.c
	gcc -c $(INC) Blue_tooth.c 
GPS.o:GPS.c
	gcc -c  $(INC) GPS.c
wifi.o:wifi.c
	gcc  -c $(INC) wifi.c
scan_bt.o:scan_bt.c
	gcc  -c $(INC) scan_bt.c 
	
clean: 
	rm *.o
