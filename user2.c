#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h>
  
int main() 
{ 
    int fd,fd1,fd2,fd3,fd4; 
   
  
    // FIFO file path 
    char * myfifo = "/tmp/myfifo"; 
    char * myfifochoice = "/tmp/myfifochoice";
    char * myfifooperand1 = "/tmp/myfifooperand1";
    char * myfifooperand2 = "/tmp/myfifooperand2"; 
    char * myfiforesult = "/tmp/myfiforesult";
  
    // Creating the named file(FIFO) 
    mkfifo(myfifo, 0666); 
    mkfifo(myfifochoice, 0666);
    mkfifo(myfifooperand1, 0666);
    mkfifo(myfifooperand2, 0666);
    mkfifo(myfiforesult,0666);
    int choice=0;
    int val1,val2;
   
   
    
   
    while (1) 
    { 
    	
    	char mymenu[200]="\nWelcome Client! Specify your operation.\n1.Addition+\n2.Subtraction-\n3.Multiplication*\n4.Division/\n";      
  
        fd = open(myfifo,O_WRONLY); 

        write(fd,mymenu,strlen(mymenu)+1);
        
        close(fd); 
        
        
        fd1 = open(myfifochoice,O_RDONLY); 
        read(fd1, &choice, 10);
        printf("The value of choice: %d",choice);  
        close(fd1);
        
         
        fd2 = open(myfifooperand1,O_RDONLY); 
        read(fd2, &val1, 10);
        printf("The value of choice: %d",val1);  
        close(fd2);
        
       
        fd3 = open(myfifooperand2,O_RDONLY); 
        read(fd3, &val2, 10);
        printf("The value of choice: %d",val2); 
        close(fd3);
        
        int result=0;
        
        switch(choice)
        {
            case 1:
            result=val1+val2;
            break;

            case 2:
            result=val1-val2;
            break;

            case 3:
            result=val1*val2;
            break;

            case 4:
            result=val1/val2;
            break;

        }
        fd4 = open(myfiforesult,O_WRONLY);
        write(fd4, &result, 10);
        close(fd4);
             
        
    }
    
    return 0; 
} 
