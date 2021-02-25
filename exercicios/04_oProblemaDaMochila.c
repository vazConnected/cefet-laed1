/**
 * Autores: Pedro Vaz e Ana Velasque
 * Disciplina Laboratorio de Algoritmos e Estruturas de Dados I (LAED I)
 * 
 * Prazo para a entrega: 26/02/2021 23:55:55
 * Plataforma: run.codes
 * 
 * Titulo: O Problema da Mochila
 * Descricao: o qualidade da solucao do problema de armazenar o maior
 *   valor agregado de produtos em uma mochila respeitando sua capacidade
 *   de peso
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    int valor;
    int peso;
} Item;

// Valor para a solucao otima - VERIFICADO
int valorSolucaoOtima(int capacidadeRestante, Item* itens, int inicioArray, int tamanhoArray){
    
    // Array percorrido por completo - VERIFICADO
    if(inicioArray == tamanhoArray){
        return 0;
    }

    // Mochila cheia - VERIFICADO
    if(capacidadeRestante <= 0){
        return 0;
    }

    int valorSemEscolha = valorSolucaoOtima(capacidadeRestante, itens, inicioArray + 1, tamanhoArray);
    int valorComEscolha = 0;

    if(itens[inicioArray].peso <= capacidadeRestante){
        capacidadeRestante -= itens[inicioArray].peso;
        valorComEscolha = itens[inicioArray].valor + valorSolucaoOtima(capacidadeRestante, itens, inicioArray + 1, tamanhoArray);
        
        if(valorComEscolha > valorSemEscolha){
            return valorComEscolha;
        }
    }

    return valorSemEscolha;
}

int main(){
    char* caminhoParaArquivo = (char*) malloc(4096 * sizeof(char));

    // Nome do arquivo - VERIFICADO
    printf("Digite o nome do arquivo: ");
    scanf("%s", caminhoParaArquivo);
    caminhoParaArquivo = (char*) realloc(caminhoParaArquivo, strlen(caminhoParaArquivo));
    FILE* arquivo = fopen(caminhoParaArquivo, "r");

    // Capacidade da mochile e qtd de itens na loja - VERIFICADO
    int capacidadeDaMochila, qtdItensDaLoja;
    fscanf(arquivo, "%d", &capacidadeDaMochila);
    fscanf(arquivo, "%d", &qtdItensDaLoja);

    Item* itensDaLoja = (Item*) malloc(qtdItensDaLoja * sizeof(Item));

    // Leitura dos itens da loja - VERIFICADO
    for(int i = 0; i < qtdItensDaLoja; i++){
        fscanf(arquivo, "%d", &itensDaLoja[i].peso);
        fscanf(arquivo, "%d", &itensDaLoja[i].valor);
    }

    int valorEscolhaJogador = 0, pesoEscolhaJogador = 0;
    int* escolhaRealizada = (int*) calloc(qtdItensDaLoja, sizeof(int));

    // Valor total e peso total - VERIFICADO
    for(int i = 0; i < qtdItensDaLoja; i++){
        fscanf(arquivo, "%d", &escolhaRealizada[i]);
        if(escolhaRealizada[i] == 1){
            valorEscolhaJogador += itensDaLoja[i].valor;
            pesoEscolhaJogador += itensDaLoja[i].peso;
        }
    }

    fclose(arquivo);

    // Solucao Inviavel - VERIFICADO
    if(pesoEscolhaJogador > capacidadeDaMochila){ 
        printf("Solucao inviavel.");
        return 0;
    }
    
    // Valor Para Melhor Escolha - VERIFICADO
    int valorEscolhaOtima = valorSolucaoOtima(capacidadeDaMochila, itensDaLoja, 0, qtdItensDaLoja);
    
    if(valorEscolhaJogador < valorEscolhaOtima){
        printf("Solucao viavel mas nao otima.");
    }else{
        printf("Solucao otima.");
    }

    return 0;
}