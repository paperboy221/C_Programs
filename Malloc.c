#include <stdio.h>
#include <stdlib.h>
int main()
{
    
    // int x pointer to variabe
    int *x = NULL;
    
    x = malloc(sizeof(int));
    *x = 6;
    printf("x is %d\n", *x);
    
    // int array pointer to array
    int *arr = NULL;
    arr = malloc(sizeof(int) * 10);
    
    int i = 0;
    for (i=0;i<10;++i){
        arr[i] = i * 2;
    }
    
    for (i=0;i<10;i++){
      printf("%d ", arr[i]);
               }
               printf("\n");
   // free space from computer
    free(x);
    free(arr);
               return 0;
               
               }

               
