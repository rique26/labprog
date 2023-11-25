#include<stdio.h>

int main()
{
    int paulo = 0, renata = 0, voto;
    int branco=0, nulo=0;
    float total;
    
    printf("-----URNA ELETRÔNICA-----\n\n");
    printf("\n0 - branco\noutro valor - nulo\nvalor negativo- sair");
    printf("\n\nCandidatos: \nPaulo-5\nRenata-7");
    
    do {
        
        printf("\n\n\nVoto: ");
        scanf("%d", &voto);
    
        if (voto == 5)
            paulo += 1;
        else if(voto == 7)
            renata += 1;
        else if(voto == 0)
            branco +=1;
        else if(voto >= 0)
            nulo += 1;
           
    }while (voto >= 0);
    
    
    total = paulo+renata+branco+nulo;
    
    
    printf("\n\nRelatório: ");
    printf("\n\tTotal de votos: %.0f", total);
    printf("\n\tVotos em Paulo - %d - %.2f%%", paulo, (paulo/total)*100);
    printf("\n\tVotos em Renata - %d - %.2f%%", renata, (renata/total)*100);
    printf("\n\tVotos em branco - %d - %.2f%%", branco, (branco/total)*100);
    printf("\n\tVotos em nulo - %d - %.2f%%", nulo, (nulo/total)*100);
    
    
    return 0;
}
