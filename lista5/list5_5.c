#include<stdio.h>
#include <stdlib.h>
#include <time.h>

//Escreva um programa que some todos os elementos de um vetor de float alocado dinamicamente.
//A quantidade de elementos devem ser fornecidas por linha de comando. Utilize a fun¸c˜ao rand()
//para alimentar o vetor com valores pseudo-aleat´orios.

void somaVetor(float *, float *, int);


int main()
{
    float *vet, result=0;
    int tam;
    srand(time(NULL));
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);
    
    vet = malloc(sizeof(float)*tam);
    
    //preencher vetor
    for(int i=0;i<tam;i++)
        *(vet+i) = rand()%10;
        
    for(int i=0; i<tam; i++)
        printf("%0.f ", *(vet+i));
    
    somaVetor(vet, &result, tam);
    
    printf("\n\n");
    printf("%1.f ", result);
         
    return 0;
}

void somaVetor(float *vet, float *result, int tam){
    
    
    for(int i=0; i<=tam; i++)
        *result += *(vet+i);
    

}

//nó e processos, p e h
