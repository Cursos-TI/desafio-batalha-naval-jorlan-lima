#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}

#include <stdio.h>
#include <stdlib.h> // Para a função exit() se necessário

// Constantes para o tamanho do tabuleiro
#define TAMANHO_TABULEIRO_NOVATO 5
#define TAMANHO_TABULEIRO_AVENTUREIRO 10
#define TAMANHO_HABILIDADE 5 // Tamanho fixo para as matrizes de habilidade

// Símbolos no Tabuleiro
#define AGUA 0
#define NAVIO 3
#define AFETADO 1


// ======================================================================
// 🏅 NÍVEL NOVATO: Matriz 5x5 e Posicionamento Básico
// ======================================================================

void nivelNovato() {
    printf("==========================================\n");
    printf("         🏅 NÍVEL NOVATO: Posicionamento Básico\n");
    printf("==========================================\n");

    // Requisito: Utilização de vetores bidimensionais (Matriz 5x5)
    int tabuleiro[TAMANHO_TABULEIRO_NOVATO][TAMANHO_TABULEIRO_NOVATO] = {0};

    // Navio 1: Vertical (Tamanho 3) - Posição inicial (1, 2)
    const int NAVIO1_TAM = 3;
    const int NAVIO1_X = 1; // Linha (Y)
    const int NAVIO1_Y = 2; // Coluna (X)

    // Navio 2: Horizontal (Tamanho 4) - Posição inicial (4, 0)
    const int NAVIO2_TAM = 4;
    const int NAVIO2_X = 4; // Linha (Y)
    const int NAVIO2_Y = 0; // Coluna (X)

    printf("\n--- Posicionamento dos Navios ---\n");

    // Posicionamento e Exibição do Navio 1 (Vertical)
    printf("Navio 1 (Vertical - Tamanho %d):\n", NAVIO1_TAM);
    for (int i = 0; i < NAVIO1_TAM; i++) {
        // Coordenadas: (Linha + i, Coluna)
        int x = NAVIO1_X + i;
        int y = NAVIO1_Y;

        // Verifica os limites da matriz antes de posicionar
        if (x < TAMANHO_TABULEIRO_NOVATO) {
            tabuleiro[x][y] = NAVIO;
            printf("  Coordenada: (%d, %d)\n", x, y);
        }
    }

    // Posicionamento e Exibição do Navio 2 (Horizontal)
    printf("\nNavio 2 (Horizontal - Tamanho %d):\n", NAVIO2_TAM);
    for (int j = 0; j < NAVIO2_TAM; j++) {
        // Coordenadas: (Linha, Coluna + j)
        int x = NAVIO2_X;
        int y = NAVIO2_Y + j;

        // Verifica os limites da matriz antes de posicionar
        if (y < TAMANHO_TABULEIRO_NOVATO) {
            tabuleiro[x][y] = NAVIO;
            printf("  Coordenada: (%d, %d)\n", x, y);
        }
    }

    // Exibição do Tabuleiro (Opcional, mas útil para visualização)
    printf("\n--- Tabuleiro 5x5 (0=Água, 3=Navio) ---\n");
    for (int i = 0; i < TAMANHO_TABULEIRO_NOVATO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO_NOVATO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// ======================================================================
// 🏅 NÍVEL AVENTUREIRO: Tabuleiro 10x10 e Navios Diagonais
// ======================================================================

void nivelAventureiro() {
    printf("\n\n==========================================\n");
    printf("      🏅 NÍVEL AVENTUREIRO: Tabuleiro 10x10 e Diagonais\n");
    printf("==========================================\n");

    // Requisito: Matriz 10x10
    int tabuleiro[TAMANHO_TABULEIRO_AVENTUREIRO][TAMANHO_TABULEIRO_AVENTUREIRO] = {0};

    // Navios
    // 1. Vertical (Tam 4) - Início (1, 1)
    const int N1_TAM = 4, N1_X = 1, N1_Y = 1;
    // 2. Horizontal (Tam 3) - Início (8, 5)
    const int N2_TAM = 3, N2_X = 8, N2_Y = 5;
    // 3. Diagonal Superior Direita (Tam 3) - Início (4, 0)
    const int N3_TAM = 3, N3_X = 4, N3_Y = 0;
    // 4. Diagonal Inferior Direita (Tam 4) - Início (0, 7)
    const int N4_TAM = 4, N4_X = 0, N4_Y = 7;

    printf("\n--- Posicionamento de 4 Navios (Incluindo 2 Diagonais) ---\n");

    // Lógica de Posicionamento (Laços simples para vertical e horizontal)
    // Navio 1 (Vertical)
    for (int i = 0; i < N1_TAM; i++) {
        tabuleiro[N1_X + i][N1_Y] = NAVIO;
    }
    // Navio 2 (Horizontal)
    for (int j = 0; j < N2_TAM; j++) {
        tabuleiro[N2_X][N2_Y + j] = NAVIO;
    }

    // Navio 3 (Diagonal Superior Direita: Linha Aumenta, Coluna Aumenta)
    printf("Navio 3 (Diagonal Superior Direita - Tam %d):\n", N3_TAM);
    for (int k = 0; k < N3_TAM; k++) {
        int x = N3_X + k;
        int y = N3_Y + k;
        if (x < TAMANHO_TABULEIRO_AVENTUREIRO && y < TAMANHO_TABULEIRO_AVENTUREIRO) {
            tabuleiro[x][y] = NAVIO;
            printf("  Coordenada: (%d, %d)\n", x, y);
        }
    }

    // Navio 4 (Diagonal Inferior Direita: Linha Aumenta, Coluna Diminui)
    printf("Navio 4 (Diagonal Inferior Direita - Tam %d):\n", N4_TAM);
    for (int l = 0; l < N4_TAM; l++) {
        int x = N4_X + l;
        int y = N4_Y - l; // Coluna diminui
        if (x < TAMANHO_TABULEIRO_AVENTUREIRO && y >= 0) {
            tabuleiro[x][y] = NAVIO;
            printf("  Coordenada: (%d, %d)\n", x, y);
        }
    }

    // Requisito: Exibição Completa do Tabuleiro (0=Água, 3=Ocupado)
    printf("\n--- Tabuleiro 10x10 Completo ---\n");
    for (int i = 0; i < TAMANHO_TABULEIRO_AVENTUREIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO_AVENTUREIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}


// ======================================================================
// 🥇 NÍVEL MESTRE: Habilidades Especiais (Padrões de Matriz)
// ======================================================================

/**
 * @brief Exibe uma matriz de habilidade 5x5.
 * @param matriz A matriz de habilidade.
 * @param nome O nome da habilidade.
 */
void exibirHabilidade(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], const char* nome) {
    printf("\n--- Habilidade: %s (0=Não Afetado, 1=Afetado) ---\n", nome);
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void nivelMestre() {
    printf("\n\n==========================================\n");
    printf("      🥇 NÍVEL MESTRE: Habilidades Especiais\n");
    printf("==========================================\n");

    // Matrizes para as habilidades 5x5
    int habilidade_cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
    int habilidade_cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
    int habilidade_octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
    
    // Ponto central de referência (índice 2, 2 para matriz 5x5)
    const int CENTRO = TAMANHO_HABILIDADE / 2; // 5 / 2 = 2

    // Requisito: Estruturas de Repetição Aninhadas para preenchimento
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            
            // ------------------------------------
            // 1. Padrão CONE (Exemplo de saída: Triângulo/Cone de 3 linhas)
            // A área afetada se alarga na parte inferior da matriz.
            if (i >= CENTRO - 1) { // Afeta linhas 1, 2, 3, 4 (índices 1 a 4)
                 // Define a largura (ex: Linha 2 afeta 3 colunas, Linha 4 afeta 5 colunas)
                 // abs(j - CENTRO) é a distância horizontal do centro
                 if (abs(j - CENTRO) <= (i - (CENTRO - 1))) {
                      habilidade_cone[i][j] = AFETADO;
                 }
            }
            // Para reproduzir o exemplo dado (00100, 01110, 11111) de forma simples:
            if (i >= 2) { // Afeta linhas 2, 3, 4
                // Usamos uma lógica mais simples para simular o crescimento:
                if (abs(j - CENTRO) <= (i - 2)) {
                   habilidade_cone[i][j] = AFETADO;
                }
            } else if (i == 1) {
                if (abs(j - CENTRO) <= 1) {
                    habilidade_cone[i][j] = AFETADO;
                }
            } else if (i == 0 && j == CENTRO) {
                 habilidade_cone[i][j] = AFETADO;
            }
            // Fim da adaptação do CONE

            // ------------------------------------
            // 2. Padrão CRUZ (Linha e Coluna central inteiras)
            if (i == CENTRO || j == CENTRO) {
                habilidade_cruz[i][j] = AFETADO;
            }

            // ------------------------------------
            // 3. Padrão OCTAEDRO (Losango/Diamante centrado)
            // A soma da distância vertical (abs(i-CENTRO)) e horizontal (abs(j-CENTRO))
            // deve ser menor ou igual ao raio (CENTRO).
            if (abs(i - CENTRO) + abs(j - CENTRO) <= CENTRO) {
                habilidade_octaedro[i][j] = AFETADO;
            }
        }
    }

    // Requisito: Exibição das Áreas Atingidas
    exibirHabilidade(habilidade_cone, "CONE (Adaptado ao Exemplo)");
    exibirHabilidade(habilidade_cruz, "CRUZ");
    exibirHabilidade(habilidade_octaedro, "OCTAEDRO (Losango)");
}


// ======================================================================
// FUNÇÃO PRINCIPAL
// ======================================================================

int main() {
    // Chama as funções para cada nível do desafio
    nivelNovato();
    nivelAventureiro();
    nivelMestre();

    printf("\n\nDesafio Batalha Naval concluído com sucesso!\n");
    return 0;
}