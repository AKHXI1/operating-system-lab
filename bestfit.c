#include<stdio.h>

void main()
{
    int process,blkno,i,j;
    
    printf("Enter the number of processes: ");
    scanf("%d",&process);
    printf("Enter the number of blocks: ");
    scanf("%d",&blkno);
    
    int flag[process],p[process],block[blkno];
    
    printf("\nEnter the size of each block:\n");
    for(j=0;j<blkno;j++)
    {
        printf("Enter the size of block %d: ",j + 1);
        scanf("%d",&block[j]);
    }
    
    printf("\nEnter the size of each process:\n");
    for(i=0;i<process;i++)
    {
        printf("Enter the size of process %d: ",i+1);
        scanf("%d",&p[i]);
        flag[i]=-1;
    }
    
    for(i=0;i<process;i++)
    {
        int best=-1;
        int smallest=9999999;
        
        for(j=0;j<blkno; j++)
        {
            if(block[j]>=p[i] && block[j]-p[i]< smallest)
            {
                best=j;
                smallest=block[j]-p[i];
            }
        }
        
        if(best!= -1)
        {
            flag[i]=best+1;
            block[best]-=p[i];
        }
    }
    
    printf("\nPROCESS\t\tPROCESS SIZE\tSTATUS\n");
	for(i=0;i<process;i++)
	{
		if(flag[i]==-1)
		{
			printf("Process %d\t\t%d\tnot inserted\n",i+1,p[i]);
		}
		else
		{
			printf("Process %d\t\t%d\tinserted in block%d\n",i+1,p[i],flag[i]);
			
		}
	}
}
