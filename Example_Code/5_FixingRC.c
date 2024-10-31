#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 

//We can have an even larget mails integer and still have it be accurate! Thanks mutex
int mails = 0; 
pthread_mutex_t mutex; 

void* routine(){ 
	/*SPIN LOCK*/ 
	for(int i = 0; i < 10000000; i++){
	pthread_mutex_lock(&mutex); 
	mails++;
	pthread_mutex_unlock(&mutex);
	} 
} 

int main(int argc, char* argv[]){ 
	pthread_t p1, p2; 
	pthread_mutex_init(&mutex, NULL); //sets mutex to default value
	
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
	pthread_mutex_destroy(&mutex); //destroys mutex lock
	printf("mails: %d\n", mails); 
	return 0;  
}
	
