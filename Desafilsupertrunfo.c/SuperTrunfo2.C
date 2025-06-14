#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    printf("Carta Super Trunfo - Desafio Final!\n");

    // Declaração das variáveis para a primeira carta
    char Estado1;
    char Codigo_da_Carta1[5];
    char Nome_Da_Cidade1[50];
    unsigned long int Populacao1;
    float Area1, PIB1, Densidade_Populacional1, PIB_per_Capita1;
    int Pontos_Turisticos1;

    // Declaração das variáveis para a segunda carta
    char ESTADO2;
    char Codigo_da_carta2[5];
    char Nome_Da_cidade2[50];
    unsigned long int populacao2;
    float area2, pib2, DensidadePopulacional2, PIBperCapita2;
    int Pontos_turisticos2;

    // Cadastro da primeira carta
    printf("\nCadastro da primeira carta\n");
    printf("Digite o estado: ");
    scanf(" %c", &Estado1);
    printf("Digite o código da carta: ");
    scanf("%s", Codigo_da_Carta1);
    printf("Digite o nome da cidade: ");
    scanf("%s", Nome_Da_Cidade1);
    printf("Digite a população: ");
    scanf("%lu", &Populacao1);
    printf("Digite a área em km²: ");
    scanf("%f", &Area1);
    printf("Digite o PIB em bilhões: ");
    scanf("%f", &PIB1);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &Pontos_Turisticos1);

    // Cálculo dos atributos adicionais da primeira carta
    Densidade_Populacional1 = Populacao1 / Area1;
    PIB_per_Capita1 = PIB1 / Populacao1;

    // Cadastro da segunda carta
    printf("\nCadastro da segunda carta\n");
    printf("Digite o estado: ");
    scanf(" %c", &ESTADO2);
    printf("Digite o código da carta: ");
    scanf("%s", Codigo_da_carta2);
    printf("Digite o nome da cidade: ");
    scanf("%s", Nome_Da_cidade2);
    printf("Digite a população: ");
    scanf("%lu", &populacao2);
    printf("Digite a área em km²: ");
    scanf("%f", &area2);
    printf("Digite o PIB em bilhões: ");
    scanf("%f", &pib2);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &Pontos_turisticos2);

    // Cálculo dos atributos adicionais da segunda carta
    DensidadePopulacional2 = populacao2 / area2;
    PIBperCapita2 = pib2 / populacao2;

    // Escolha dinâmica dos atributos
    int escolha1, escolha2;
    printf("\nEscolha o primeiro atributo para comparação:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Densidade Populacional\n5 - PIB per Capita\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha1);

    do {
        printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
        printf("1 - População\n2 - Área\n3 - PIB\n4 - Densidade Populacional\n5 - PIB per Capita\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha2);
    } while (escolha2 == escolha1); // Garante que os atributos escolhidos sejam diferentes

    printf("\n--- Comparação de cartas ---\n");

    // Variáveis para armazenar os valores dos atributos
    float valorCarta1, valorCarta2, somaCarta1 = 0, somaCarta2 = 0;

    // Loop para comparar os dois atributos escolhidos
    for (int i = 0; i < 2; i++) {
        int atributo = (i == 0) ? escolha1 : escolha2; // Define o atributo atual

        switch (atributo) {
            case 1:
                printf("\nAtributo: População\n");
                valorCarta1 = Populacao1;
                valorCarta2 = populacao2;
                break;
            case 2:
                printf("\nAtributo: Área\n");
                valorCarta1 = Area1;
                valorCarta2 = area2;
                break;
            case 3:
                printf("\nAtributo: PIB\n");
                valorCarta1 = PIB1;
                valorCarta2 = pib2;
                break;
            case 4:
                printf("\nAtributo: Densidade Populacional (Menor vence!)\n");
                valorCarta1 = Densidade_Populacional1;
                valorCarta2 = DensidadePopulacional2;
                break;
            case 5:
                printf("\nAtributo: PIB per Capita\n");
                valorCarta1 = PIB_per_Capita1;
                valorCarta2 = PIBperCapita2;
                break;
            default:
                printf("Erro na escolha de atributos!\n");
                return 1;
        }

        printf("Carta 1 - %s (%c): %.2f\n", Nome_Da_Cidade1, Estado1, valorCarta1);
        printf("Carta 2 - %s (%c): %.2f\n", Nome_Da_cidade2, ESTADO2, valorCarta2);
        
        // Comparação usando operador ternário e soma dos pontos
        if (atributo == 4) { // Regra especial para densidade populacional (menor vence)
            printf("Resultado: %s venceu!\n", (valorCarta1 < valorCarta2) ? Nome_Da_Cidade1 : Nome_Da_cidade2);
            somaCarta1 += (valorCarta1 < valorCarta2) ? 1 : 0;
            somaCarta2 += (valorCarta2 < valorCarta1) ? 1 : 0;
        } else {
            printf("Resultado: %s venceu!\n", (valorCarta1 > valorCarta2) ? Nome_Da_Cidade1 : Nome_Da_cidade2);
            somaCarta1 += (valorCarta1 > valorCarta2) ? 1 : 0;
            somaCarta2 += (valorCarta2 > valorCarta1) ? 1 : 0;
        }
    }

    printf("\n--- Resultado Final ---\n");
    printf("Soma dos atributos - Carta 1: %.2f\n", somaCarta1);
    printf("Soma dos atributos - Carta 2: %.2f\n", somaCarta2);

    // Determina o vencedor final
    if (somaCarta1 > somaCarta2)
        printf("Vencedor da rodada: Carta 1 (%s)!\n", Nome_Da_Cidade1);
    else if (somaCarta2 > somaCarta1)
        printf("Vencedor da rodada: Carta 2 (%s)!\n", Nome_Da_cidade2);
    else
        printf("Empate!\n");

    return 0;
}