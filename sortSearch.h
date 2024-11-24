int *srts(int unsorts[], int l)  //Ascending sort of Array unsorts of length l;
{
    static int sorts[5];
    int temp, tempIndex, let;
    for(int i = 0; i < l; i ++)
    {
        temp = unsorts[i];
        tempIndex = i;
        for(int j = i+1; j < l; j ++)
        {
            if(unsorts[j] < temp)
            {
                temp = unsorts[j];
                tempIndex = j;
            }
        }
        sorts[i] = temp;
        let = unsorts[tempIndex];
        unsorts[tempIndex] = unsorts[i];
        unsorts[i] = let;
    }
    return sorts;
}

int *srch(int unsorts[], int sorts[], int l)
{
    static int cx[5];
    for(int i=0; i < l; i ++)
    {
        for(int j=0; j < l; j ++)
        {
            if(sorts[i] == unsorts[j])
            {
                cx[i] = j;
                break;
            }
        }
    }
    return cx;
}

int *sortSetIndex(int unsorts[], int l)
{
    static int indexed[10];
    int temp, tempIndex, let, sorts[10], copyOfUnsorts[10];
    for(int i = 0; i < l; i++)
    {
        copyOfUnsorts[i] = unsorts[i];
    }
    for(int i = 0; i < l; i ++)
    {
        temp = copyOfUnsorts[i];
        tempIndex = i;
        for(int j = i+1; j < l; j ++)
        {
            if(copyOfUnsorts[j] < temp)
            {
                temp = copyOfUnsorts[j];
                tempIndex = j;
            }
        }
        sorts[i] = temp;
        let = copyOfUnsorts[tempIndex];
        copyOfUnsorts[tempIndex] = copyOfUnsorts[i];
        copyOfUnsorts[i] = let;
    }
    for(int i=0; i < l; i ++)
    {
        for(int j=0; j < l; j ++)
        {
            if(sorts[i] == unsorts[j])
            {
                indexed[i] = j;
                break;
            }
        }
    }
    return indexed;
}
