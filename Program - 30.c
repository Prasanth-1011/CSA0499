#include <stdio.h>
#include <string.h>
#include <pthread.h>
int i = 2;
void* foo(void* p)
{
	printf("Value Recevied as Argument in Starting Routine : ");
	printf("%i\n", * (int*)p);
	pthread_exit(&i);
}
int main(void)
{
	pthread_t id;
	int j = 1;
	pthread_create(&id, NULL, foo, &j);
	int* ptr;
	pthread_join(id, (void**)&ptr);
	printf("Value Recevied by Parent From Child : ");
	printf("%i\n", *ptr);
}
