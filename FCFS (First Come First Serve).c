#include <stdio.h>
int main()
{
    int burst[10], wait[10], response[10], tat[10], gantt[10], Ctime = 0, proc;
    float AWT = 0.0, ATAT = 0.0, sumWT = 0.0, sumTAT = 0.0;
    gantt[0] = 0;
    printf("Enter the quantity of Process: ");
    scanf("%d", &proc);
    for(int i = 0; i < proc; i ++)
    {
        printf("Process %d Burst Time: ", i+1);
        scanf("%d", &burst[i]);
    }
    for(int i = 0; i < proc; i ++)
    {
        Ctime = Ctime + burst[i];
        gantt[i+1] = gantt[i] + burst[i];
        wait[i] = gantt[i];
        response[i] = gantt[i];
        tat[i] = wait[i] + burst[i];
    }
    printf("\nGantt Chart: ");
    for(int i = 0; i < proc+1; i ++)
    {
        printf("%d ", gantt[i]);
    }
    printf("\n\nProc  Burs  Wait Resp  TAT\n");
    for(int i = 0; i < proc; i ++)
    {
        printf("P%d    %d     %d     %d     %d\n", i+1, burst[i],wait[i], response[i], tat[i]);
    }
    for(int i = 0; i < proc; i ++)
    {
        sumWT = sumWT + wait[i];
        sumTAT = sumTAT +tat[i];
    }
    AWT = sumWT / proc;
    ATAT = sumTAT / proc;
    printf("\nAvg. of WT: %.3f\n", AWT);
    printf("Avg. of TAT: %.3f", ATAT);
    return 0;
}
