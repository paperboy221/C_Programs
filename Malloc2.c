#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    int *arr = NULL;
    int x = 10;
    int i = 0;
    
    arr = malloc(sizeof(int)*x);
    if(arr == NULL){
        printf("Error allocting space\n");
        exit(1);
    }
    for(i=0;i<x; ++i)
    {
        arr[i] = i*2;
    }
    for(i=0;i<10;++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    arr = realloc(arr, sizeof(int)*x*2);
    if(arr == NULL)
    {
        printf("Error allocating space.\n");
        exit(1);
    }
    
    for(i=x;i<x*2; ++i)
    {
        arr[i] = 2*x-i;
        
    }
    for(i=0;i<x*2; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    
    
    
    
    
    
    
    
    return 0;
}




