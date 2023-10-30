#include<stdio.h>
void turnaroundtime(int process[],int n,int ct[],int tat[])
{
  for(int i=0;i<n;i++)
     tat[i]=ct[i];
}
void waitingtime(int process[],int n,int tat[],int bt[],int wt[])
{
  for(int i=0;i<n;i++)
      wt[i]=tat[i]-bt[i];
}
void averagetime(int n,int bt[],int wt[])
{
	int sumtat,avgtat,sumwt,tat[25],avgwt;
	printf("The Average Turn around time is:");
	for(int i=0;i<n;i++)
	{
		sumtat+=tat[i];
		avgtat=sumtat/n;
	}
	printf("The Average Waiting Time is:");
	for(int i=0;i<n;i++)
	{
		sumwt+=wt[i];
		avgwt=sumwt/n;
	}
}
void main()
{
	int n;
	 printf("Enter the no of processes:");
	 scanf("%d",&n);
	 int bt[n],ct[n],wt[n],tat[n],i,process[n];
	 printf("Enter the Burst Time:");
	 for(int i=0;i<n;i++)
	  scanf("%d",&bt[i]);
	   turnaroundtime(process,n,ct,tat);
	   waitingtime(process,n,tat,bt,wt);
	   printf("Proces");
	   for(i=0;i<n;i++)
	   {
		   process[i]=i+1;
		  printf(" %d \t",process[i]);
	  }
	  averagetime(n,bt,wt);
	  printf("\nThe completion time is:");
	  ct[0]=bt[0];
	  printf("%d\t",ct[0]);
	 for(int i=1;i<n;i++)
	   printf("%d\t",ct[i]=bt[i]+bt[i-1]);
	 
}


