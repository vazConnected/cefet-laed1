/**
 * Autor: Pedro Henrique Estevam Vaz de Melo
 * Disciplina Laboratorio de Algoritmos e Estruturas de Dados I (LAED I)
 * 
 * Prazo para a entrega: 21/01/2021 25:55:55
 * Plataforma: run.codes
 * 
 * Titulo: Digitos
 * Descricao: O programa le um numero inteiro e retorna a sua quantidade de digitos
 * 
 */

#include <stdio.h>

int Digitos(int N){
  int cont = 1;

  if(N >= 10){
    cont += Digitos(N/10);
  }

  return cont;
}

int main(){
    int numeroDeEntrada;
    printf("Digite um numero inteiro: ");
    scanf("%d", &numeroDeEntrada);

    int resultado = Digitos(numeroDeEntrada);
    printf("Resultado: %d", resultado);

    return 0;
}