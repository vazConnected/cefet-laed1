/**
 * Autor: Pedro Henrique Estevam Vaz de Melo
 * Disciplina Laboratorio de Algoritmos e Estruturas de Dados I (LAED I)
 * 
 * Prazo para a entrega: 21/01/2021 25:55:55
 * Plataforma: run.codes
 * 
 * Titulo: Potencia
 * Descricao: realizar a operacao de calcular a potencia de um numero
 * 
 */

#include <stdio.h>
#include <math.h>

int mult(int base, int exp){
    return pow(base, exp);
}

int main(){
    printf("Digite a base e o expoente inteiros: ");
    int base = 0, expoente = 0;
    scanf("%d %d", &base, &expoente);
    
    int resultado = mult(base, expoente);
    printf("Resultado: %d", resultado);
    
    return 0;
}