#include<stdio.h>

int main()
{
    float mercadoria, entrada;
    int prestacao;
    
    printf("Valor da mercadoria: ");
    scanf("%f", &mercadoria);
    
    prestacao = (float)mercadoria/3;
    entrada = mercadoria - (2*prestacao);
    
    printf("\nEntrada: R$%.2f\n\Prestação: R$%d.00", entrada, prestacao);
    
    return 0;
}
