#include<stdio.h>

int main(){
    printf("Carta Super Trunfo \n");
    
    char Estado = 'A';
    char Codigo_da_Carta [5] = "A01";
    char Nome_Da_Cidade [50] = "Manaus";
    int Populacao = 2279686;
    float Area = 11.401 ;
    float PIB = 103281000000.0 ;
    int Pontos_Turisticos = 15;

    printf ("Estado: %c\n", Estado);
    printf ("Codigo da carta: %s\n", Codigo_da_Carta);
    printf ("nome da cidade: %s\n", Nome_Da_Cidade);
    printf ("População: %d\n", Populacao);
    printf ("Área: %.3f\n", Area);
    printf ("PIB: %.2f bilhões\n", PIB);
    printf ("Pontos turisticos: %d\n", Pontos_Turisticos);
    return 0; 
}
