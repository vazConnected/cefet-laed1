/**
 * Autores: Pedro Vaz e Ana Julia Velasque
 * Disciplina Laboratorio de Algoritmos e Estruturas de Dados I (LAED I)
 * 
 * Prazo para a entrega: 19/03/2021 25:55:55
 * Plataforma: run.codes
 * 
 * Titulo: Projeto (Parte 1) - Busca por padrão em sequência
 * Descricao: ler um arquivo e buscar por um padrão numérico pré definido em uma seguencia de inteiros.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(){
    // Entrada do nome do arquivo - VERIFICADO
    char* caminhoParaArquivo = (char*) malloc(4096* sizeof(char));
    printf("Digite o nome do arquivo: ");
    scanf("%s", caminhoParaArquivo);
    caminhoParaArquivo = (char*) realloc(caminhoParaArquivo, strlen(caminhoParaArquivo));

    // Le tamanho do vetor com padrao numerico - VERIFICADO
    FILE* arquivo = fopen(caminhoParaArquivo, "r");
    int tamanhoDoVetor = 0;
    fscanf(arquivo, "%d", &tamanhoDoVetor);

    // Le sequencia de elementos - VERIFICADO
    int* sequenciaNumerica = (int*) malloc(tamanhoDoVetor * sizeof(int));
    for(int i = 0; i < tamanhoDoVetor; i++){
        fscanf(arquivo, "%d", &sequenciaNumerica[i]);
    }
    fclose(arquivo);

    // Busca por padrao - VERIFICADO
    int padraoBuscado[5] = {1, 3, 2, 3, 1};
    bool padraoEncontrado = false;
    for(int i = 0; i < tamanhoDoVetor - 5; i++){
        if(sequenciaNumerica[i] == padraoBuscado[0]){
            for(int j = 1, iAux = i+1; j < 5; j++, iAux++){
                if(sequenciaNumerica[iAux] != padraoBuscado[j]){
                    break;
                }else if(j == 4){
                    padraoEncontrado = true;
                }
            }
        }
    }

    // Imprime resultado da busca - VERIFICADO
    if(padraoEncontrado){
        printf("Resultado: Padrao encontrado.");
    }else{
        printf("Resultado: Padrao nao encontrado.");
    }
    
    return 0;
}