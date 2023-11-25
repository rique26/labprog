#include<stdio.h>

int main()
{   
	float diaria = 50.25, imposto = 0.9;
    int dias_trab;
    float total_liq, total_brut, total_sem_imposto;
    
    printf("Total de dias trabalhados: ");
    scanf("%d", &dias_trab);
    total_sem_imposto = dias_trab*diaria;
    
    if (dias_trab <= 10){
    	total_brut = total_sem_imposto;
    }else if (dias_trab <=20){
    	total_brut = total_sem_imposto*1.2;
    }else{
    	total_brut = total_sem_imposto*1.3;
    }
    
    printf("Total líquido: R$%.2f", total_brut*imposto);
    
    return 0;
}
