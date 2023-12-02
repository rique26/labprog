#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void filtro(int **, int , int, int );
void printMatriz(int **, int , int );

int main(){

    int **matOrig, l=15, c=15;
    int tamJanela = 3;
    srand(time(NULL));

    matOrig = malloc(l*sizeof(int*));
    for(int i=0; i<l;i++) 
        *(matOrig+i) = malloc(c*sizeof(int));
    
    for(int i=0;i<l;i++)
        for(int k=0;k<c;k++)
            *(*(matOrig + i)+k) = rand()%256;

    printf("Matriz Original: \n\n");
    printMatriz(matOrig, l ,c);

    filtro(matOrig, l, c, tamJanela);

}       

void filtro(int **matOrig, int l, int c, int tamJanela){

    int **result, **matCopia, soma=0, zerosAdic, acresc;
    
    switch (tamJanela)
    {
    case 3:
        zerosAdic = 2;
        acresc = 0;
        break;
    case 5:
        zerosAdic = 4;
        acresc = 1;
        break;
    case 7: 
        zerosAdic = 6;
        acresc = 2;
        break;
    case 9:
        zerosAdic = 8;
        acresc = 3;
        break;
    }

    //alocacao das matrizes
    matCopia = calloc(l+zerosAdic, sizeof(int*));     //5x5 para janela 3x3, 7x7 para janela 5x5 
    for(int i=0; i<l+zerosAdic; i++) matCopia[i] = calloc(c+zerosAdic, sizeof(int));

    result = calloc(l, sizeof(int*));
    for(int i=0; i<l; i++) result[i] = calloc(c, sizeof(int));
    
    //soma matCopia + MatOrig
    for(int i=1;i<=l; i++)
        for(int k=1; k<=c; k++)
            *(*(matCopia+i+acresc)+k+acresc) += *(*(matOrig+i-1)+k-1); 

    printf("Copia da matriz extendida: \n\n");
    for(int i=0;i<l+zerosAdic;i++){
        for(int k=0;k<c+zerosAdic;k++)
            printf("%3d  ", *(*(matCopia+i)+k));
        printf("\n\n");
    }
    
    //filtro
    for(int i=1; i<=l; i++){
        for(int k=1; k<=c; k++){
            soma = 0;
            for(int x=-1; x<=tamJanela-2; x++){
                for(int y=-1; y<=tamJanela-2; y++)
                    soma += *(*(matCopia+i+x)+k+y);
            }*(*(result+i-1)+k-1) = soma/(tamJanela*tamJanela);
        }
    }
      
    printf("\n\nMatriz com filtro: \n\n");
    for(int i=0;i<l;i++){
        for(int k=0;k<c;k++)
            printf("%5d  ", *(*(result+i)+k));
        printf("\n\n");
    } 
}

void printMatriz(int **vet, int l, int c){

    for(int i=0;i<l;i++){
        for(int k=0;k<c;k++)
            printf("%3d  ", *(*(vet+i)+k));
        printf("\n\n");
    }printf("\n\n");
}
