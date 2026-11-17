#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, head, i, j, total1 = 0, total2 = 0;
    int req[50], visited[50] = {0};
    int pos, min, current;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    // FCFS
    current = head;
    printf("\nFCFS Service Order: %d", head);

    for(i = 0; i < n; i++)
    {
        total1 += abs(current - req[i]);
        current = req[i];
        printf(" -> %d", current);
    }

    printf("\nFCFS Total Head Movement: %d\n", total1);

    // SSTF
    current = head;
    printf("\nSSTF Service Order: %d", head);

    for(i = 0; i < n; i++)
    {
        min = 9999;
        pos = -1;

        for(j = 0; j < n; j++)
        {
            if(!visited[j] && abs(current - req[j]) < min)
            {
                min = abs(current - req[j]);
                pos = j;
            }
        }

        visited[pos] = 1;
        total2 += min;
        current = req[pos];

        printf(" -> %d", current);
    }

    printf("\nSSTF Total Head Movement: %d\n", total2);

    if(total1 < total2)
        printf("\nFCFS provides less head movement.");
    else if(total2 < total1)
        printf("\nSSTF provides less head movement.");
    else
        printf("\nBoth algorithms have equal movement.");

    return 0;
}
