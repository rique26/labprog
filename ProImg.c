#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void filtro(int **matOrig, int l, int c){

    int soma=0;
    int result[3][3] = {0};
    int matFil[5][5]= {0};

    /*
    //alocacao matrizFil com zeros
    matFil = calloc(l+2, sizeof(int*));
    for(int i=0; i<l+2; i++)
        matFil[i] = calloc(c+2, sizeof(int));
    */
    
    //soma matFil + MatOrig
    for(int i=1;i<=3; i++)
        for(int k=1; k<=3; k++)
            *(*(matFil+i)+k) += *(*(matOrig+i-1)+k-1); 

    /*
    //alocacao matriz result media
    result = calloc(l, sizeof(int*));
    for(int i=0; i<l; i++)
        result[i] = calloc(c, sizeof(int));
    */

   
    printf("matfil somada: \n");
    for(int i=0;i<l+2;i++){
        for(int k=0;k<c+2;k++)
            printf("%2d ", *(*(matFil+i)+k));
        printf("\n");
    }
    
   
    //filtro
    for(int i=1; i<=l; i++){
        for(int k=1; k<=c; k++){
            soma = 0;
            for(int x=-1; x<=1; x++){
                for(int y=-1; y<=1; y++)
                    soma += matFil[i+x][k+y]; //soma += *(*(matFil+i+x)+k+y);
                
            } 
            //printf("%d ", soma);       
            result[i-1][k-1] = soma/9; //*(*(result+i)+k) = soma/9;
        }
    }
      
    //printf("111111");

    printf("result : \n");
    for(int i=0;i<l;i++){
        for(int k=0;k<c;k++)
            printf("%2d ", result[i][k]);
            //printf("%2d ", *(*(result+i)+k));
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
    for(int i=0;i<l;i++){
        for(int k=0;k<c;k++)
            printf("%2d ", *(*(matOrig+i)+k));
        printf("\n");
    }
    printf("\n\n");
    

    //////////////////////////////////////////

    filtro(matOrig, l, c);

 
    
}       


