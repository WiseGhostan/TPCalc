#ifndef CALCULADORA_H
#define CALCULADORA_H

typedef struct {
    char posFixa[512];  // Expressão na forma pos fixa, como 3 12 4 + *
    char inFixa[512];   // Expressão na forma pos fixa, como 3 * (12 + 4)
    float valor;        // Valor numérico da expressão
} Expressao;

char *getFormaInFixa(char *str); // Retorna a forma inFixa de Str (posFixa)
float getValor(char *str);       // Calcula o valor de Str (na forma posFixa)

#endif
