#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	pid_t p;
	printf("Before Fork\n");
	p=fork();
	if(p==0)
	{
		printf("Child Having Id : %d\n",getpid());
		printf("My Parent's Id : %d\n",getppid());
	}
	else
	{
		printf("My Child's Id : %d\n",p);
		printf("Parent Having Id : %d\n",getpid());
	}
	printf("Common\n");
}