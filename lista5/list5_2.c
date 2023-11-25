#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void menorElemento(int *vet, int tam,int *menor);


int main(){
    srand(time(NULL));
    int *vet, tam, menor;

    printf("Digite o tamanho do vetor: ");
    scanf("%d",&tam);
    
    vet = malloc(sizeof(int)*tam);

    //preencher vetor aleátorio
    for(int i=0; i<tam; i++)
        *(vet+i) = rand()%100;

    //imprimir vetor
    for(int i=0; i<tam; i++)
        printf("%d ", *(vet+i));


    menorElemento(vet, tam, &menor);

    return 0;
}


void menorElemento(int *vet, int tam,int *menor){

    *menor = *(vet+0);
    for(int i=1; i<tam; i++)
        if(*(vet+i) < *menor)
            *menor = *(vet+i);
    printf("\nMenor elemento: %d", *menor);
    
}
    

