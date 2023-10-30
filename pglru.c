#include <stdio.h>

int main()
{
    int frameno, len, i, j, pageFaults = 0, current = 0;

    printf("Enter the number of frames: ");
    scanf("%d", &frameno);

    printf("Enter the reference string length: ");
    scanf("%d", &len);

    int refstr[len], q[frameno], counter[frameno];

    printf("Enter the reference string:\n");
    for (i = 0; i < len; i++)
    {
        scanf("%d", &refstr[i]);
    }

    for (j = 0; j < frameno; j++)
    {
        q[j] = -1;
        counter[j] = 0;
    }

    for (i = 0; i < len; i++)
    {
        int pageFound = 0;
        int page = refstr[i];
        int foundIndex = -1; // Track the index where the page was found

        for (j = 0; j < frameno; j++)
        {
            if (q[j] == page)
            {
                pageFound = 1;
                foundIndex = j; // Store the index of the found page
                printf("       ----------");
                printf("\nhit  : |");
                for (int k = 0; k < frameno; k++) // Use a different variable for the inner loop
                {
                    if (q[k] != -1)
                    {
                        printf("%d |", q[k]);
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
        if (pageFound == 0)
        {
            // Find the index of the least recently used page
            int minCounter = counter[0];
            int minIndex = 0;
            for (j = 1; j < frameno; j++)
            {
                if (counter[j] < minCounter)
                {
                    minCounter = counter[j];
                    minIndex = j;
                }
            }

            q[minIndex] = page;
            counter[minIndex] = i + 1; // Update the counter with the current reference string index
            printf("       ----------");
            printf("\nmiss : |");
            for (j = 0; j < frameno; j++)
            {
                if (q[j] != -1)
                {
                    printf("%d |", q[j]);
                }
                else
                {
                    printf("  |");
                }
            }
            printf("\n       ----------\n");
            pageFaults++;
        }
        else
        {
            // Update the counter with the current reference string index only if the page was found
            counter[foundIndex] = i + 1;
        }
    }
    printf("\nTotal Page Faults: %d\n", pageFaults);
    return 0;
}


