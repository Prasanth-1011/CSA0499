#include<stdio.h>
#include<process.h>

void main()
{
	int a[20],p[20],i,j,n,m;
	printf("Enter Number of Blocks.\n");
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		printf("Enter the %dst Block Size:",i);
		scanf("%d",&a[i]);
	}
	printf("Enter Number of Process.\n");
	scanf("%d",&m);
	for(i=0; i<m; i++)
	{
		printf("Enter the Size of %dst Process:",i);
		scanf("%d",&p[i]);
	}
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			if(p[j]<=a[i])
			{
				printf("The Process %d Allocated to %d\n",j,a[i]);
				p[j]=10000;
				break;
			}
		}
	}
	for(j=0; j<m; j++)
	{
		if(p[j]!=10000)
		{
			printf("The Process %d is Not Allocated\n",j);
		}
	}
}
