#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *arr = malloc(5 * sizeof(int));
    if (arr == NULL)
    {
    printf("Memory Allocation Failed Due to Allocation of Pre Defined Memory");
    return 1;
    }
    for(int i = 0; i < 5; i++)
        arr[i] = i * 10;
    printf("%d\n", arr[4]);
    free(arr);
    return 0;
}
