myDaemon : daemon.o 
	gcc -o myDaemon daemon.o -lm

daemon.o : daemon.c 
	gcc -c daemon.c

clean: 
	rm  myDaemon daemon.o
