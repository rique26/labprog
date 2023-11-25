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
        if(a%3==0)
            printf("\n%d", a);
    }
    
    return 0;
}
