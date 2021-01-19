/**
 * Autor: Pedro Henrique Estevam Vaz de Melo
 * Disciplina Laboratorio de Algoritmos e Estruturas de Dados I (LAED I)
 * 
 * Prazo para a entrega: 21/01/2021 25:55:55
 * Plataforma: run.codes
 * 
 * Titulo: Soma de dois números (teste)
 * Descricao: O programa recebe dois valores inteiros e retorna a soma das respectivas entradas
 * 
 */

#include <stdio.h>

int main(){
    int primeiroNumero = 0, segundoNumero = 0;

    printf("Digite os dois numeros: ");
    scanf("%d %d", &primeiroNumero, &segundoNumero);

    int resultado = primeiroNumero + segundoNumero;

    printf("Resultado = %d", resultado);

    return 0;
}