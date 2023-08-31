#include <stdio.h>

int main()
{
	float hora_aula, desc_inss, sal_bruto, sal_liq;
    int horas_trab; 
    
    printf("Valor da hora-aula: R$");
    scanf("%f", &hora_aula);
    printf("Horas trabalhadas no mês: ");
    scanf("%d", &horas_trab);
    printf("Percentual de desconto do INSS: %");
    scanf("%f", &desc_inss);
    
    desc_inss = 1-(desc_inss/100);
    
    sal_bruto = hora_aula*horas_trab;
    sal_liq = sal_bruto*desc_inss;
    
    printf("\nSalário bruto: R$%.2f", sal_bruto);
    printf("\nSalário líquido: R$%.2f", sal_liq);
    
    return 0;
}
    
