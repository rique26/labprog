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
    printf("\n\n----------------------");
    puts("\n 1. Ocupar armário.");
    puts(" 2. Liberar armário.");
    puts(" 3. Sair.");
    printf("Opção: ");
    scanf("%d", &opcao);
    printf("----------------------\n");
    
    mask = 1;
    srand(time(NULL));
    
    if (opcao == 1){
        do{
        //Armário aleatório.
        mask = 1;
        armario = (rand() % (8)+1);
        
        //Testar se o armário está em uso.
        mask = mask<<(armario-1);
        teste_valor_duplicado = armarios & mask;
        
        }while(teste_valor_duplicado);
        
        armarios = armarios|mask;
        printf("\nO armário %d foi reservado para você.", armario);
        
    }else if(opcao == 2){
        printf("\nQual armário você quer liberar? ");
        scanf("%d", &armario);
        
        mask = mask<<(armario-1);
        mask = ~mask;
        armarios = armarios & mask;
    }
    }while(opcao!=3);

    //Mostrar armários em uso.
    puts("\nArmários ocupados:");
    for (i=1; i<=8; i++){
        mask = 1;
        t = (mask<<i-1) & armarios;
        if(t)
            printf("• %d\n", i);
    }
    
    //Mostrar armários desocupados.
    puts("\nArmários desocupados:");
    for (i=1; i<=8; i++){
        mask = 1;
        t = (mask<<i-1) & armarios;
        if(t==0)
            printf("• %d\n", i);
    }

    return 0;
}
