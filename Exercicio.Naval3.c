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
                printf("5 ");  // Área afetada pela habilidade
            }
        }
        printf("\n");
    }
}

// Função para aplicar a habilidade Cone no tabuleiro
void aplicarHabilidadeCone(int tabuleiro[LINHAS][COLUNAS], int linhaOrigem, int colunaOrigem) {
    int tamanho = 5; // Tamanho da matriz Cone 5x5
    int cone[tamanho][tamanho];

    // Criação da matriz de habilidade Cone (expande para baixo)
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (j >= (tamanho / 2) - i && j <= (tamanho / 2) + i) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    // Aplicação da habilidade no tabuleiro
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            int x = linhaOrigem + i - (tamanho / 2);
            int y = colunaOrigem + j - (tamanho / 2);
            if (x >= 0 && x < LINHAS && y >= 0 && y < COLUNAS && cone[i][j] == 1) {
                tabuleiro[x][y] = 5; // Marca a área afetada pela habilidade
            }
        }
    }
}

// Função para aplicar a habilidade Cruz no tabuleiro
void aplicarHabilidadeCruz(int tabuleiro[LINHAS][COLUNAS], int linhaOrigem, int colunaOrigem) {
    int tamanho = 5; // Tamanho da matriz Cruz 5x5
    int cruz[tamanho][tamanho];

    // Criação da matriz de habilidade Cruz (linha e coluna no centro)
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (i == tamanho / 2 || j == tamanho / 2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // Aplicação da habilidade no tabuleiro
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            int x = linhaOrigem + i - (tamanho / 2);
            int y = colunaOrigem + j - (tamanho / 2);
            if (x >= 0 && x < LINHAS && y >= 0 && y < COLUNAS && cruz[i][j] == 1) {
                tabuleiro[x][y] = 5; // Marca a área afetada pela habilidade
            }
        }
    }
}

// Função para aplicar a habilidade Octaedro no tabuleiro
void aplicarHabilidadeOctaedro(int tabuleiro[LINHAS][COLUNAS], int linhaOrigem, int colunaOrigem) {
    int tamanho = 5; // Tamanho da matriz Octaedro 5x5
    int octaedro[tamanho][tamanho];

    // Criação da matriz de habilidade Octaedro (forma de losango)
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (i + j >= tamanho / 2 && i + j <= 3 * tamanho / 2) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // Aplicação da habilidade no tabuleiro
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            int x = linhaOrigem + i - (tamanho / 2);
            int y = colunaOrigem + j - (tamanho / 2);
            if (x >= 0 && x < LINHAS && y >= 0 && y < COLUNAS && octaedro[i][j] == 1) {
                tabuleiro[x][y] = 5; // Marca a área afetada pela habilidade
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

    // Definir a origem das habilidades (Exemplo de origem no meio do tabuleiro)
    int linhaOrigemCone = 4, colunaOrigemCone = 4;
    int linhaOrigemCruz = 5, colunaOrigemCruz = 5;
    int linhaOrigemOctaedro = 3, colunaOrigemOctaedro = 3;

    // Aplicando as habilidades
    aplicarHabilidadeCone(tabuleiro, linhaOrigemCone, colunaOrigemCone);
    aplicarHabilidadeCruz(tabuleiro, linhaOrigemCruz, colunaOrigemCruz);
    aplicarHabilidadeOctaedro(tabuleiro, linhaOrigemOctaedro, colunaOrigemOctaedro);

    // Exibindo o tabuleiro após aplicar as habilidades
    printf("Tabuleiro com habilidades aplicadas:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
