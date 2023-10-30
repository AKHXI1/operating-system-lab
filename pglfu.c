#include <stdio.h>
#include <stdbool.h>

int main()
{
    int frameno, len, i, j, pageFaults = 0, current = 0;

    printf("Enter the number of frames: ");
    scanf("%d", &frameno);

    printf("Enter the reference string length: ");
    scanf("%d", &len);

    int refstr[len], q[frameno], frequency[frameno];

    printf("Enter the reference string:\n");
    for (i = 0; i < len; i++)
    {
        scanf("%d", &refstr[i]);
    }

    for (j = 0; j < frameno; j++)
    {
        q[j] = -1;
        frequency[j] = 0;
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
            // Find the index of the page with the minimum frequency
            int minFrequency = frequency[0];
            int minIndex = 0;
            for (j = 1; j < frameno; j++)
            {
                if (frequency[j] < minFrequency)
                {
                    minFrequency = frequency[j];
                    minIndex = j;
                }
            }

            q[minIndex] = page;
            frequency[minIndex] = 1; // Initialize the frequency to 1 for the new page
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
            // Increment the frequency of the found page
            frequency[foundIndex]++;
        }
    }
    printf("\nTotal Page Faults: %d\n", pageFaults);
    return 0;
}

