#include <stdio.h>

#define NUM_ESTADOS 8
#define CIDADES_POR_ESTADO 4

// Estrutura para representar uma cidade
typedef struct {
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Cidade;

void cadastrar_cidade(Cidade *cidade, char estado, int numero) {
    // Gerar o código da cidade
    sprintf(cidade->codigo, "%c%02d", estado, numero);

    // Entrada de dados
    printf("Cadastro da cidade %s:\n", cidade->codigo);
    printf("Digite a população: ");
    scanf("%d", &cidade->populacao);
    printf("Digite a área (km²): ");
    scanf("%f", &cidade->area);
    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &cidade->pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &cidade->pontos_turisticos);

    // Cálculos das propriedades adicionais
    cidade->densidade_populacional = cidade->populacao / cidade->area;
    cidade->pib_per_capita = cidade->pib * 1e9 / cidade->populacao;

    printf("\n");
}

void exibir_cidade(const Cidade *cidade) {
    printf("Cidade %s:\n", cidade->codigo);
    printf("População: %d\n", cidade->populacao);
    printf("Área: %.2f km²\n", cidade->area);
    printf("PIB: %.2f bilhões\n", cidade->pib);
    printf("Pontos turísticos: %d\n", cidade->pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", cidade->densidade_populacional);
    printf("PIB per Capita: %.2f R$/hab\n", cidade->pib_per_capita);
    printf("---------------------------\n");
}

int main() {
    Cidade cartas[NUM_ESTADOS][CIDADES_POR_ESTADO];
    char estados[NUM_ESTADOS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int i, j;

    printf("Bem-vindo ao Super Trunfo - Cadastro de Cartas!\n\n");

    // Cadastro de todas as cidades
    for (i = 0; i < NUM_ESTADOS; i++) {
        for (j = 0; j < CIDADES_POR_ESTADO; j++) {
            cadastrar_cidade(&cartas[i][j], estados[i], j + 1);
        }
    }

    // Exibição dos dados cadastrados
    printf("\nDados cadastrados:\n");
    printf("===========================\n");
    for (i = 0; i < NUM_ESTADOS; i++) {
        for (j = 0; j < CIDADES_POR_ESTADO; j++) {
            exibir_cidade(&cartas[i][j]);
        }
    }

    return 0;
}
