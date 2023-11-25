#include <stdio.h>
#include <stdlib.h>


#define TAM 15

int main()
{
    float vet[TAM], soma;
    int flag, aux;
    
    //receber valores
    for(int i=0; i<=TAM-1; i++){
        printf("Elementos: ");
        scanf("%f", &vet[i]);
    }

    //ordenação tipo bolha da lista
    flag=1;
    while(flag){
        flag=0;
        for(int i=0; i<=TAM-2; i++){
            if(vet[i]>vet[i+1]){
                aux=vet[i];
                vet[i]=vet[i+1];
                vet[i+1]=aux;
                flag=1;
            }
        }
    }

    printf("Soma do menor valor com o maior: %.1f", vet[0] + vet[TAM-1]);
    
    
  return(0);
}
