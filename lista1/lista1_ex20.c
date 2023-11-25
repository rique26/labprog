#include <stdio.h>

int main()
{
    int numero;

    printf("Digite um número: ");
    scanf("%d", &numero);

    numero%2 ? printf("%d é ímpar.\n", numero) : printf("%d é par.\n", numero);

    return 0;
}
