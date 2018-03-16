#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	void backup(void);
	backup();
	
	/*int pid = fork();
	if(pid > 0){
		printf("parent\n");
	}
	else if(pid == 0){
		printf("Child\n");
	}*/
	
 return 0;

}

void backup(){
	int difference;	
	difference = system("diff -r /home/michael/Desktop/SystemsSoftware/var/www/html/intranet/ /home/michael/Desktop/SystemsSoftware/var/www/html/live/");

	if(difference != 0){
		printf("filewaschanged");

	}
	else if (difference == 0){
		printf("no Changes");
	}
}
