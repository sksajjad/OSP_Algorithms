#include <stdio.h>
int minIndexArray(int arr[], int n)
{
    int minArr = arr[0];
    for(int i = 0; i < n-1; i ++)
    {
        (arr[i+1] < minArr) ? minArr = i+1 : minArr;
    }
    return minArr;
}
int wait(int arrT[], int gnt[], int cA[], int l, int n)
{
    int value;
    for(int i = 0; i < n; i ++)
    {
        if(cA[i] == l)
        {
            value = gnt[i];
            value = value - arrT[l];
        }
    }
    return value;
}
int main()
{
    int at[10], arT[10], bt[10], ca[10], sort[10], gantt[10], sum = 0, temp, count = 0, start, N;
    int wt[10], tat[10];
    float avg_wt = 0.0, avg_tat = 0.0;
    printf("Enter Process Quantity: ");
    scanf("%d", &N);
    for(int i = 0; i < N; i ++)
    {
        printf("Process %d Arrival Time: ", i+1);
        scanf("%d", &at[i]);
    }
    for(int i = 0; i < N; i ++)
    {
        printf("Process %d Burst Time: ", i+1);
        scanf("%d", &bt[i]);
    }
    printf("\n");
    sort[0] = at[0];
    ca[0] = 0;
    gantt[0] = 0;
    for (int i = 0; i < N; i ++)
    {
        arT[i] = at[i];
    }
    start = minIndexArray(at, N);
    int minBT = bt[start];
    int minIndex = start;
    for(int i = 1; i < N+1; i ++)
    {
        sum = sum + minBT;
        gantt[i] = sum;
        ca[i-1] = minIndex;
        for(int j = 0; j < N; j ++)
        {
            if(arT[j] == 0)
            {
                continue;
            }
            if(arT[j] <= sum)
            {
                count ++;
                if(count > 1)
                {
                    if(bt[j] < temp)
                    {
                        temp = bt[j];
                        minIndex = j;
                    }
                }
                else
                {
                    temp = bt[j];
                    minIndex = j;
                }
            }
        }
        minBT = temp;
        arT[minIndex] = 0;
        count = 0;
    }
    for(int i = 0; i < N; i ++)
    {
        wt[i] = wait(at, gantt, ca, i, N);
    }
    for(int i = 0; i < N; i ++)
    {
        tat[i] = bt[i] + wt[i];
    }
    for(int i = 0; i < N; i ++)
    {
        avg_wt = avg_wt + wt[i];
    }
    avg_wt = avg_wt / N;
    for(int i = 0; i < N; i ++)
    {
        avg_tat = avg_tat + tat[i];
    }
    avg_tat = avg_tat / N;
    printf("Process Priority: ");
    for(int i = 0; i < N; i ++)
    {
        printf("%d ", ca[i] + 1);
    }
    printf("\nGantt: ");
    for(int i = 0; i < N+1; i ++)
    {
        printf("%d ", gantt[i]);
    }
    printf("\nWaiting: ");
    for(int i = 0; i < N; i ++)
    {
        printf("%d ", wt[i]);
    }
    printf("\nTAT: ");
    for(int i = 0; i < N; i ++)
    {
        printf("%d ", tat[i]);
    }
    printf("\nAvg. WT: %.2f\nAvg. TAT: %.2f\n", avg_wt, avg_tat);
    return 0;
}
