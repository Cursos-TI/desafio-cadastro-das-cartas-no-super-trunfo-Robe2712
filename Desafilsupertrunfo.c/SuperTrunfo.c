#include<stdio.h>

int main(){
    printf("Carta Super Trunfo \n");
    
    char Estado1 ;
    char Codigo_da_Carta1 [5] ;
    char Nome_Da_Cidade1 [50] ;
    unsigned long int Populacao1 ;
    float Area1 ;
    float PIB1 ;
    int Pontos_Turisticos1 ;
    float Densidade_Populacional1;
    float PIB_per_Capita1;
    float superPoder1;


    char ESTADO2 ;
    char Codigo_da_carta2 [5] ;
    char Nome_Da_cidade2 [50] ;
    unsigned long int populacao2 ;
    float area2 ;
    float pib2 ;
    int Pontos_turisticos2 ;
    float DensidadePopulacional2;
    float PIBperCapita2;
    float superPoder2;



       // Cadastro da primeira carta
         printf("dados da primeira carta\n");

    printf("digite o estado: ");
    scanf( "%c", &Estado1 );
   
    printf("digite o codigo da carta: ");
    scanf( "%s", &Codigo_da_Carta1 );
    
    printf("nome da cidade: ");
    scanf( "%s", &Nome_Da_Cidade1 );
   
    printf("numero de populacao: ");
    scanf( "%lu", &Populacao1 );
   
    printf("Tamanho da Area: ");
    scanf ( "%f", &Area1);
    
    printf("O PIB ");
    scanf( "%f", &PIB1 );
   
    printf("Quantos pontos turisticos ");
    scanf( "%d", &Pontos_Turisticos1 );

     Densidade_Populacional1 =  Populacao1 / Area1;
     PIB_per_Capita1 = PIB1 / Populacao1;
     superPoder1 = Populacao1 + Area1 + PIB1 + Pontos_Turisticos1 + (1.0 / Densidade_Populacional1);

        // Cadastro da segunda carta
        printf("dados da segunda carta\n");

    printf("Digite o Estado: " );
    scanf( " %c", &ESTADO2 );
    
    printf(" digite o codigo da carta: ");
    scanf(" %s", &Codigo_da_carta2 );
   
    printf("nome da cidade: ");
    scanf(" %s", &Nome_Da_cidade2 );
    
    printf("numero de populacao: ");
    scanf( "%lu", &populacao2 );
    
    printf("Tamanho da Area: ");
    scanf ( "%f", &area2);
   
    printf("O PIB ");
    scanf( "%f", &pib2 );
    
    printf("Quantos pontos turisticos ");
    scanf(" %d", &Pontos_turisticos2 );

        // Cálculo da densidade populacional e PIB per capita 

     DensidadePopulacional2 =  populacao2 / area2;
     PIBperCapita2 = pib2 / populacao2;
     superPoder2 = populacao2 + area2 + pib2 + Pontos_turisticos2 + (1.0 / DensidadePopulacional2);

           // Dados da primeira carta
            printf("Resultados da primeira carta\n");

    printf("Estado: %c\n", Estado1);
    printf("Código da Carta: %s\n", Codigo_da_Carta1);
    printf("Nome da Cidade: %s\n", Nome_Da_Cidade1);
    printf ("População: %.d\n", Populacao1);
    printf ("Área: %.2f km²\n", Area1);
    printf ("PIB: %.2f bilhões\n", PIB1);
    printf ("Pontos turisticos: %d\n", Pontos_Turisticos1);
    printf ("Densidade Populacional: %.2f hab/km²\n", Densidade_Populacional1);
    printf (" PIB per Capita: %.6f reais\n", PIB_per_Capita1 );

            // Dados da segunda carta
            printf("Resultados da segunda carta\n");

    printf("estado: %c\n", ESTADO2 );
    printf("Codigo da carta: %s\n", Codigo_da_carta2);
    printf("nome da cidade: %s\n", Nome_Da_cidade2);
    printf ("População: %d\n", populacao2);
    printf ("Área: %.2f km²\n", area2);
    printf ("PIB: %.2f bilhões\n", pib2);
    printf ("Pontos turisticos: %d\n", Pontos_turisticos2);
    printf ("Densidade Populacional: %.2f hab/km²\n", DensidadePopulacional2);
    printf (" PIB per Capita: %.6f reais\n", PIBperCapita2 );

    
        // Comparação entre as cartas
        printf(" Comparação entre cartas\n");
    
        printf("População: Carta 1 venceu (%d)\n", Populacao1 > populacao2);
        printf("Área: Carta 1 venceu (%d)\n", Area1 > area2);
        printf("PIB: Carta 1 venceu (%d)\n", PIB1 > pib2);
        printf("Pontos Turísticos: Carta 1 venceu (%d)\n", Pontos_Turisticos1 > Pontos_turisticos2);
        printf("Densidade Populacional: Carta 1 venceu (%d)\n", Densidade_Populacional1 < DensidadePopulacional2);
        printf("PIB per Capita: Carta 1 venceu (%d)\n", PIB_per_Capita1 > PIBperCapita2);
        printf("Super Poder: Carta 1 venceu (%d)\n", superPoder1 > superPoder2);
    
        return 0;
}
    
    
   