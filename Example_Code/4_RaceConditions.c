#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 

//the output should be 20,000, but it won't (always) be due to race conditions
int mails = 0; 

void* routine(){ 
	for(int i = 0; i < 10000; i++)
	mails++;
	//reads mails 
	//increments mails  
	//writes mails
} 

int main(int argc, char* argv[]){ 
	pthread_t p1, p2; 
	
	if(pthread_create(&p1, NULL, &routine, NULL) != 0){ 
		return 1;
	} 
	
	if(pthread_create(&p2, NULL, &routine, NULL) != 0){ 
		return 2;
	}
	
	if(pthread_join(p1, NULL) != 0){ 
		return 3; 
	} 
	
	if(pthread_join(p2, NULL) != 0){ 
		return 4; 
	}
	
	printf("mails: %d\n", mails); 
	return 0;  
}
	
