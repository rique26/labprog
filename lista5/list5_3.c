#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void menorMaiorElemento(int *, int ,int *,int *);
void menorMaiorVetor(int *, int *,int *);


int main(){
    srand(time(NULL));
    int *vet, tam, menor, maior;
    int *vetMenorMaior;

    printf("Digite o tamanho do vetor: ");
    scanf("%d",&tam);
    
    vet = malloc(sizeof(int)*tam);
    vetMenorMaior = malloc(sizeof(int)*2);

    //preencher vetor aleátorio
    for(int i=0; i<tam; i++)
        *(vet+i) = rand()%100;

    //imprimir vetor
    for(int i=0; i<tam; i++)
        printf("%d ", *(vet+i));


    menorMaiorElemento(vet, tam, &menor, &maior);

    menorMaiorVetor(vetMenorMaior, &menor, &maior);

    printf("\nMaior e menor valor no novo vetor: %d e %d", *(vetMenorMaior), *(vetMenorMaior+1));

    return 0;
}


void menorMaiorElemento(int *vet, int tam,int *menor,int *maior){

    *menor = *vet;
    *maior = *vet;

    for(int i=1; i<tam; i++)
        if(*(vet+i) < *menor)
            *menor = *(vet+i);
        else if(*(vet+i) > *maior)
            *maior = *(vet+i);
  
}
    
void menorMaiorVetor(int *vetMenorMaior, int *menor,int *maior){

    *vetMenorMaior = *maior;
    *(vetMenorMaior+1) = *menor;

}

