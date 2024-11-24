#include <stdio.h>
#include "sortSearch.h"

int *wait(int arrT[], int gnt[], int pro[], int n, int l)
{
    static int res[10];
    int start, end, countln = 0, sum = 0;
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < l-1; j ++)
        {
          if(pro[j] == i)
          {
            countln ++;
            if(countln == 1)
            {
              start = gnt[j];
              end = gnt[j+1];
              sum = start;
            }
            else
            {
              start = gnt[j] - end;
              sum = sum + start;
              end = gnt[j+1];
            }
          }
        }
        res[i] = sum - arrT[i];
        countln = 0;
        sum = 0;
    }
    return res;
}

int main()
{
    int at[10], bt[10];
    int burT[10], proc[10], gantt[20];
    int sum = 0, temp, count = 0, start, N, zero, ganttLen = 0, caCount = 1;
    int *ca, *wt, tat[10];
    float avg_wt = 0.0, avg_tat = 0.0;
    printf("Enter Process Quantity: ");
    scanf("%d", &N);
    printf("...\n");
    for(int i = 0; i < N; i ++)
    {
        printf("Enter Process %d Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
    }
    printf("...\n");
    for(int i = 0; i < N; i ++)
    {
        printf("Enter Process %d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
    }
    ca = sortSetIndex(at, N);
    gantt[0] = 0;
    proc[0] = ca[0];
    temp = at[ca[1]];
    for (int i = 0; i < N; i ++)
    {
        burT[i] = bt[i];
    }
    //Gantt Chart:
    int minBT = at[ca[1]];
    int minIndex = ca[0];
    for(int i = 1; i < 10; i ++)
    {
        if(zero == N)
        {
            break;
        }
        zero = 0;
        for(int j = 0; j < N; j ++)
        {
            if(bt[j] == 0)
            {
                zero ++;
            }
            if(at[j] <= sum)
            {
                count ++;
                if(count > 1)
                {
                    if(bt[j] == 0)
                    {
                        continue;
                    }
                    else if(bt[j] < temp)
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
        if(at[ca[caCount]] <= temp && sum < at[ca[N-1]])
        {
            temp = at[ca[caCount]];
            caCount ++;
        }
        minBT = temp;
        sum = sum + minBT;
        gantt[i] = sum;
        ganttLen ++;
        proc[i-1] = minIndex;
        bt[minIndex] = bt[minIndex] - temp;
        count = 0;
    }
    wt = wait(at, gantt, proc, N, ganttLen);
    for(int i = 0; i < N; i ++)
    {
        tat[i] = burT[i] + wt[i];
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
    printf("\nProcess Priority: ");
    for(int i = 0; i < ganttLen-1; i ++)
    {
        printf("P%d ", proc[i]+1);
    }
    printf("\nGantt Chart: ");
    for(int i = 0; i < ganttLen; i ++)
    {
        printf("%d ", gantt[i]);
    }
    printf("\nWT: ");
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
