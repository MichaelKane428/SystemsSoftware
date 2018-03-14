# SystemsSoftware
Steps to complete this assigment:

1. Create directorys using sudo mkdir -p "directory", to create the following dirs: 
- /var/www/html/live/ 
- /var/www/html/intranet/ 
- /var/websitebackup/

2. Inside the live and intranet folder run the below command to create an empty html file to test our application: 
- sudo touch website.html


3. Create Users Dev1 and testuser with no read write permissions, these permissions will be assigned later and the accounts, will be used to test the application and assign them to a user group which will be used later on for permissions.

- sudo useradd -m Dev
- sudo useradd -m testuser

4. Create a group for the Dev user and a group for the testuser, then assign permissions to the /var/www/ folder and /var/websitebackup folder this will apply the permissions to all subsequent within these directories.

- sudo groupadd Developers
- sudo usermod -a -G Developers Dev
- sudo groupadd testers
- sudo usermod -a -G testers testuser

# References

1. Linux website showing how to give permissions recursively to directorys. 
- https://www.linux.com/learn/how-manage-file-and-folder-permissions-linux



