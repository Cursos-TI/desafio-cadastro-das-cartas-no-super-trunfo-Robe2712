#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// Função para cadastrar territórios
void cadastrarTerritorios(Territorio* mapa, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("\nCadastro do território %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", mapa[i].nome);
        printf("Cor do exército: ");
        scanf(" %[^\n]", mapa[i].cor);
        printf("Quantidade de tropas: ");
        scanf("%d", &mapa[i].tropas);
    }
}

// Função para exibir os territórios
void exibirMapa(Territorio* mapa, int tamanho) {
    printf("\n--- Mapa Atualizado ---\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Território %d: %s | Cor: %s | Tropas: %d\n",
               i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

// Função para simular ataque
void atacar(Territorio* atacante, Territorio* defensor) {
    if (strcmp(atacante->cor, defensor->cor) == 0) {
        printf("\nAtaque inválido: ambos os territórios são da mesma cor.\n");
        return;
    }

    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;

    printf("\nAtaque de %s contra %s\n", atacante->nome, defensor->nome);
    printf("Dado atacante: %d | Dado defensor: %d\n", dadoAtacante, dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        printf("Vitória do atacante!\n");
        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = atacante->tropas / 2;
    } else {
        printf("Defesa bem-sucedida. Atacante perde uma tropa.\n");
        atacante->tropas = (atacante->tropas > 0) ? atacante->tropas - 1 : 0;
    }
}

// Função para liberar memória
void liberarMemoria(Territorio* mapa, char* missaoJogador) {
    free(mapa);
    free(missaoJogador);
}

// Função para perguntar se o jogador quer continuar
int desejaContinuar() {
    char resposta[5];
    printf("\nDeseja continuar o jogo? (sim/não): ");
    scanf(" %s", resposta);
    return strcmp(resposta, "sim") == 0;
}

// Função para coletar cores únicas do mapa
void coletarCores(char cores[][10], Territorio* mapa, int tamanho, int* totalCores) {
    *totalCores = 0;
    for (int i = 0; i < tamanho; i++) {
        int existe = 0;
        for (int j = 0; j < *totalCores; j++) {
            if (strcmp(cores[j], mapa[i].cor) == 0) {
                existe = 1;
                break;
            }
        }
        if (!existe) {
            strcpy(cores[*totalCores], mapa[i].cor);
            (*totalCores)++;
        }
    }
}

// Função para atribuir missão com base nas cores reais
void atribuirMissaoComConfirmacao(char* destino, char cores[][10], int totalCores) {
    char resposta[5];
    int tentativa = 0;

    do {
        int sorteio = rand() % totalCores;
        sprintf(destino, "Eliminar todas as tropas da cor %s", cores[sorteio]);
        printf("\nMissão sorteada: %s\n", destino);
        printf("Você aceita essa missão? (sim/não): ");
        scanf(" %s", resposta);

        if (strcmp(resposta, "sim") == 0) {
            printf("Missão confirmada: %s\n", destino);
            return;
        }

        tentativa++;
    } while (tentativa < 3);

    // Missão automática após 3 recusas
    int sorteio = rand() % totalCores;
    sprintf(destino, "Eliminar todas as tropas da cor %s", cores[sorteio]);
    printf("Missão atribuída automaticamente: %s\n", destino);
}

// Verifica se a missão foi cumprida
int verificarMissao(char* missao, Territorio* mapa, int tamanho) {
    char corAlvo[10];
    if (sscanf(missao, "Eliminar todas as tropas da cor %s", corAlvo) == 1) {
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, corAlvo) == 0 && mapa[i].tropas > 0) {
                return 0; // Missão não cumprida
            }
        }
        return 1; // Missão cumprida
    }
    return 0;
}

// Recompensa por missão cumprida
void concederRecompensa(Territorio* mapa, int tamanho, char* corAliada) {
    int recompensa = rand() % 11 + 5; // 5 a 15 tropas
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(mapa[i].cor, corAliada) == 0) {
            mapa[i].tropas += recompensa;
            printf("\nRecompensa: %d tropas adicionadas ao território %s!\n", recompensa, mapa[i].nome);
            return;
        }
    }
    printf("\nNenhum território aliado encontrado para receber a recompensa.\n");
}

// Função principal
int main() {
    srand(time(NULL));

    int totalTerritorios;
    printf("Digite o número de territórios: ");
    scanf("%d", &totalTerritorios);

    Territorio* mapa = (Territorio*)calloc(totalTerritorios, sizeof(Territorio));
    cadastrarTerritorios(mapa, totalTerritorios);
    exibirMapa(mapa, totalTerritorios);

    // Coleta de cores reais
    char cores[10][10];
    int totalCores;
    coletarCores(cores, mapa, totalTerritorios, &totalCores);

    // Atribuição de missão
    char* missaoJogador = (char*)malloc(100 * sizeof(char));
    atribuirMissaoComConfirmacao(missaoJogador, cores, totalCores);

    // Loop de turnos
    while (desejaContinuar()) {
        int atacante, defensor;
        printf("\nEscolha o território atacante (1 a %d): ", totalTerritorios);
        scanf("%d", &atacante);
        printf("Escolha o território defensor (1 a %d): ", totalTerritorios);
        scanf("%d", &defensor);

        if (atacante < 1 || atacante > totalTerritorios || defensor < 1 || defensor > totalTerritorios) {
            printf("Território inválido. Tente novamente.\n");
            continue;
        }

        atacar(&mapa[atacante - 1], &mapa[defensor - 1]);
        exibirMapa(mapa, totalTerritorios);

        if (verificarMissao(missaoJogador, mapa, totalTerritorios)) {
            printf("\nParabéns! Você cumpriu sua missão: %s\n", missaoJogador);
            concederRecompensa(mapa, totalTerritorios, mapa[atacante - 1].cor);
            break;
        } else {
            printf("\nMissão ainda não cumprida. Continue tentando!\n");
        }
    }

    liberarMemoria(mapa, missaoJogador);
    printf("\nJogo encerrado. Obrigado por jogar!\n");
    return 0;
}