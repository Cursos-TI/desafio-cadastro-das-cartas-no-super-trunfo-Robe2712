#include<stdio.h>

int main(){
    printf("Carta Super Trunfo \n");
    
    char Estado ;
    char Codigo_da_Carta [5] ;
    char Nome_Da_Cidade [50] ;
    int Populacao ;
    float Area ;
    float PIB ;
    int Pontos_Turisticos ;


    char ESTADO ;
    char Codigo_da_carta [5] ;
    char Nome_Da_cidade [50] ;
    int populacao ;
    float area ;
    float pib ;
    int Pontos_turisticos ;


       // Cadastro da primeira carta
    printf("digite o estado: ");
    scanf( "%c", &Estado );
   
    printf("digite o codigo da carta: ");
    scanf( "%s", &Codigo_da_Carta );
    
    printf("nome da cidade: ");
    scanf( "%s", &Nome_Da_Cidade );
   
    printf("numero de populacao: ");
    scanf( "%d", &Populacao );
   
    printf("Tamanho da Area: ");
    scanf ( "%f", &Area);
    
    printf("O PIB ");
    scanf( "%f", &PIB );
   
    printf("Quantos pontos turisticos ");
    scanf( "%d", &Pontos_Turisticos );
    

        // Cadastro da segunda carta
    printf("Digite o Estado: " );
    scanf( " %c", &ESTADO );
    
    printf("digite o codigo da carta: ");
    scanf( "%s", &Codigo_da_carta );
   
    printf("nome da cidade: ");
    scanf( "%s", &Nome_Da_cidade );
    
    printf("numero de populacao: ");
    scanf( "%d", &populacao );
    
    printf("Tamanho da Area: ");
    scanf ( "%f", &area);
   
    printf("O PIB ");
    scanf( "%f", &pib );
    
    printf("Quantos pontos turisticos ");
    scanf(" %d", &Pontos_turisticos );
    

           // Dados da primeira carta
    printf("Estado: %c\n", Estado);
    printf("Código da Carta: %s\n", Codigo_da_Carta);
    printf("Nome da Cidade: %s\n", Nome_Da_Cidade);
    printf ("População: %.d\n", Populacao);
    printf ("Área: %.2f km²\n", Area);
    printf ("PIB: %.2f bilhões\n", PIB);
    printf ("Pontos turisticos: %d\n", Pontos_Turisticos);

            // Dados da segunda carta
    printf("estado: %c\n", ESTADO );
    printf("Codigo da carta: %s\n", Codigo_da_carta);
    printf("nome da cidade: %s\n", Nome_Da_cidade);
    printf ("População: %d\n", populacao);
    printf ("Área: %.2f km²\n", area);
    printf ("PIB: %.2f bilhões\n", pib);
    printf ("Pontos turisticos: %d\n", Pontos_turisticos);

    return 0; 
}
