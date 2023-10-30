#include<stdio.h>

void main()
{
	int process,blkno,i,j;
	
	printf("Enter the no. of processes :");
	scanf("%d",&process);
	printf("Enter the no. of blocks:");
	scanf("%d",&blkno);
	
	int flag[process],p[process],block[blkno];
	
	printf("\nEnter the size of each block : \n");
	for(j=0;j<blkno;j++)
	{
		printf("Enter the size of block %d : ",j+1);
		scanf("%d",&block[j]);
	}
	
	printf("\nEnter the size of each process : \n");
	for(i=0;i<process;i++)
	{
		printf("Enter the size of process %d : ",i+1);
		scanf("%d",&p[i]);
		flag[i]=0;
	}
	for(i=0;i<process;i++)
	{
		for(j=0;j<blkno;j++)
		{
			if(block[j]>=p[i])
			{
				flag[i]=j+1;
				block[j]-=p[i];
				break;
			}
		}
	}
	
	printf("\nPROCESS\t\tPROCESS SIZE\tSTATUS\n");
	for(i=0;i<process;i++)
	{
		if(flag[i]==0)
		{
			printf("Process %d\t\t%d\tnot inserted\n",i+1,p[i]);
		}
		else
		{
			printf("Process %d\t\t%d\tinserted in block%d\n",i+1,p[i],flag[i]);
			
		}
	}
}


