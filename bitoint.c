#include <stdio.h>
#include <string.h>

// Função para converter uma string binária em um número inteiro
int binaryToInt(const char *binaryString) {
    int length = strlen(binaryString);
    int result = 0;
    int i = 0;

    // Inicializa i com o índice do bit menos significativo
    while (i < length) {
        // Converte o caractere '0' ou '1' para 0 ou 1
        int bit = binaryString[length - 1 - i] - '0';

        // Calcula o valor inteiro acumulado
        result += bit * (1 << i); // Equivalente a result += bit * pow(2, i);

        // Incrementa o índice para avançar para o próximo bit
        i++;
    }

    return result;
}

int main() {
    char binaryString[65]; // Considerando uma string binária de até 64 bits

    printf("Digite uma string binária: ");
    scanf("%s", binaryString);

    int intValue = binaryToInt(binaryString);
    printf("O valor inteiro equivalente a %s é: %d\n", binaryString, intValue);

    return 0;
}
