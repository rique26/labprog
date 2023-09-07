#include<stdio.h>

int main()
{
    int x, i;
    
    printf("Tabuada a ser gerada: ");
    scanf("%d", &x);
    
    for (i = 0; i <=10; i++){
        printf("%d X %d = %d\n", x, i, x*i);
    }
    
    return 0;
}
