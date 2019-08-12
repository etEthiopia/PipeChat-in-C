#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FIFO_FILE "/tmp/fifo_twoway"
int main() {
   	int fd,retval;
	char arr1[100], arr2[100];

   	
   	/*Create the FIFO if it does not exist on temporary filesystem with 		permission 0666 (read and write permission)*/
	retval= mkfifo(FIFO_FILE, S_IFIFO|0666);

	while(1){
	   	
		/*we open the file with write only mode because this is the 			process that writes first*/
	   	fd = open(FIFO_FILE, O_WRONLY);
		
		fgets(arr2, 100, stdin); //get data from the user
	   	write(fd, arr2, strlen(arr2)+1); //write on the file descriptor
		close(fd); 
	  
		// Open FIFO for Read only 
		fd = open(FIFO_FILE, O_RDONLY); 
	  
		// Read from the message recived
		read(fd, arr1, sizeof(arr1)); 
	  
		// Print the recived message
		printf("Process2 %s\n", arr1);

		close(fd); 
	}
   
   	return 0;
}


