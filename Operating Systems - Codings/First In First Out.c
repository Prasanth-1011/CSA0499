#include <stdio.h>

#define Max 100
int frames[Max],pages[Max];
int i,m,n,hit=0,fault=0,counter=0;

void init()
{
    printf("Number of Frames : ");
    scanf("%d", &m);
    printf("Number of Pages : ");
    scanf("%d", &n);
    for (i=0;i<m;i++)
        frames[i] = -1;
    printf("Page Reference String :\n");
    for (i=0;i<n;i++)
        scanf("%d", &pages[i]);
}

int isHit(int page)
{
    for (i=0;i<m;i++)
        if (frames[i] == page)
            return 1;
    return 0;
}

void display()
{
    int i;
    printf("Frame : ");
    for (i = 0; i < m; i++)
        printf("%d\t", frames[i]);
    printf("\n");
}

void FIFO()
{
    int i;
    for (i=0;i<n;i++)
	{
        if (isHit(pages[i]) == 1)
		{
            hit += 1;
            printf("\n%d Hit\n", pages[i]);
        }
		else
		{
            frames[counter] = pages[i];
            counter = (counter + 1) % m;
            fault += 1;
            printf("\n%d Fault\n", pages[i]);
        }
        display();
    }
    printf("\nTotal Hits = %d\n", hit);
    printf("Total Faults = %d\n", fault);
}

int main()
{
    init();
    FIFO();
    return 0;
}