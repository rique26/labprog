#include <stdio.h>

int main()
{
    int x, centena, dezena, unidade;
    
    printf("Digite o valor de x: ");
    scanf("%d", &x);
    
    centena = x / 100; //3
    dezena = (x / 10) %10; //2
    unidade = x % 10; //5
    
    x = unidade*100 + dezena*10 + centena;
    
    printf("Valor invertido: %d", x);

    return 0;
}
    
