#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t Semaphore;
pthread_t thread1;
void* print(void* n)
{
	sem_wait(&Semaphore);
	int i =0;
	for( i=0;i<5;i++)
	{
	printf("%d ",i);
	}
	pthread_exit(NULL);
}
int main()
{
	
	sem_init(&Semaphore,0,1);
	
	pthread_create(&thread1,NULL,print,NULL);
	pthread_join(thread1,NULL);
	return 0;
}
