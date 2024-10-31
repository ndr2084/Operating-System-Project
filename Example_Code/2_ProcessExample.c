#include <stdio.h> 
#include <stdlib.h>  
#include <unistd.h> 
#include <sys/wait.h> 
#include <sys/types.h> 

int main(int argc, char* argv[]){ 
	int x = 0; 
	int pid = fork(); 
	if (pid == -1)
		return 1; 
		
	if(pid == 0) /*IF (we are in the child process) then increment*/
		x++; 
	sleep(2); 
	//pid will be diff because proccesses don't share memory unless told to
	printf("PID: %d\n value of x: %d\n", getpid(), x); 
	
	if(pid != 0) 
		wait(NULL); 
	return 0; 
}
