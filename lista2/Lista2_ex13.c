#include<stdio.h>

int main()
{    
    int a, b, somatorio = 0, i ;
    
    printf("Valor de A: ");
    scanf("%d", &a);
    printf("Valor de B: ");
    scanf("%d", &b);
    
    if(a>b){
        i = a;
        a = b;
        b = i;
    }for (a; a<=b; a++){
        somatorio += a;
    }
    printf("Soma: %d", somatorio);
    
    return 0;
}
