#include <stdio.h>

#define MAX_CARTAS 5

typedef struct {
    char nome[50];
    int populacao; // em milhões
    float area; // em km²
    int pib; // em bilhões
    float densidadePopulacional; // calculada
    float pibPerCapita; // calculado
} Carta;

void cadastrarCartas(Carta cartas[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Cadastro da carta %d\n", i + 1);
        printf("Digite o nome do país: ");
        scanf("%s", cartas[i].nome);
        printf("Digite a população (em milhões): ");
        scanf("%d", &cartas[i].populacao);
        printf("Digite a área (em km²): ");
        scanf("%f", &cartas[i].area);
        printf("Digite o PIB (em bilhões): ");
        scanf("%d", &cartas[i].pib);
        
        // Calcula as novas propriedades
        cartas[i].densidadePopulacional = (float)cartas[i].populacao * 1000000 / cartas[i].area;
        cartas[i].pibPerCapita = (float)cartas[i].pib * 1000000000 / (cartas[i].populacao * 1000000);
        
        printf("\n");
    }
}

void exibirCartas(Carta cartas[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Carta %d\n", i + 1);
        printf("Nome do país: %s\n", cartas[i].nome);
        printf("População: %d milhões\n", cartas[i].populacao);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("PIB: %d bilhões\n", cartas[i].pib);
        printf("Densidade Populacional: %.2f habitantes/km²\n", cartas[i].densidadePopulacional);
        printf("PIB per Capita: %.2f\n", cartas[i].pibPerCapita);
        printf("\n");
    }
}

int main() {
    Carta cartas[MAX_CARTAS];
    int n;

    printf("Quantas cartas deseja cadastrar (máximo %d)? ", MAX_CARTAS);
    scanf("%d", &n);

    if (n > MAX_CARTAS) {
        printf("Número máximo de cartas é %d. Cadastrando %d cartas.\n", MAX_CARTAS, MAX_CARTAS);
        n = MAX_CARTAS;
    }

    cadastrarCartas(cartas, n);
    exibirCartas(cartas, n);

    return 0;
}