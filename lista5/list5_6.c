#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int media(int *vet);
int mediana(int *vet);
int moda(int *vet);
int tam=7;

int main(){
    int *vet;
    vet = malloc(sizeof(int)*tam);
    srand(time(NULL));

    
    for(int i=0; i<tam; i++) *(vet+i) = rand()%10;
    for(int i=0; i<tam; i++) printf("%d ", *(vet+i));

    printf("\n\n");
    printf("Media: %d ", media(vet));

    printf("\n\n");
    printf("Mediana: %d ", mediana(vet));

    printf("\n\n");
    for(int i=0; i<tam; i++) printf("%d ", *(vet+i));

    return 0;
}


int media(int *vet){
    int result = 0;
    for(int i=0; i<tam; i++) result += *(vet+i);
    return result/tam;
}

int mediana(int *vet){
    int result2 = 0;
    
    //ordenacao
    int flag=1, aux;
    while(flag){
        flag=0;
        for(int k=0;k<tam-1;k++){
            if(*(vet+k) > *(vet+k+1)){
                aux = *(vet+k);
                *(vet+k) = *(vet+k+1); 
                *(vet+k+1) = aux;
                flag=1;
            }
        }
    }

    if(tam %2 == 0)
        result2 = (*(vet+(tam/2)) + *(vet+(tam/2)-1)) /2;
    else    
        result2 = *(vet+(tam/2));

    return result2;

}

int moda(int *vet){
    int *vetcont;
    vetcont = calloc(tam, sizeof(int));

    for(int k=0;k<tam;k++)
        for(int i=0;i<tam;i++)
            if(*(vet+k)==*(vet+i))
                *(vetcont+k) +=1;

    for(int k=0;k<tam;k++)
        for(int i=0;i<tam;i++)
            if(*(vet+k)==*(vet+i))
                *(vetcont+k) +=1;

    
}
