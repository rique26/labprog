#include<stdio.h>

int main()
{   
    int valor;

    printf("Digite um valor inteiro: ");
    scanf("%d", &valor);

    printf("O valor %d ao quadrado é: %d", valor, valor*valor);

    return 0;
}
