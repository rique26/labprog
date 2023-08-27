#include<stdio.h>

int main()
{   
	float c, f;
    
    printf("Temperatura em Celcius: ");
    scanf("%f", &c);
    
    f = (9*c+160)/5;
    
    printf("\nTemperatura convertida para Fahrenheit: %.1f", f);
    
    
    return 0;
}
