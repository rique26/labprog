#include <stdio.h>

int calcular(int x, int y, int opcao){
    if(opcao == 1)
        return x+y;
    else if(opcao == 2)
        return x*y;
}

int main(){
    int n1, n2, opcao;

    printf("Digite o primeiro valor: ");scanf("%d", &n1);
    printf("Digite o segundo valor: ");scanf("%d", &n2);
    printf("\n1 - soma\n2 - multiplicacao\nDigite uma das opcoes acima: ");scanf("%d", &opcao);
    printf("\nResultado: %d", calcular(n1, n2, opcao));

    return 0;
}

