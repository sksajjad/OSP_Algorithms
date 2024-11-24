#include <stdio.h>

int *wait(int gnt[], int pro[], int n, int l)
{
    static int res[10];
    int start, end, countln = 0, sum = 0;
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < l; j ++)
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
        res[i] = sum;
        countln = 0;
        sum = 0;
    }
    return res;
}

int *response(int pro[], int gant[], int pro_len, int n)
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
        //rec[i] = rec[i] - arT[i];
    }
    return rec;
}

int main()
{
    int bt[3] = {8, 9, 16}, q = 3, N = 3;
    //int at[10], bt[10], q, N;
    int *wt, *rt;
    int sum = 0, procCount = 0;
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
    for(int i = 0; ; i ++)
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
                continue;
            }
            else
            {
                if(bt[j] >= q)
                {
                    sum = sum + q;
                    bt[j] = bt[j] - q;
                    count = j;
                }
                else
                {
                    sum = sum + bt[j];
                    bt[j] = 0;
                    count = j;
                }
            }
            gantt[procCount+1] = sum;
            proc[procCount] = count;
            procCount ++;
        }
    }
    wt = wait(gantt, proc, N, procCount);
    rt = response(proc, gantt, procCount, N);
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
    for(int i = 0; i < procCount;  i ++)
    {
        printf("%d ", proc[i]+1);
    }
    printf("\n");
    printf("Gantt: ");
    for(int i = 0; i < procCount+1;  i ++)
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

