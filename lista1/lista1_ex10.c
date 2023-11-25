#include<stdio.h>

int main()
{   
    float comprimento, largura, altura;
    float volume;

    printf("-- CALCULAR VOLUME DE CAIXA RETANGULAR --\n\n");
    printf("Digite os valores da caixa em metros:\n\n ");

    printf("Comprimento: ");
    scanf("%f", &comprimento);

    printf(" Largura: ");
    scanf("%f", &largura);

    printf(" Altura: ");
    scanf("%f", &altura);

    volume = comprimento*largura*altura;

    printf("\nVolume da caixa: %.2fm³", volume );

    return 0;
}
