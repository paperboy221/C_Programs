#include <stdio.h>
#include <stdlib.h>
int main()
{

int *x = NULL;

x = malloc(sizeof(int));
*x = 6;
printf("x is %d\n", *x);



return 0;

}


