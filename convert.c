#include <stdio.h>

// Função para imprimir a representação binária de um inteiro
void printBinary(int num) {
    if (num == 0) {
        printf("0\n");
        return;
    }

    unsigned int mask = 1 << (sizeof(int) * 8 - 1); // Mascara para o bit mais significativo
    int started = 0; // Flag para detectar o primeiro bit 1

    while (mask > 0) {
        if (num & mask) {
            started = 1; // Detecta o primeiro bit 1
            printf("1");
        } else if (started) {
            printf("0");
        }
        mask >>= 1; // Move a máscara para o próximo bit
    }

    printf("\n");
}

int main() {
    int num;

    printf("Digite um número inteiro: ");
    scanf("%d", &num);

    printf("A representação binária de %d é: ", num);
    printBinary(num);

    return 0;
}

