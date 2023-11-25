#include <stdio.h>

int main()
{
    int n1, n2;

    printf("Digite um número: ");
    scanf("%d", &n1);
    printf("Digite outro número: ");
    scanf("%d", &n2);

    n1 % n2 ? printf("%d não é multiplo de %d.\n", n1, n2) : printf("%d é multiplo de %d.\n", n1, n2);

    return 0;
} 

