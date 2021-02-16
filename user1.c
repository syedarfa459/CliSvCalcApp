#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
int main() 
{ 
    int fd,fd1,fd2,fd3,fd4; 
    int choice=0;
    int val1,val2;
    // FIFO file path 
    char * myfifo = "/tmp/myfifo";
    char * myfifochoice = "/tmp/myfifochoice";
    char * myfifooperand1 = "/tmp/myfifooperand1";
    char * myfifooperand2 = "/tmp/myfifooperand2"; 
    char * myfiforesult = "/tmp/myfiforesult";
  
   
   
    char MESSAGEFROM[100];
    while (1) 
    { 
        
        // Open FIFO for Read only 
        fd1 = open(myfifo, O_RDONLY); 
  
        read(fd1, MESSAGEFROM, sizeof(MESSAGEFROM));  
        printf("%s\n", MESSAGEFROM); 
        close(fd1); 
        
        
        fd2 = open(myfifochoice, O_WRONLY); 
        printf("\nEnter the operation number you want to perform : ");
        scanf("%d",&choice);
        write(fd2, &choice, 10); 
        close(fd2); 
        
        fd3 = open(myfifooperand1, O_WRONLY); 
        printf("\nEnter 1st value : ");
        scanf("%d",&val1);
        write(fd3, &val1, 10); 
        close(fd3);
        
        fd4 = open(myfifooperand2, O_WRONLY); 
        printf("\nEnter 2nd value : ");
        scanf("%d",&val2);
        write(fd4, &val2, 10); 
        close(fd4);
        
        //to read final result
        fd = open(myfiforesult, O_RDONLY); 
  	int result=0;
        // Read from FIFO 
        read(fd, &result, 10); 
        // Print the read message 
        printf("The result of your operation is: %d", result); 
        close(fd1);  
  
    } 
    return 0; 
} 
