#include<stdio.h>

int main()
{
    int n1=1, n2=0, cont=1;
    
    for (cont; cont <= 20; cont++){
        printf("\n%d", n1);
        n1 += n2;
        n2 = n1 - n2;
        
    }
    
    return 0;
}
