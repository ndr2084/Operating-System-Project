#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 
#include <time.h> 

pthread_mutex_t mutex; 

void* function(){ 
	int value = (rand() % 6) + 1;
	int *result = malloc(sizeof(int )); 
	*result = value; 
	printf("dice value: %d\n", value); 
	return (void*) result;
} 

int main(int argc, char* argv[]){ 
	int* res; 
	srand(time(NULL)); 
	pthread_t th;
	pthread_mutex_init(&mutex, NULL); 
	if(pthread_create(&th, NULL, &function, NULL)!=0){
		printf("error creating thread\n"); 
		return 1;
	}
	
	/*Main thread(res) will wait for th thread
	**to finish and then retrieve its return value*/
	if(pthread_join(th, (void**) &res) != 0){ 
		printf("error deleting thread\n"); 
		return 2; 
	}
	pthread_mutex_destroy(&mutex);
	printf("Result: %d\n", *res); 
	free(res); 
	return 0; 
}  
	
		
		 
	
