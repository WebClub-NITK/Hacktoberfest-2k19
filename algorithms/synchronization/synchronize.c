#include<stdio.h>
#include<pthread.h>

pthread_mutex_t sum_mutex = PTHREAD_MUTEX_INITIALIZER;

long long sum=0;
void* func(void* ptr)
{
	for(int i=0;i<10000;++i)
    {
        pthread_mutex_lock(&sum_mutex);
		sum=sum+1;
        pthread_mutex_unlock(&sum_mutex);
    }
}
int main()
{
	pthread_t t1[10];

	for(int i=0;i<10;++i)
		pthread_create(&t1[i], NULL, func, NULL); 

	for(int i=0;i<10;++i)
		pthread_join(t1[i], NULL); 
    pthread_mutex_destroy(&sum_mutex);
	printf("%Ld",sum);
	return 0;
}









