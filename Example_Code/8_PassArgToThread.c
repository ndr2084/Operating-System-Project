#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h>
#include<pthread.h> 

int primes[10] = {2,3,5,7,11,13,17,19,23,29}; 

pthread_mutex_t mutex; 

void* function(void* arg){ 
	sleep(1);
	int prime = *(int*)arg; 
	printf("%d ", prime); 
} 

int main(int argc, char* argv[]){ 
	pthread_t th[10];
	pthread_mutex_init(&mutex, NULL);
	int i;
	for(i=0; i<10; i++){  
		if(pthread_create(&th[i], NULL, &function, primes+i) !=0){
			return 1;
		}
	}  
	
	for(int i=0; i<10; i++){ 
		if(pthread_join(th[i], NULL)!=0){
			return 2;
		}
	}
		  
	pthread_mutex_destroy(&mutex); 
	return 0; 
}
 
