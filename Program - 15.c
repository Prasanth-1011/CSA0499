#include<string.h>
#include<stdlib.h>
#include<stdio.h>
struct
{
	char dname[10],fname[10][10];
	int fcnt;
} dir[10];

void main()
{
	int i,ch,dcnt,k;
	char f[30], d[30];
	dcnt = 0;
	while(1)
	{
		printf("\n\n1. Create Directory\t2. Create File\t3. Delete File");
		printf("\n4. Search File\t\t5. Display\t6. Exit\tEnter Your Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the Name of the Directory : ");
				scanf("%s", dir[dcnt].dname);
				dir[dcnt].fcnt=0;
				dcnt++;
				printf("Directory Created");
				break;
			case 2:
				printf("\nEnter the Name of the Directory : ");
				scanf("%s",d);
				for(i=0; i<dcnt; i++)
					if(strcmp(d,dir[i].dname)==0)
					{
						printf("Enter the Name of the File : ");
						scanf("%s",dir[i].fname[dir[i].fcnt]);
						printf("File Created");
						break;
					}
				if(i==dcnt)
					printf("Directory %s Not Found",d);
				break;
			case 3:
				printf("\nEnter the Name of the Directory : ");
				scanf("%s",d);
				for(i=0; i<dcnt; i++)
				{
					if(strcmp(d,dir[i].dname)==0)
					{
						printf("Enter the Name of the File : ");
						scanf("%s",f);
						for(k=0; k<dir[i].fcnt; k++)
						{
							if(strcmp(f, dir[i].fname[k])==0)
							{
								printf("File %s is Deleted ",f);
								dir[i].fcnt--;
								strcpy(dir[i].fname[k],dir[i].fname[dir[i].fcnt]);
								goto jmp;
							}
						}
						printf("File %s Not Found",f);
						goto jmp;
					}
				}
				printf("Directory %s Not Found",d);
jmp :
				break;
			case 4:
				printf("\nEnter Name of the Directory : ");
				scanf("%s",d);
				for(i=0; i<dcnt; i++)
				{
					if(strcmp(d,dir[i].dname)==0)
					{
						printf("Enter the Name of the File : ");
						scanf("%s",f);
						for(k=0; k<dir[i].fcnt; k++) {
							if(strcmp(f, dir[i].fname[k])==0)
							{
								printf("File %s is Found ",f);
								goto jmp1;
							}
						}
						printf("File %s Not Found",f);
						goto jmp1;
					}
				}
				printf("Directory %s Not Found",d);
jmp1:
				break;
			case 5:
				if(dcnt==0)
					printf("\nNo Directory's ");
				else {
					printf("\nDirectory\tFiles");
					for(i=0; i<dcnt; i++) {
						printf("\n%s\t\t",dir[i].dname);
						for(k=0; k<dir[i].fcnt; k++)
							printf("\t%s",dir[i].fname[k]);
					}
				}
				break;
			default:
				exit(0);
		}
	}
}