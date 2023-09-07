#include<stdio.h>

int main()
{
    unsigned int f, fatorial = 1, i = 1;
    
    printf("Digite o valor de f: ");
    scanf("%d", &f);
    
    for (i; i <= f; ++i){
        fatorial *= i;
    }
    
    printf("Fatorial: %d", fatorial);
    
    return 0;
}
