#include "calculadora.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI acos(-1)

// Função para verificar se um token é um operador
int isOperator(char *token) {
    return strcmp(token, "+") == 0 || strcmp(token, "-") == 0 ||
           strcmp(token, "*") == 0 || strcmp(token, "/") == 0 ||
           strcmp(token, "^") == 0;
}

// Função para verificar se um token é uma função
int isFunction(char *token) {
    return strcmp(token, "raiz") == 0 || strcmp(token, "sen") == 0 ||
           strcmp(token, "cos") == 0 || strcmp(token, "tg") == 0 ||
           strcmp(token, "log") == 0;
}

// Função para converter expressão posfixa para infixada
char *getFormaInFixa(char *Str) {
    char *tokens[512];
    char *stack[512];
    int top = -1;
    int tokenCount = 0;

    // Criar uma cópia da string para preservar a original
    char *strCopy = strdup(Str);

    // Tokenizar a expressão
    char *token = strtok(strCopy, " ");
    while (token != NULL) {
        tokens[tokenCount++] = token;
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < tokenCount; i++) {
        token = tokens[i];
        if (isOperator(token)) {
            // Operador
            char *op2 = stack[top--];
            char *op1 = stack[top--];
            char *expr = (char *)malloc(512 * sizeof(char));
            snprintf(expr, 512, "(%s %s %s)", op1, token, op2);
            stack[++top] = expr;
        } else if (isFunction(token)) {
            // Função
            char *op = stack[top--];
            char *expr = (char *)malloc(512 * sizeof(char));
            snprintf(expr, 512, "%s(%s)", token, op);
            stack[++top] = expr;
        } else {
            // Número
            char *num = (char *)malloc(512 * sizeof(char));
            strcpy(num, token);
            stack[++top] = num;
        }
    }

    char *result = (char *)malloc(512 * sizeof(char));
    strcpy(result, stack[top]);

    // Libera a memória alocada para a cópia da string
    free(strCopy);

    return result;
}

// Função para calcular o valor de uma expressão posfixa
float getValor(char *Str) {
    char *tokens[512];
    float stack[512];
    int top = -1;
    int tokenCount = 0;

    // Criar uma cópia da string para preservar a original
    char *strCopy = strdup(Str);

    // Tokenizar a expressão
    char *token = strtok(strCopy, " ");
    while (token != NULL) {
        tokens[tokenCount++] = token;
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < tokenCount; i++) {
        token = tokens[i];
        if (isOperator(token)) {
            // Operador
            float operand2 = stack[top--];
            float operand1 = stack[top--];
            if (strcmp(token, "+") == 0) {
                stack[++top] = operand1 + operand2;
            } else if (strcmp(token, "-") == 0) {
                stack[++top] = operand1 - operand2;
            } else if (strcmp(token, "*") == 0) {
                stack[++top] = operand1 * operand2;
            } else if (strcmp(token, "/") == 0) {
                stack[++top] = operand1 / operand2;
            } else if (strcmp(token, "^") == 0) {
                stack[++top] = pow(operand1, operand2);
            }
        } else if (isFunction(token)) {
            // Função
            float operand = stack[top--];
            if (strcmp(token, "raiz") == 0) {
                stack[++top] = sqrt(operand);
            } else if (strcmp(token, "sen") == 0) {
                stack[++top] = sin(PI * operand / 180.0);
            } else if (strcmp(token, "cos") == 0) {
                stack[++top] = cos(PI * operand / 180.0);
            } else if (strcmp(token, "tg") == 0) {
                stack[++top] = tan(PI * operand / 180.0);
            } else if (strcmp(token, "log") == 0) {
                stack[++top] = log10(operand);
            }
        } else {
            // Número
            stack[++top] = atof(token);
        }
    }

    float result = stack[top];

    // Libera a memória alocada para a cópia da string
    free(strCopy);

    return result;
}

