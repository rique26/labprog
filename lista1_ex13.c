#include<stdio.h>

int main()
{   
	int n1, n2, x;
    
    printf("Valor de n1: ");
    scanf("%d", &n1);
    printf("Valor de n2: ");
    scanf("%d", &n2);
    
    x = n1;
    n1 = n2;
    n2 = x;
    
    printf("\nn1 = %d e n2 = %d", n1, n2);
    
    return 0;
}
