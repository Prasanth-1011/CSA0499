#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
void *fun1();
void *fun2();
int shared = 1;
pthread_mutex_t l;
int main()
{
	pthread_mutex_init(&l, NULL);
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, fun1, NULL);
	pthread_create(&thread2, NULL, fun2, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2,NULL);
	printf("Final Value of Shared is %d\n",shared);
}
void *fun1()
{
	int x;
	printf("Thread 1 Trying to Acquire Lock\n");
	pthread_mutex_lock(&l);
	printf("Thread 1 Acquired Lock\n");
	x=shared;
	
	printf("Thread 1 Reads the Value of Shared Variable as %d\n",x);
	x++;
	printf("Local Updation by Thread 1 : %d\n",x);
	sleep(1);
	shared = x;
	printf("Value of Shared Variable Updated by Thread 1 is %d\n",shared);
	pthread_mutex_unlock(&l);
	printf("Thread 1 Released the Lock\n\n");
}
void *fun2()
{
	int y;
	printf("Thread 2 Trying to Acquire Lock\n");
	pthread_mutex_lock(&l);
	printf("Thread 2 Acquired Lock\n");
	y = shared;
	printf("Thread 2 Reads the Value as %d\n",y);
	y--;
	printf("Local Updation by Thread 2 : %d\n",y);
	sleep(1);
	shared = y;
	printf("Value of Shared Variable Updated by Thread 2 is %d\n",shared);
	pthread_mutex_unlock(&l);
	printf("Thread 2 Released the Lock\n");
}