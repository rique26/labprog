#include <stdio.h>
#include <stdlib.h>

#define TAM 15

int main()
{
    float menor=0, maior=0;
    float vet[TAM];
    
    for(int i=1; i<=15; i++){
        printf("Elementos: ");
        scanf("%f", &vet[i]);
    }

    for(int i=1; i<=15; i++){
        if(vet[i]>maior)
            maior = vet[i];
        else if(vet[i]<menor);
            menor = vet[i];
    }

    printf("maior: %1.f e menor: %1.f", maior, menor);
        





    





  return(0);
}
