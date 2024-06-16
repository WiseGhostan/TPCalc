#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Adicionado para corrigir o erro
#include "calculadora.h"

int main() {
    char posFixa[512];

    printf("Digite a expressao posfixa (por exemplo, 3 4 + 5 *): ");
    fgets(posFixa, sizeof(posFixa), stdin);
    posFixa[strcspn(posFixa, "\n")] = '\0'; // Remove o caractere de nova linha

    float valor = getValor(posFixa);

    printf("Resultado: %.2f\n", valor);

    return 0;
}
