#ifndef CALCULADORA_H
#define CALCULADORA_H

typedef struct {
    char posFixa[512];  // Expressão na forma pos fixa, como 3 12 4 + *
    char inFixa[512];   // Expressão na forma infixa, como 3 * (12 + 4)
    float valor;        // Valor numérico da expressão
} Expressao;

char *getFormaInFixa(const char *str); // Retorna a forma infixa de Str (posFixa)
float getValor(const char *str);       // Calcula o valor de Str (na forma posFixa)

#endif