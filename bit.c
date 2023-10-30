  #include <stdio.h>

void implementFirstFit(int blockSize[], int blocks, int processSize[], int processes)
{
    int allocate[processes];
    for (int i = 0; i < processes; i++)
    {
        allocate[i] = -1;
    }
	
    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < blocks; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                allocate[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < processes; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i + 1, processSize[i]);
        if (allocate[i] != -1)
            printf("%d\n", allocate[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void implementBestFit(int blockSize[], int blocks, int processSize[], int processes)
{
    int allocation[processes];
    for (int i = 0; i < processes; i++)
    {
        allocation[i] = -1;
    }

    for (int i = 0; i < processes; i++)
    {
        int indexPlaced = -1;
        for (int j = 0; j < blocks; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (indexPlaced == -1)
                    indexPlaced = j;
                else if (blockSize[j] < blockSize[indexPlaced])
                    indexPlaced = j;
            }
        }

        if (indexPlaced != -1)
        {
            allocation[i] = indexPlaced;
            blockSize[indexPlaced] -= processSize[i];
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < processes; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void implementWorstFit(int blockSize[], int blocks, int processSize[], int processes)
{
    int allocation[processes];
    for (int i = 0; i < processes; i++)
    {
        allocation[i] = -1;
    }

    for (int i = 0; i < processes; i++)
    {
        int indexPlaced = -1;
        for (int j = 0; j < blocks; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (indexPlaced == -1)
                    indexPlaced = j;
                else if (blockSize[j] > blockSize[indexPlaced])
                    indexPlaced = j;
            }
        }

        if (indexPlaced != -1)
        {
            allocation[i] = indexPlaced;
            blockSize[indexPlaced] -= processSize[i];
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < processes; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main()
{
    int blocks, processes,lockSize[];

    printf("Enter the number of memory blocks: ");
    scanf("%d", &blocks);
    int b2
lockSize[blocks];

    printf("Enter the size of each memory block:\n");
    for (int i = 0; i < blocks; i++)
    {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &processes);
    int processSize[processes];

    printf("Enter the size of each process:\n");
    for (int i = 0; i < processes; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    int choice;
    printf("\nSelect memory allocation algorithm:\n");
    printf("1. First Fit\n");
    printf("2. Best Fit\n");
    printf("3. Worst Fit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("First Fit Algorithm:\n");
        implementFirstFit(blockSize, blocks, processSize, processes);
        break;
    case 2:
        printf("Best Fit Algorithm:\n");
        implementBestFit(blockSize, blocks, processSize, processes);
        break;
    case 3:
        printf("Worst Fit Algorithm:\n");
        implementWorstFit(blockSize, blocks, processSize, processes);
        break;
    default:
        printf("Invalid choice!\n");
        break;
    }

    return 0;
}

