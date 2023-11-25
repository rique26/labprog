#include<stdio.h>

int main()
{   
	float cot_dolar;
	float real;
    float result;
    
    printf("--- Conversão de dólar para real ---\n\n");
    printf("Cotação do dólar: R$");
    scanf("%f", &cot_dolar);
    printf("Valor em reais : R$");
    scanf("%f", &real);
    
    result = cot_dolar*real;
    printf("\nValor convertido: R$%.2f", result);
    
    return 0;
}
