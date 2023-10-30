#include<stdio.h>
#include<stdlib.h>

void main()
{
	int num,i;
	float sumtat=0,sumwt=0;
	printf("Enter the number of processes: ");
	scanf("%d",&num);
	int bt[num],exet[num],tat[num],wt[num];
	printf("Enter the burst time of each process:\n");
	for(i=0;i<num;i++)
	{
		scanf("%d",&bt[i]);
	}
	
	//Execution time
	exet[0]=bt[0];
	for(i=1;i<num;i++)
	{
		exet[i]=exet[i-1]+bt[i];
	}
	//Turn Around Time
	for(i=0;i<num;i++)
	{
		tat[i]=exet[i];
	}
	//Waiting Time
	for(i=0;i<num;i++)
	{
		wt[i]=tat[i]-bt[i];
	}
	//avg Turn Around Time
	for(i=0;i<num;i++)
	{
		sumtat=sumtat+tat[i];
	}
	//avg Waiting Time
	for(i=0;i<num;i++)
	{
		sumwt=sumwt+wt[i];
	}
	
	printf("PROCESS\tBURST TIME\tTAT\tWT\n");
	for(i=0;i<num;i++)
	{
		printf("P%d\t%d\t\t%d\t%d\n",i,bt[i],tat[i],wt[i]);
	}
	
	printf("\nTotal Turn Around Time=%f\n",sumtat);
	printf("Total Waiting Time=%f\n",sumwt);
	printf("Average Turn Around time=%f\n",sumtat/num);
	printf("Average Waiting time=%f\n\n",sumwt/num);
	
	//Gantt Chart
	printf("---------------------\n");
	for(i=0;i<num;i++)
	{
		printf("| P%d ",i);
	}
	printf("\n---------------------\n");
	printf("0");
	for(i=0;i<num;i++)
	{
		printf("   %d",exet[i]);
	}
	printf("\n");
}

