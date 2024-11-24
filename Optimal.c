#include <stdio.h>
int main()
{
    int frame[10], pages[50];
    //int frame[3],pages[20]= {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int hit = 0, miss = 0, point = 0, exist = 0, frame_len, pages_len, pos;
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
        //Check...
        if(i < frame_len)
        {
            for(int j = 0; j < i; j ++)
            {
                if(pages[i] == frame[j])
                {
                    exist = 1;
                    hit ++;
                    break;
                }
            }
        }
        else
        {
            for(int j = 0; j < frame_len; j ++)
            {
                if(pages[i] == frame[j])
                {
                    exist = 1;
                    hit ++;
                    break;
                }
            }
        }
        if(exist == 0)
        {
            if(i < frame_len)
            {
                frame[point] = pages[i];
                miss ++;
                point ++;
            }
            else
            {
                for(int j = 0; j < frame_len; j ++)
                {
                    for(int k = i+1; k < pages_len; k ++)
                    {
                        exist = 0;
                        if(frame[j] == pages[k])
                        {
                            exist = 1;
                            if(j == 0)
                            {
                                pos = k;
                                point = j;
                            }
                            else
                            {
                                if(pos < k)
                                {
                                    pos = k;
                                    point = j;
                                }
                            }
                            break;
                        }
                    }
                    if(exist == 0)
                    {
                        point = j;
                        break;
                    }
                }
                frame[point] = pages[i];
                miss ++;
            }
        }
        exist = 0;
    }
    printf("Hit: %d | Miss: %d", hit, miss);
    return 0;
}

