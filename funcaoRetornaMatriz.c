#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tam=5, l=5, c=5;


void imprimir(int m[l][c]){
    int i,j;
    for(i=0; i<tam; i++){
        for(j=0; j<tam; j++)
            printf("%2d ", m[i][j]);
        printf("\n");
    }

}

int somarLinha(int x[l][c], int l){
    int c, soma =0;

    for(c=0; c<tam; c++)
        soma += x[l][c];
    return soma;

}

int main() {
    int mat[l][c];
    int i , j;
    srand(time(NULL));

    for(i=0; i<tam; i++){
        for(j=0; j<tam; j++){
            mat[i][j] = rand() % 10;
        }
    }

    imprimir(mat);
    printf("Soma da lina 0: %d\n", somarLinha(mat, 0));
    printf("Soma da lina 1: %d\n", somarLinha(mat, 1));
    printf("Soma da lina 2: %d\n", somarLinha(mat, 2));

    return 0;
}
