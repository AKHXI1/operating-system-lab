#include <stdio.h> 
void main()
{
	int p,r,a[25],i,b,sum=0;
	printf("Enter the head :");
	scanf("%d",&p);
	printf("Enter the number of requests:");
	scanf("%d",&r);
	printf("Enter the requests:");
	for(i=0;i<r;i++) 
	scanf("%d",&a[i]);
	for(i=0;i<r;i++)
	{
		if(p>a[i])
		{
			b=p-a[i];
		}
		else
		{
			b=a[i]-p;
		}
		printf("The head movement from %d to %d is %d\n:",p,a[i],b);
		p=a[i];
		sum+=b;
	}
printf("The total head movement is %d:",sum);
}
