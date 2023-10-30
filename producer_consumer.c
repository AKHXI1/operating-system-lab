#include <stdio.h>
#include <stdlib.h>
int mutex = 1,full = 0,empty = 3,item=0;
int wait(int s)
{
	return --s;
}
int signal(int s)
{
	return ++s;
}
void producer()
{
	mutex=wait(mutex);
	full=signal(full);
	empty=wait(empty);
	item=signal(item);
	printf("the producer produce the item %d",item);
	mutex=signal(mutex);
}
void consumer()
{
	mutex=wait(mutex);
	full=wait(full);
	empty=signal(empty);
	printf("the Consumer consumes the item %d",item);
	item=wait(item);
	mutex=signal(mutex);
}
int main()
{
	while(1)
	{
		int n, i;
		printf("\n1. Press 1 for Producer"
			"\n2. Press 2 for Consumer"
			"\n3. Press 3 for Exit");

		for (i = 1; i > 0; i++) 
		{

			printf("\nEnter your choice:");
			scanf("%d", &n);
			switch (n) 
			{
				case 1:

					
					if ((mutex == 1)&&(empty != 0)) 
					{
						producer();
					}
					else 
					{
						printf("Buffer is full!");
					}
					break;

				case 2:

					
					if ((mutex == 1)
						&& (full != 0)) {
						consumer();
					}
					else {
						printf("Buffer is empty!");
					}
					break;

				case 3:
					exit(0);
					break;
			}
		}
	}
}


