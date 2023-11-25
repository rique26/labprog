#include <stdio.h>


int main()
{
    float raio, diametro, circunferencia, area, pi = 3.14159;
    
    printf("Digite o raio do circulo: ");
    scanf("%f", &raio);

    diametro = raio*2;
    circunferencia = 2*pi*raio;
    area = pi*raio*raio;

    printf("\nDiamêtro: %.2f \nCircunferência: %.2f \nÁrea: %.2f\n", diametro, circunferencia, area);
  
    return 0;
}
