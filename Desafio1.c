#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    unsigned char armarios = 0;
    unsigned char mask=1;
    unsigned char teste_valor_duplicado;
    unsigned char t;
    
    int opcao, armario, i;
    
    do{
    
    
    puts("\n\n1. Ocupar armário.");
    puts("2. Liberar armário.");
    puts("3. Sair.");
    scanf("%d", &opcao);
    mask = 1;
    srand(time(NULL));
    
    if (opcao == 1){
    
        do{
        
        mask = 1;
        armario = (rand() % (8)+1);
        
        mask = mask<<(armario-1);
        teste_valor_duplicado = armarios & mask;
        
        }while(teste_valor_duplicado);
        
        
        armarios = armarios|mask;
        
       
        
        printf("O armário %d foi reservado para você.", armario);
        
       
    }
    else if(opcao == 2){
        puts("Qual armário você quer liberar?");
        scanf("%d", &armario);
        
        
        mask = mask<<(armario-1);
        mask = ~mask;
        armarios = armarios & mask;
        
    }
    
    
    
    
    
    }while(opcao!=3);


    
    printf("\n%hhu", armarios);
    for (i=1; i<=8; i++){
        mask = 1;
        t = (mask<<i-1) & armarios;
        if(t)
            printf("\nArmário %d está em uso.", i);
            
    }



     
    
    return 0;
}
