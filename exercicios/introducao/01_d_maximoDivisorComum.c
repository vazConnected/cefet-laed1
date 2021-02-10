/**
 * Autor: Pedro Vaz
 * Disciplina Laboratorio de Algoritmos e Estruturas de Dados I (LAED I)
 * 
 * Prazo para a entrega: 21/01/2021 25:55:55
 * Plataforma: run.codes
 * 
 * Titulo: Maximo divisor comum
 * Descricao: descobrir o valor do maximo divisor comum entre dois numeros com uma funcao recursiva
 * 
 */

#include <stdio.h>

int mdc(int a, int b){
    int maximoDivisorComum = 1;
    if(a == 1 || b == 1)
        return maximoDivisorComum;

    int maiorNumero = b;
    if(a > b)
        maiorNumero = a;

    for(int i = 2; i <= maiorNumero; i++){
        if(a % i == 0 && b  % i == 0){
            a /= i;
            b /= i;
            
            maximoDivisorComum *= i * mdc(a, b);
            break;
        }
    }

    return maximoDivisorComum;
}

int main(){
    printf("Digite dois numeros inteiros: ");
    int numeroA = 0, numeroB = 0;
    scanf("%d %d", &numeroA, &numeroB);

    int maximoDivisorComum = mdc(numeroA, numeroB);
    printf("Resultado: %d", maximoDivisorComum);

    return 0;
}