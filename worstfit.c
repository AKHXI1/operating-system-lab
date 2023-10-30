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
        printf("Enter the size of block %d: ",j+1);
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
        int worst=-1;
        int largest=-1;
        
        for(j=0;j<blkno;j++)
        {
            if(block[j]>=p[i] && block[j]-p[i] > largest)
            {
                worst=j;
                largest=block[j]-p[i];
            }
        }
        
        if(worst!=-1)
        {
            flag[i]=worst + 1;
            block[worst] -= p[i];
        }
    }
    
    printf("\nPROCESS\t\tPROCESS SIZE\tSTATUS\n");
    for(i=0;i<process;i++)
    {
        if(flag[i]==-1)
        {
            printf("Process %d\t\t%d\t\tNot inserted\n",i+1,p[i]);
        }
        else
        {
            printf("Process %d\t\t%d\t\tInserted in block %d\n",i+1,p[i],flag[i]);
        }
    }
}


