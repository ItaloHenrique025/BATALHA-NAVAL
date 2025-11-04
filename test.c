#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("0 ");  // Água
            } else if (tabuleiro[i][j] == 3) {
                printf("3 ");  // Navio
            } else if (tabuleiro[i][j] == 5) {
                printf("5 ");  // Área afetada pela habilidade Octaedro
            } else if (tabuleiro[i][j] == 4) {
                printf("4 ");  // Área afetada pela habilidade Cruz
            } else if (tabuleiro[i][j] == 1) {
                printf("1 ");  // Área afetada pela habilidade Cone
            }
        }
        printf("\n");
    }
}

// Função para aplicar a habilidade Cone no tabuleiro
void aplicarHabilidadeCone(int tabuleiro[LINHAS][COLUNAS], int linhaOrigem, int colunaOrigem) {
    int cone[3][5] = {  // Matriz 3x5 do Cone
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1}
    };

    // Aplica o cone no tabuleiro
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            int x = linhaOrigem + i;
            int y = colunaOrigem + j - 2;  // Ajusta para centralizar
            if (x >= 0 && x < LINHAS && y >= 0 && y < COLUNAS && cone[i][j] && tabuleiro[x][y] == 0) {
                tabuleiro[x][y] = 1;  // Marca a área afetada
            }
        }
    }
}

// Função para aplicar a habilidade Cruz no tabuleiro
void aplicarHabilidadeCruz(int tabuleiro[LINHAS][COLUNAS], int linhaOrigem, int colunaOrigem) {
    int tamanho = 5;
    int cruz[5][5] = {  // Matriz 5x5 da Cruz
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };

    // Aplica a cruz no tabuleiro
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            int x = linhaOrigem + i - (tamanho / 2);
            int y = colunaOrigem + j - (tamanho / 2);
            if (x >= 0 && x < LINHAS && y >= 0 && y < COLUNAS && cruz[i][j] && tabuleiro[x][y] == 0) {
                tabuleiro[x][y] = 4;  // Marca a área afetada
            }
        }
    }
}

// Função para aplicar a habilidade Octaedro (Cruz 3x3) no tabuleiro
void aplicarHabilidadeOctaedro(int tabuleiro[LINHAS][COLUNAS], int linhaOrigem, int colunaOrigem) {
    int octaedro[3][3] = {  // Matriz 3x3 do Octaedro (cruz)
        {0, 1, 0},
        {1, 1, 1},
        {0, 1, 0}
    };

    // Aplica o octaedro no tabuleiro
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int x = linhaOrigem + i - 1;  // Ajusta o centro
            int y = colunaOrigem + j - 1;
            if (x >= 0 && x < LINHAS && y >= 0 && y < COLUNAS && octaedro[i][j] && tabuleiro[x][y] == 0) {
                tabuleiro[x][y] = 5;  // Marca a área afetada
            }
        }
    }
}

int main() {
    int tabuleiro[LINHAS][COLUNAS] = {0};  // Inicializa o tabuleiro com 0 (Água)

    // Define a posição dos navios
    tabuleiro[2][3] = 3;  // Navio na posição (2,3)
    tabuleiro[4][5] = 3;  // Navio na posição (4,5)
    tabuleiro[6][7] = 3;  // Navio na posição (6,7)

    // Define as origens das habilidades
    int linhaOrigemCone = 0, colunaOrigemCone = 4;  // Cone começa na linha 0
    int linhaOrigemCruz = 5, colunaOrigemCruz = 5;  // Cruz no centro
    int linhaOrigemOctaedro = 3, colunaOrigemOctaedro = 3;  // Octaedro no centro

    // Aplica as habilidades
    aplicarHabilidadeCone(tabuleiro, linhaOrigemCone, colunaOrigemCone);
    aplicarHabilidadeCruz(tabuleiro, linhaOrigemCruz, colunaOrigemCruz);
    aplicarHabilidadeOctaedro(tabuleiro, linhaOrigemOctaedro, colunaOrigemOctaedro);

    // Exibe o tabuleiro após as habilidades
    printf("Tabuleiro com habilidades aplicadas:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
