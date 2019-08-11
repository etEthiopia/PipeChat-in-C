#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FIFO_FILE "/tmp/fifo_twoway"
int main() {

   	int fd1,retval;
	char str1[100], str2[100]; 
	
	while(1){  

		//open the temp file in readonly mode
	   	fd1 = open(FIFO_FILE, O_RDONLY);

		//read the message that has been recieved 
	   	read(fd1, str1, sizeof(str1)); 
	  
		// Print the message and close
		printf("Process1 %s\n", str1); 
		close(fd1); 
	  
		// Now open in write mode and write 
		fd1 = open(FIFO_FILE,O_WRONLY); 
		// string taken from user. 
		fgets(str2, 100, stdin); 
		//write on the temp file
		write(fd1, str2, strlen(str2)+1); 
		//close
		close(fd1);
	} 
	return 0;
}
