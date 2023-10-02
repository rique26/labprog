#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 100

int main(){
    int vet[TAM], *pvet = vet;
    srand(time(NULL));
    
    for(int i=0; i<TAM; i++)
        *(vet+i)= rand()%100;

    for(int i=0; i<TAM; i++) 
        printf(" [%p] - %2d \n", vet+i, *(vet+i));
        

return 0;
}



//colchete é alocacao estatica
//=# alocacao dinamica
//malloc
