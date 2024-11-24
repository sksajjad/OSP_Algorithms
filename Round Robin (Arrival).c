#include <stdio.h>

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

int *response(int arT[], int pro[], int gant[], int pro_len, int n)
{
    static int rec[10];
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < pro_len; j ++)
        {
            if(pro[j] == i)
            {
                rec[i] = gant[j];
                break;
            }
        }
        rec[i] = rec[i] - arT[i];
    }
    return rec;
}

int main()
{
    int at[5] = {0, 1, 2, 3, 4}, bt[5] = {6, 3, 5, 1, 4}, q = 2, N = 5;
    //int at[10], bt[10], q, N;
    int *wt, *rt;
    int sum = 0, readyCount = 0;
    int burT[10], tat[10], proc[30], ready[30], gantt[30], zero;
    int count = 0;
    float avg_wt = 0, avg_rt = 0, avg_tat = 0;
    gantt[0] = 0;
    /*
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
    printf("...\n");
    printf("Enter Time Quantum: ");
    scanf("%d", &q);
    printf("...\n");
    */
    for(int i = 0; i < N; i ++)
    {
        burT[i] = bt[i];
    }
    for(int i = 0; i < 11; i ++)
    {
        zero = 0;
        for(int j = 0; j < N; j ++)
        {
            if(at[j] <= sum)
            {
                if(bt[j] == 0)
                {
                    zero ++;
                    continue;
                }
                if(i == 0)
                {
                    ready[readyCount] = j;
                    readyCount ++;
                    count = j;
                }
            }
        }
        proc[i] = ready[i];
        if(bt[proc[i]] >= q)
        {
            sum = sum + q;
            gantt[i+1] = sum;
            bt[proc[i]] = bt[proc[i]] - q;
        }
        else
        {
            sum = sum + bt[proc[i]];
            gantt[i+1] = sum;
            bt[proc[i]] = 0;
        }
        if(count < N)
        {
            for(int j = count+1; j < N; j ++)
            {
                if(at[j] <= sum)
                {
                    if(bt[j] == 0)
                    {
                        continue;
                    }
                    ready[readyCount] = j;
                    readyCount ++;
                    count = j;
                }
            }
        }
        if(bt[proc[i]] > 0)
        {
            ready[readyCount] = proc[i];
            readyCount ++;
        }
        if(zero == N)
        {
            break;
        }
    }
    wt = wait(at, gantt, proc, N, readyCount+1);
    rt = response(at, proc, gantt, readyCount, N);
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
        avg_rt = avg_rt + rt[i];
    }
    avg_rt = avg_rt / N;
    for(int i = 0; i < N; i ++)
    {
        avg_tat = avg_tat + tat[i];
    }
    avg_tat = avg_tat / N;
    printf("Proc: ");
    for(int i = 0; i < readyCount;  i ++)
    {
        printf("%d ", proc[i]+1);
    }
    printf("\n");
    printf("Gantt: ");
    for(int i = 0; i < readyCount+1;  i ++)
    {
        printf("%d ", gantt[i]);
    }
    printf("\n");
    printf("WT: ");
    for(int i = 0; i < N;  i ++)
    {
        printf("%d ", wt[i]);
    }
    printf("\n");
    printf("RT: ");
    for(int i = 0; i < N;  i ++)
    {
        printf("%d ", rt[i]);
    }
    printf("\n");
    printf("TAT: ");
    for(int i = 0; i < N;  i ++)
    {
        printf("%d ", tat[i]);
    }
    printf("\n");
    printf("Avg. WT: %.3f\nAvg. RT: %.3f\nAvg. TAT: %.3f\n", avg_wt, avg_rt, avg_tat);
    return 0;
}
