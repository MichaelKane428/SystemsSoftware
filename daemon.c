#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	void update(void);
	update();
	
	/*int pid = fork();
	if(pid > 0){
		printf("parent\n");
	}
	else if(pid == 0){
		printf("Child\n");
	}*/
	
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
