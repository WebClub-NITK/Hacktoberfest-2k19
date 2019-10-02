#include<stdio.h>
#include<pthread.h>
long long sum=0;
void* func(void* ptr)
{
	for(int i=0;i<10000;++i)
		sum=sum+1;
	
}
int main()
{
	pthread_t t1[10];

	for(int i=0;i<10;++i)
		pthread_create(&t1[i], NULL, func, NULL); 

	for(int i=0;i<10;++i)
		pthread_join(t1[i], NULL); 

	printf("%Ld",sum);
	return 0;
}









