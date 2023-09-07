#include<stdio.h>

int main()
{
    int jose = 150, pedro = 110, cont = 0;
    
    while (pedro <= jose){
        jose += 2;
        pedro += 3;
        cont += 1;
    }
    printf("Em %d anos ", cont);
    return 0;
}
