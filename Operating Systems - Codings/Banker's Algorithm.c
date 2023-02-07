#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[10][10],m[10][10],ne[10][10],avail[10],i,j,n,k = 0,r,cop[10],op[10],copm = 0;
	printf("Enter the No.of Processes : ");
	scanf("%d",&n);
	printf("Enter the No.of Requests : ");
	scanf("%d",&r);
	for(i= 0 ;i<n;i++)
	{
		cop[i] = 0;
	}
	printf("Enter the Allocation Matrix :\n");
	for(i = 0; i < n;i++)
	{
		for(j = 0;j < r;j++)
		{
			printf("[%d][%d] = ",i,j);
			scanf("%d",&a[i][j]);
		}
	printf("\n");
	}
	printf("Enter the Max Matrix :\n");
	for(i = 0; i < n;i++)
	{
		for(j = 0;j < r;j++)
		{
			printf("[%d][%d] = ",i,j);
			scanf("%d",&m[i][j]);
		}
	printf("\n");
	}
	printf("The Allocation Matrix is :\n");
	for(i = 0; i < n;i++){
		for(j = 0;j < r;j++){
			printf("%d  ",a[i][j]);
		}
		printf("\n");
	printf("\n");
	}
	printf("\n");
	printf("The Max Matrix is :\n");
	for(i = 0; i < n;i++)
	{
		for(j = 0;j < r;j++)
		{
			printf("%d  ",m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i = 0; i < n;i++)
	{
		for(j = 0;j < r;j++)
		{
			ne[i][j] = m[i][j] - a[i][j];
		}
	printf("\n");
	}
	printf("The Need Matrix is :\n");
	for(i = 0; i < n;i++)
	{
		for(j = 0;j < r;j++)
		{
			printf("%d  ",ne[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("The Available is :\n");
	for(i=0;i<n;i++)
	{
		printf("[%d] = ",i);
		scanf("%d",&avail[i]);
	}
	while(copm < n)
	{
		for(i = 0;i < n;i++)
		{
			if(cop[i] != 1 && ne[i][0] <= avail[0] && ne[i][1] <= avail[1] && ne[i][2] <= avail[2])
			{
				avail[0] += a[i][0];
				avail[1] += a[i][1];
				avail[2] += a[i][2];
				copm++;
				cop[i] = 1;
				op[k++] = i;
			}
		}
	printf("\n");
	}
	printf("The Availale Resource is :\n");
	for(i= 0 ;i<n;i++)
	{
		printf("%d ",avail[i]);
	}
	printf("\n");
	printf("\nThe Order of Process is :\n");
	for(i= 0 ;i<n;i++)
	{
		printf("%d ",op[i]);
	}
}