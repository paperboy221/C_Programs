#include <stdio.h>
#include <stdlib.h>

int main ()
{
    
    int *arr = NULL;
    int count=0,i=0,input=0;
    
    printf("Enter a number, 0 to quit: ");
    
    scanf("%d", &input);
    while (input != 0)
    {
        count++;
        arr = realloc(arr, sizeof(int)*count);
    
    if( arr == NULL){
        
        printf("Error allocating space\n");
        exit(1);
        
    }
    
    arr[count-1]=input;
    printf("Enter a number, 0 to quit: ");
    scanf("%d", &input);
}
for(i=0;i<count; ++i)
{
printf("%d ", arr[i]);
    
}
printf("\n");

free(arr);
    

return 0;
    
}
