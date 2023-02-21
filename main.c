#include <stdio.h>
#include <stdlib.h>


#include "vendas.h"

int main()
{
    int num;
    while(1>0)
    {
        menu();
        scanf("%d",&num);
        casos(num);
    }
    return 0;
}