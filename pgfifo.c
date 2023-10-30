#include<stdio.h>

int main()
{
    int frameno,len,i,j,pageFaults=0,current=0;
    
    printf("Enter the number of frames: ");
    scanf("%d", &frameno);
    
    printf("Enter the reference string length: ");
    scanf("%d", &len);
    
    int refstr[len], q[frameno];

    printf("Enter the reference string:\n");
    for (i=0;i<len;i++)
    {
        scanf("%d",&refstr[i]);
    }
    
    for(j=0;j<frameno;j++)
    {
    	q[j]=-1;
    }
    
    for (i=0;i<len;i++)
    {
        int pageFound=0;
        int page=refstr[i];
        for(j=0;j<frameno;j++)
        {
            if(q[j]==page)
            {
                pageFound=1;
                printf("       ----------");
                printf("\nhit  : |");
                for(j=0;j<frameno;j++)
                {
            		if(q[j]!=-1)
            		{
            			printf("%d |",q[j]);
            		}
            		else
            		{
            			printf("  |");
            		}
            	}
            	printf("\n       ----------\n");
                break;
            }
        }
        if(pageFound==0)
        {
            q[current]=page;
            printf("       ----------");
            printf("\nmiss : |");
            for(j=0;j<frameno;j++)
            {
            	if(q[j]!=-1)
            	{
            		printf("%d |",q[j]);
            	}
            	else
            	{
            		printf("  |");
            	}
            }
            printf("\n       ----------\n");
            current=(current+1)%frameno;
            pageFaults++;
        }
    }
    printf("\nTotal Page Faults: %d\n",pageFaults);
}
