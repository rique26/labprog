#include <stdio.h>

int main() {
    int a;


    do{
        printf("\nDigite um número que corresponde a um dos dias da semana: ");
        scanf("%d", &a);

        if (a >= 1 && a <= 7) {
            switch (a) {
            case 1:
                printf("\n Domingo\n");
                break;
            case 2:
                printf("\n Segunda\n");
                break;
            case 3:
                printf("\n Terça\n");
                break;
            case 4:
                printf("\n Quarta\n");
                break;
            case 5:
                printf("\n Quinta\n");
                break;
            case 6:
                printf("\n Sexta\n");
                break;
            case 7:
                printf("\n Sábado\n");
                break;
            }
        }

        else if(a!=0) {
            printf("\n Número de dia não válido\n ");
        }
        else
            printf("\n Saindo do programa\n ");
    } while (a!=0);

    return 0;
}
