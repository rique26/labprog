#include<stdio.h>

int main()
{

    float alt;
    char sexo;
    float peso_ideal;
    
    printf("Digite sua altura em metros: ");
    scanf("%f", &alt);
    printf("Digite seu sexo (M/F): ");
    scanf("%s", &sexo);
    
    if (sexo == 'm' || sexo == 'M'){
    	peso_ideal = 72.7*alt-58;
    }
    else if (sexo == 'f' || sexo == 'F'){
    	peso_ideal = 62.1*alt-44.7;
    }
    
    printf("Peso ideal: %.2fkg", peso_ideal);
    
    return 0;
}
