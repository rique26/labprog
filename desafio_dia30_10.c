//Estoque loja, structs, passar pra funcao e ela devolve o produto mais caro.

#include <stdio.h>

typedef struct{
    char cereais[20], carnes[20], laticinios[20];
    
    
}Estoque;



Estoque lerDados(){
    
    Estoque dados;

    printf("\nCereal: ");
    fgets(dados.cereais, 20, stdin);
    printf("Carne: ");
    fgets(dados.carnes, 20, stdin);
    printf("Laticínio: ");
    fgets(dados.laticinios, 20, stdin);

    return dados;

}


int main(){
    
    Estoque estoqueComercio[3];

    for(int i=0; i<3; i++)
        estoqueComercio[i] = lerDados();
    
        
    

return 0;
}




