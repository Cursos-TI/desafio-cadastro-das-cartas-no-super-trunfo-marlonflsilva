#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int populacao;
    float area;
    float densidade_populacional;
    int super_poder;
} Carta;

void calcularPropriedades(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->super_poder = carta->populacao + (int)carta->area + (int)carta->densidade_populacional;
}

void cadastrarCarta(Carta *carta) {
    printf("Digite o nome do país: ");
    scanf("%s", carta->nome);
    printf("Digite a população: ");
    scanf("%d", &carta->populacao);
    printf("Digite a área: ");
    scanf("%f", &carta->area);
    calcularPropriedades(carta);
}

void compararCartas(Carta *carta1, Carta *carta2) {
    printf("Comparando %s e %s:\n", carta1->nome, carta2->nome);
    
    // Comparar densidade populacional
    if (carta1->densidade_populacional < carta2->densidade_populacional) {
        printf("Densidade Populacional: %s vence\n", carta1->nome);
    } else {
        printf("Densidade Populacional: %s vence\n", carta2->nome);
    }

    // Comparar super poder
    if (carta1->super_poder > carta2->super_poder) {
        printf("Super Poder: %s vence\n", carta1->nome);
    } else {
        printf("Super Poder: %s vence\n", carta2->nome);
    }
}

int main() {
    Carta carta1, carta2;

    printf("Cadastro da primeira carta:\n");
    cadastrarCarta(&carta1);

    printf("Cadastro da segunda carta:\n");
    cadastrarCarta(&carta2);

    compararCartas(&carta1, &carta2);

    return 0;
}