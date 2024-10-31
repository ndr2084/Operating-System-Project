#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h> 

pthread_mutex_t mutex; 
int mails = 0; 
void *function(){ 
	
	for(int i = 0; i < 100000; i++){ 
		pthread_mutex_lock(&mutex); 
		mails++;
		pthread_mutex_unlock(&mutex); 
	}
} 

int main(int argc, char* argv[]){ 
	pthread_t th[4]; //creates an array of 4 threads
	pthread_mutex_init(&mutex, NULL); 	
	
	for(int i = 0; i < 4; i++){ 
		if(pthread_create(&th[i], NULL, &function, NULL) != 0){ 
			printf("Failed to create thread\n"); 
			return 1; 
		} 
		printf("Thread %d has started\n", i); 
	} 
	
	for(int i = 0; i < 4; i++){ 
		if(pthread_join(th[i], NULL) != 0){ 
			printf("Failed to delete thread\n"); 
			return 2;
		}
		printf("Thread %d has finished execution\n", i); 
	}
	
	 pthread_mutex_destroy(&mutex); 
	 printf("Mail: %d\n", mails); 
	 return 0; 
}
 
