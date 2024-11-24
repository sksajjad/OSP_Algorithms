#include <stdio.h>
display_Need(int need[10][10], int i, int j)
{
    printf("Need: \n");
    for(int i = 0; i < 5; i ++)
    {
        for(int j = 0; j < 3; j ++)
        {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main()
{
    int N, res, sum=0, count=0, flagCount=0;
    int all[10][10], max[10][10], need[10][10], resIns[10], avl[10], flag[10];
    printf("Enter the quantity of process: ");
    scanf("%d", &N);
    printf("Enter the quantity of resources: ");
    scanf("%d", &res);
    printf("Enter the quantity of resource-instance: \n");
    for(int i = 0; i < res; i ++)
    {
        printf("Resource %d Instance: ", i+1);
        scanf("%d", &resIns[i]);
    }
    printf("Enter the process - Allocations(%d): \n", res);
    for(int i = 0; i < N; i ++)
    {
        printf("Process %d: ", i+1);
        for(int j = 0; j < res; j ++)
        {
            scanf("%d", &all[i][j]);
        }
    }
    printf("Enter the process - Max(%d): \n", res);
    for(int i = 0; i < N; i ++)
    {
        printf("Process %d: ", i+1);
        for(int j = 0; j < res; j ++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    printf("\n");
    for(int i = 0; i < N; i ++)
    {
        flag[i] = 0;
    }
    for(int i = 0; i < N; i ++)
    {
        for(int j = 0; j < res; j ++)
        {
            need[i][j] = max[i][j] - all[i][j];
        }
    }
    display_Need(need, N, res);
    for(int i = 0; i < res; i ++)
    {
        for(int j = 0; j < N; j ++)
        {
            sum = sum + all[j][i];
        }
        avl[i] = resIns[i] - sum;
        sum = 0;
    }
    printf("Available: ");
    for(int i = 0; i < res; i ++)
    {
        printf("%d ", avl[i]);
    }
    printf("\n");

    //Processing...
    for(int i = 0; i < N; i++)
    {
        if(flagCount == N)
        {
            break;
        }
        count = 0;
        if(flag[i] == 1)
        {
            continue;
        }
        else
        {
            for(int j = 0; j < res; j ++)
            {
                if(avl[j] >= need[i][j])
                {
                    count ++;
                }
                else
                {
                    break;
                }
            }
            if(count == res)
            {
                printf("proc %d: ", i);
                for(int j = 0; j < res; j ++)
                {
                    avl[j] = avl[j] + all[i][j];
                    printf("%d ", avl[j]);
                }
                flag[i] = 1;
                flagCount ++;
                printf("\n");
            }
        }
        if(i == N-1)
        {
            i = i - N;
        }
    }
    if(flagCount == N)
    {
        printf("Safe State.");
    }
    else
    {
        printf("Not in safe state!");
    }
    //End of processing
    printf("\nRemaining Available: ");
    for(int i = 0; i < res; i++)
    {
        printf("%d ", avl[i]);
    }
    printf("\n");
    return 0;
}
