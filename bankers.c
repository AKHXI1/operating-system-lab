#include<stdio.h>
void main()
{
	int n,r,i,j;
	printf("enter the no of processes");
	scanf("%d",&n);
	printf("enter the no of resources");
	scanf("%d",&r);
	int allocation[n][r],max[n][r],available[r],need[n][r];
	printf("enter the available resource:");
	for(i=0;i=r;i++)
	{
		scanf("%d",&available[i]);
		for(i=0;i<n;i++)
		{
			printf("enter the allocation of the processes %d",i);
			for(j=0;j<r;j++)
			{
				scanf("%d",&allocation[i][j]);
			}
		}
		printf("enter the max of the processes %d:",i);
		for(j=0;j<r;j++)
		{
			scanf("%d",&max[i][j]);
		}
		for(j=0;j<r;j++)
		
		{
			
		}
