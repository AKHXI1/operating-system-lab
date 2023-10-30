#include<stdio.h>

void main()
{
	int head_pos,num_disk,i,seek=0,seek_time=0,j,mid=0,max_cylinder;
	printf("Enter the head position : ");
	scanf("%d",&head_pos);
	printf("Enter the number of disk request : ");
	scanf("%d",&num_disk);
	int disk_requests[num_disk+1];
	printf("Enter the maximum size of cylinders : ");
	scanf("%d",&max_cylinder);
	disk_requests[num_disk]=max_cylinder-1;
	printf("Enter the disk requests : ");
	for(i=0;i<num_disk;i++)
		scanf("%d",&disk_requests[i]);
	for(i=0;i<num_disk;i++)
	{
		for(j=0;j<num_disk-i-1;j++)
		{
			if(disk_requests[j]>disk_requests[j+1])
			{
				int temp=disk_requests[j];
				disk_requests[j]=disk_requests[j+1];
				disk_requests[j+1]=temp;
			}
		}
	}
	
	for(i=0;i<num_disk;i++)
	{
		if(disk_requests[i]>head_pos)
	
		{
			mid=i;
			break;
		}
	}
	seek=head_pos-disk_requests[mid];
	if(seek<0)
		seek_time+=(-seek);	
	else
		seek_time+=seek;
		
	printf("The head movement from %d to %d : %d \n",head_pos,disk_requests[mid],seek);
	for(i=mid;i<num_disk;i++)
	{
		seek=disk_requests[i]-disk_requests[i+1];
		if(seek<0)
			seek_time+=(-seek);	
		else
			seek_time+=seek;
		
		//printf("%d\n",seek);
		printf("The head movement from %d to %d : %d \n",disk_requests[i],disk_requests[i+1],seek);
	}
	seek_time+=max_cylinder-1;
	seek=max_cylinder;
	printf("The head movement from %d to 0 : %d\n",max_cylinder-1,seek);
	
	for(i=0;i<mid;i++)
	{
		if(i==0)
		{
			seek=0-disk_requests[i];
			printf("The head movement from 0 to %d : %d \n",disk_requests[i],seek);
		}
		else
		{
			seek=disk_requests[i-1]-disk_requests[i];
			printf("The head movement from %d to %d : %d \n",disk_requests[i-1],disk_requests[i],seek);
		}
		//printf("%d\n",seek);
		if(seek<0)
			seek_time+=(-seek);	
		else
			seek_time+=seek;
	}
	printf("----\n");
	printf("Seek time : %d",seek_time);
	
			
	
}

