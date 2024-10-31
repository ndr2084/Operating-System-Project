#include <stdlib.h> 
#include <stdio.h> 
#include <unistd.h> 
#include <pthread.h> 

int x = 0; 
void* routine(){ 
	x++; 
	//pid will be the same for both threads because they share a common space in memory
	sleep(2); 
	printf("PID: %d\n value of x: %d\n", getpid(), x); 
} 

void* routine2(){ 
	sleep(2); 
	printf("PID: %d\n value of x: %d\n", getpid(), x); 
}

int main(int argc, char* argv[]){ 
	int x = 0; 
	pthread_t t1, t2; 
	
	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return 1; 
	if (pthread_join(t1, NULL) != 0)
		return 2; 
	if (pthread_create(&t2, NULL, &routine2, NULL) != 0)
		return 3; 
	if (pthread_join(t2, NULL) != 0)
		return 4; 
		
	return 0; 
}
