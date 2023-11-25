#include<stdio.h>

int main()
{
    int i;
    
    printf("Quadrado dos inteiro entre 15 e 90 que são múltiplos de 4: \n\n");
    
    for (i=15; i<=90; i++){
        if (i%4==0)
            printf("%d - %d\n",i ,i*i);
    
    }
    
    return 0;
}
