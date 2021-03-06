#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

int main(){

	int pid = fork();
	if(pid > 0){
		exit(EXIT_SUCCESS);
	}
	else if(pid == 0){
		
		//Elevate the orphan to session leader.
		if(setsid() < 0) {
			printf("sid");
			exit(EXIT_FAILURE);
		}
		
		umask(0);
	
		//Change working dir to root.
		if(chdir("/") < 0) {
			printf("dir");
			exit(EXIT_FAILURE);
		}
	
		while(1){
			//https://www.tutorialspoint.com/c_standard_library/time_h.htm
			//http://zetcode.com/articles/cdatetime/
			//Create a time object to wait for midnight.
			int hour = 0;
			int minutes = 00;
			time_t rawtime = time(NULL);
			struct tm *ptm =localtime(&rawtime);
			void update(void);
			if(hour == ptm->tm_hour && minutes == ptm->tm_min){
				
				update();
				sleep(60);
			}
		}			
		
	}
 	
 return 0;

}


/*
	Purpose of this function is to start a backup, then when it is complete check the difference between intranet and live, 
	if the results say there has been a change to intranet update live, while update is in progress remove permissions.
*/
void update(){
	int difference;	
	difference = system("diff -r /home/michael/Desktop/SystemsSoftware/var/www/html/intranet/ /home/michael/Desktop/SystemsSoftware/var/www/html/live/");


	// Remove read, write,execute commands for the developers group.
	system("chmod -R g-rwx /home/michael/Desktop/SystemsSoftware/var/");
	

	// Backup website.html from live with current permissions to the backupwebsite folder.
	system("cp -a /home/michael/Desktop/SystemsSoftware/var/www/html/live/website.html /home/michael/Desktop/SystemsSoftware/var/websitebackup/");	


	if(difference != 0){
		printf("Change Detected updating live");

		// Copy website.html from intranet to live with current permissions. e.g. Dont overwrite old permissions with new.
		system("cp -a /home/michael/Desktop/SystemsSoftware/var/www/html/intranet/website.html /home/michael/Desktop/SystemsSoftware/var/www/html/live/");
		
	}
	else if (difference == 0){
		printf("No change detected cancelling update");
	}

	// Add permissions back.
	system("chmod -R g+rwx /home/michael/Desktop/SystemsSoftware/var/");
}
