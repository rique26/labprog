#include <stdio.h>
#include <stdlib.h>

void minMax(int *, int *, int *);
void xLinha(int *x, int *xL);


int min, max;

int main(){

    int *x, tam=4;
    int *xL;
    

    x = malloc(sizeof(int)*tam);
    xL = malloc(sizeof(int)*tam);

    for(int i=0;i<tam;i++)
        *(x+i) = i+1;
    
    //obtém o valor menor e o maior do vetor e armazena-os em min e max
    minMax(x, &min, &max);
    xLinha(x, xL);
    

    for(int i=0;i<tam;i++)
        printf("%d ", *(xL+i));




    return 0;
}

void minMax(int *x, int *min, int *max){
    int tam = sizeof(x);
    *min = *x;
    *max = *x;

    for(int i=1;i<tam;i++){
        if(*(x+i) < *min)
            *min = *(x+i);
        else if(*(x+i) > *max)
            *max = *(x+i);
    }
}

void xLinha(int *x, int *xL){
    int tam = sizeof(xL);

    for(int i=0;i<tam;i++)
        *(xL+i) = *(x+i) - min;
    for(int i=0;i<tam;i++)
        *(xL+i) /= max-min;

}
