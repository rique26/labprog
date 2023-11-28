#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//janela 5x5

void filtro(int **matOrig, int l, int c){

    int soma=0;
    int **result;;
    int **matFil;

    
    //alocacao matrizFil com zeros
    matFil = calloc(l+4, sizeof(int*));     //5x5 para janela 3x3, 7x7 para janela 5x5 
    for(int i=0; i<l+4; i++)
        matFil[i] = calloc(c+4, sizeof(int));
    
    
    //soma matFil + MatOrig
    for(int i=1+1;i<=3+1; i++)
        for(int k=1+1; k<=3+1; k++)
            *(*(matFil+i)+k) += *(*(matOrig+i-1-1)+k-1-1); 

    
    //alocacao matriz result media
    result = calloc(l, sizeof(int*));
    for(int i=0; i<l; i++)
        result[i] = calloc(c, sizeof(int));
    

   
    printf("Copia da matriz extendida: \n\n");
    for(int i=0;i<l+4;i++){
        for(int k=0;k<c+4;k++)
            printf("%2d ", *(*(matFil+i)+k));
        printf("\n");
    }
    
   
    //filtro
    for(int i=1; i<=l; i++){
        for(int k=1; k<=c; k++){
            soma = 0;
            for(int x=-1; x<=3; x++){
                for(int y=-1; y<=3; y++)
                    soma += *(*(matFil+i+x)+k+y);
                    //soma += matFil[i+x][k+y];
                
            } 
            //result[i-1][k-1] = soma;       
            *(*(result+i-1)+k-1) = soma;
        }
    }
      
    

    printf("\n\nMatriz com filtro: \n\n");
    for(int i=0;i<l;i++){
        for(int k=0;k<c;k++)
            //printf("%2d ", result[i][k]);
            printf("%2d ", *(*(result+i)+k));
        printf("\n");
    }
    
    
}



int main(){

    int **matOrig;
    int l=3, c=3;
    srand(time(NULL));

    //alocacao dinamica
    matOrig = malloc(l*sizeof(int*));
    for(int i=0; i<c;i++) 
        matOrig[i] = malloc(c*sizeof(int));
    
    //gerar aleatorios
    for(int i=0;i<l;i++)
        for(int k=0;k<c;k++)
            *(*(matOrig + i)+k) = rand()%10;

    //print matriz aleatoria
    printf("Matriz Original: \n\n");
    for(int i=0;i<l;i++){
        for(int k=0;k<c;k++)
            printf("%2d ", *(*(matOrig+i)+k));
        printf("\n");
    }
    printf("\n\n");
    

    //////////////////////////////////////////

    filtro(matOrig, l, c);

 
    
}       


