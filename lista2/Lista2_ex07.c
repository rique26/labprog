#include<stdio.h>

int main()
{
    float n1,n2;
    
    do{
        printf("\n\nValor de n1: ");
        scanf("%f", &n1);
        printf("Valor de n2: ");
        scanf("%f", &n2);
        
        printf("O resultado é %.1f", n1/n2);
    
    } while (n2 == 0);
        
    return 0;
}
