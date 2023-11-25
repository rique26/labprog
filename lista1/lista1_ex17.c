#include <stdio.h>

int main() {
    int numero;

    printf("Digite um valor inteiro: ");
    scanf("%d", &numero);

    numero < 0 ? numero = -numero : numero;

    printf("O valor absoluto é: %d\n", numero);

    return 0;
}
