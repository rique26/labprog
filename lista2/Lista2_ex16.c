#include<stdio.h>

int main()
{
    int div3=0, div5=0, i;
    
    for (i=0;i<=200;i++){
        if(i%3==0 && i<=100)
            div3 += i;
        else if(i%5==0 && i>=100)
            div5 += i;
    }
    printf("Soma dos divisíveis por 3 entre 0 e 100: %d \nSoma dos divisíveis por 5 entre 100 e 200: %d", div3, div5);
    
    return 0;
}
