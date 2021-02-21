/**
 * Autores: Pedro Vaz e Ana Velasque
 * Disciplina Laboratorio de Algoritmos e Estruturas de Dados I (LAED I)
 * 
 * Prazo para a entrega: 1
 * Plataforma: run.codes
 * 
 * Titulo: O Problema da Mochila
 * Descricao: o qualidade da solucao do problema de armazenar o maior
 *   valor agragado de produtos em uma mochila respeitando sua capacidade
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

/*
 * Retorna falso se a escolha realizada e invalida ou pior que a do jogador
 * Legenda : 
 *   EJ : escolha do jogador
 *   EA : escolha atual
 */
bool analisaEscolha(int capacidadeMochila, int valorEJ, int valorEA, int pesoEA, Item* itens, int inicioArray, int tamanho){
    if(pesoEA > capacidadeMochila){ // Capacidade da mochila excedida
        return false;
    }else if(inicioArray == tamanho - 1){ // Se for o ultimo elemento possivel
        if(valorEA + itens[inicioArray].valor > valorEJ && pesoEA + itens[inicioArray].peso <= capacidadeMochila){ // Se o valor nao for bom o suficiente
            return true; // Escolha melhor que a do jogador
        }
        return false;
    }

    inicioArray++;

    // Item atual nao escolhido
    bool escolha0 = analisaEscolha(capacidadeMochila, valorEJ, valorEA, pesoEA, itens, inicioArray, tamanho);

    // Item atual escolhido
    valorEA += itens[inicioArray].valor;
    pesoEA += itens[inicioArray].peso;
    if(pesoEA > capacidadeMochila){ // Se utrapassar a capacidade da mochila
        return false;
    }
    bool escolha1 = analisaEscolha(capacidadeMochila, valorEJ, valorEA, pesoEA, itens, inicioArray, tamanho);

    if(escolha0 || escolha1){ // Alguma das escolhas e viavel e melhor que a do jogador
        return true;
    }
}

int main(){
    char* caminhoParaArquivo = (char*) malloc(4096 * sizeof(char));

    printf("Digite o nome do arquivo: ");
    scanf("%s", caminhoParaArquivo);
    caminhoParaArquivo = (char*) realloc(caminhoParaArquivo, strlen(caminhoParaArquivo));

    FILE* arquivo = fopen(caminhoParaArquivo, "r");

    int capacidadeDaMochila, qtdItensDaLoja;
    fscanf(arquivo, "%d", &capacidadeDaMochila);
    fscanf(arquivo, "%d", &qtdItensDaLoja);

    Item* itensDaLoja = (Item*) malloc(qtdItensDaLoja * sizeof(Item));

    for(int i = 0; i < qtdItensDaLoja; i++){
        fscanf(arquivo, "%d", &itensDaLoja[i].peso);
        fscanf(arquivo, "%d", &itensDaLoja[i].valor);
    }

    int valorTotal = 0;
    int pesoTotal = 0;
    char* escolhaRealizada = (char*) calloc(qtdItensDaLoja, sizeof(char));

    for(int i = 0; i < qtdItensDaLoja; i++){
        fscanf(arquivo, "%c", &escolhaRealizada[i]);
        if(escolhaRealizada[i] == '1'){
            valorTotal += itensDaLoja[i].valor;
            pesoTotal += itensDaLoja[i].peso;
        }
    }

    fclose(arquivo);

    if(pesoTotal > capacidadeDaMochila){
        printf("Solucao inviavel.");
        return 0;
    }

    char* possivelSolucaoOtima = (char*) malloc( qtdItensDaLoja * sizeof(char) );

    bool solucaoViavelNaoOtima = analisaEscolha(capacidadeDaMochila, valorTotal, 0, 0, itensDaLoja, 0, qtdItensDaLoja);

    if(solucaoViavelNaoOtima){
        printf("Solucao viavel mas nao otima."); 
    }else{
        printf("Solucao otima.");
    }

    return 0;
}