# SystemsSoftware
Steps to complete this assigment:

1. Create directorys using sudo mkdir -p "directory", to create the following dirs: 
- /home/michael/Desktop/SystemsSoftware/var/www/html/live/ 
- /home/michael/Desktop/SystemsSoftware/var/www/html/intranet/ 
- /home/michael/Desktop/SystemsSoftware/var/websitebackup/

2. Inside the live and intranet folder run the below command to create an empty html file to test our application: 
- sudo touch website.html


3. Create Users Dev1 and testuser with no read write permissions, these permissions will be assigned later and the accounts, will be used to test the application and assign them to a user group which will be used later on for permissions.

- sudo useradd -m Dev
- sudo useradd -m testuser

4. Create a group for the Dev user and a group for the testuser, then assign permissions to the /home/michael/Desktop/SystemsSoftware/var/www/ folder and /home/michael/Desktop/SystemsSoftware/var/websitebackup folder this will apply the permissions to all subsequent within these directories.

- sudo groupadd Developers
- sudo usermod -a -G Developers Dev
- sudo groupadd testers
- sudo usermod -a -G testers testuser

Important when setting the user permissions use su - not sudo or you risk spending an hour wondering why your group doesn't have permission when it says clearly that it does.

-sudo chown changes who owns the group and who has access.
- sudo chown -R root:Developers /home/michael/Desktop/SystemsSoftware/var/

chmod assigns permissions to the users and groups on the directory. u is the owner, g is the groups which have access and o is other users/groups. +rwx adds read, write and execute permissions. -rwx takes all of those permissions away.
- sudo chmod -R ug+rwx /home/michael/Desktop/SystemsSoftware/var/
- sudo chmod -R o-rwx /home/michael/Desktop/SystemsSoftware/var/

5. Creating an auditing system for the website files, the logs can be found in the /var/log/audit/ folder and can be accessed in the audit.log file. The purpose of auditing is to monitor critical system files to ensure accountability for and errors or mistakes made, and allow a faster responce to solving them.

- sudo apt-get install auditd
- sudo auditctl-w /home/michael/Desktop/SystemsSoftware/var/www/html -p rwxa

6. Creating the c files and the make file. I started off with a basic hello world program to test that my makefile is working, I use a single file daemon.c to create an executable call my daemon, the code for these files can be found on my github linked at the top or my submission.

- touch daemon.c
- touch makefile
- make //runs the makefile

7. Preparing the daemon

# References

1. Linux website showing how to give permissions recursively to directorys. 
- https://www.linux.com/learn/how-manage-file-and-folder-permissions-linux



