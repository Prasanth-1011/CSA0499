#include<stdio.h>
struct process
{
    int wt,at,bt,tat,pt;
}
struct process a[10];
int main()
{
    int n,temp[10],t,count = 0,short_p;
    float total_WT = 0,total_TAT = 0,Avg_WT,Avg_TAT;
    printf("Enter the Number of the Process : ");
    scanf("%d",&n);
    printf("Enter the Arrival Time , Burst Time and Priority of the Process\n");
    printf("at bt pt\n");
    for(int i=0;i<n;i++)
	{
        scanf("%d%d%d",&a[i].at,&a[i].bt,&a[i].pt);
        temp[i]=a[i].bt;
    }
    a[9].pt = 10000;
    for(t=0;count!=n;t++)
	{
        short_p = 9;
        for(int i=0;i<n;i++)
		{
            if(a[short_p].pt>a[i].pt && a[i].at<=t && a[i].bt>0)
			{
                short_p = i;
            }
        }
        a[short_p].bt = a[short_p].bt - 1;
        if(a[short_p].bt==0)
		{
            count++;
            a[short_p].wt = t+1 - a[short_p].at - temp[short_p];
            a[short_p].tat = t+1 - a[short_p].at;
            total_WT = total_WT + a[short_p].wt;
            total_TAT = total_TAT + a[short_p].tat;
        }
    } 
    Avg_WT = total_WT/n;
    Avg_TAT = total_TAT/n;
    printf("ID\tWT\tTAT\n");
    for(int i=0;i<n;i++)
	{
        printf("%d\t%d\t%d\n",i+1,a[i].wt,a[i].tat);
    }
    printf("Avg waiting time of the process  is %f\n",Avg_WT);
    printf("Avg turn around time of the process is %f\n",Avg_TAT);
    return 0;
}