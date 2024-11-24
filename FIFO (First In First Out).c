#include <stdio.h>
int main()
{
    int frame[10], pages[50];
    int hit = 0, miss = 0, point = 0, exist = 0, frame_len, pages_len;
    printf("Enter the length of the frame: ");
    scanf("%d", &frame_len);
    printf("Enter the total length of the Pages: ");
    scanf("%d", &pages_len);
    printf("Enter the Page numbers(by Space): \n");
    for(int i = 0; i < pages_len; i ++)
    {
        scanf("%d", &pages[i]);
    }
    printf("\n");
    for(int i = 0; i < pages_len; i ++)
    {
        if(point == frame_len)
        {
            point = 0;
        }
        for(int j = 0; j < frame_len; j ++)
        {
            if(pages[i] == frame[j])
            {
                exist = 1;
                hit ++;
                break;
            }
        }
        if(exist == 0)
        {
            frame[point] = pages[i];
            point ++;
            miss ++;
        }
        exist = 0;
    }
    printf("Hit: %d | Miss: %d\n", hit, miss);
    return 0;
}
