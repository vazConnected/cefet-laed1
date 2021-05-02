/**
 * Autores: Pedro Vaz e Ana Julia Velasque
 * Disciplina Laboratorio de Algoritmos e Estruturas de Dados I (LAED I)
 * 
 * Prazo para a entrega: 26/03/2021 25:55:55
 * Plataforma: run.codes
 * 
 * Titulo: Projeto (Parte 2) - Busca por faixa de pedestres
 * Descricao: ler um arquivo e buscar por um padrão numérico que remete a uma faixa de pedestres.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

    // Definicao do caminho para o arquivo com a sequencia
    char caminhoParaArquivo[30];
    printf("Digite o nome do arquivo: ");
    scanf("%s", caminhoParaArquivo);

    // Abertura e teste do arquivo
    FILE *arquivo;
    arquivo = fopen(caminhoParaArquivo, "r");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!");
        return 1;
    }

    // Descobrindo a quantidade de elementos na sequencia
    int qtdDeNumerosNoArquivo = 0;
    fscanf(arquivo, "%d", &qtdDeNumerosNoArquivo);

    // Armazenando os valores do arquivo na memoria
    int elementosDoArquivo[qtdDeNumerosNoArquivo + 1], auxElementosDoArquivo[qtdDeNumerosNoArquivo + 1];
    for(int i = 0; i < qtdDeNumerosNoArquivo; i++){
        fscanf(arquivo, "%d", &elementosDoArquivo[i]);
        auxElementosDoArquivo[i] = elementosDoArquivo[i];
    }
    fclose(arquivo);

    // Descobrindo a quantidade de sequencias 
    int qtdDeSequencias = 0;
    for(int i = 0, skip = 1; i < qtdDeNumerosNoArquivo; i += skip){
        skip = 1;
        for(int j = i + 1; j < qtdDeNumerosNoArquivo; j++){
            if(elementosDoArquivo[j] == elementosDoArquivo[i]){
                skip++;
            }else{
                qtdDeSequencias++;
                break;
            }
        }
    }
    qtdDeSequencias++; // conserta erro de leitura do runCodes

    // Alocacao dinamica da vetor com as sequencias
    int *vetorSequencia = (int*) malloc(qtdDeSequencias * sizeof(int));

    // Descobrindo numeros repetidos (de sequencia) e substituindo por -1
    for(int i = 0; i < qtdDeNumerosNoArquivo + 1; i++){
        for(int j = 0; j < qtdDeNumerosNoArquivo + 1; j++){
            if(i != j && auxElementosDoArquivo[i] == auxElementosDoArquivo[j]){
                auxElementosDoArquivo[i] = -1;
            }
        }
    }

    // Ordenando o vetor auxiliar de elementos do arquivo
    for(int i = 0; i < qtdDeNumerosNoArquivo + 1; i++){
        for(int j = 0; j < qtdDeNumerosNoArquivo + 1; j++){
            if(auxElementosDoArquivo[i] < auxElementosDoArquivo[j]){
                int aux = auxElementosDoArquivo[i];
                auxElementosDoArquivo[i] = auxElementosDoArquivo[j];
                auxElementosDoArquivo[j] = aux;
            }
        }
    }

    // Definicao dos valores fixados pelo enunciado do exercicio
    int teste[6] = {0, 1, 128, 2, 255, 3};

    // Armazenando os identificadores das sequencias no vetorSequencias
    int indiceVetorTeste = 0, indiceVetorSequencia = 0;
    for(int i = 0, skip = 1; i < qtdDeNumerosNoArquivo + 1; i += skip){
        int indiceVetorTeste = 0;
        skip = 1;
        
        for(int j = i + 1; j < qtdDeNumerosNoArquivo + 1; j++){
            if(elementosDoArquivo[j] == elementosDoArquivo[i]){
                skip++;
            }else{
                break;
            }
        }

        for(int k = 0; k < 6; k += 2){
            if(elementosDoArquivo[i] == teste[k]){
                indiceVetorTeste++;
                vetorSequencia[indiceVetorSequencia] = teste[indiceVetorTeste];
                indiceVetorSequencia++;
                indiceVetorTeste++;
            }
            indiceVetorTeste += 2;
        }
    }

    // Busca pelo padrao da faixa de pedestres
    int padraoBuscado[13] = {1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1}; // faixa de pedestres
    bool padraoEncontrado = false;
    for(int i = 0; i < qtdDeSequencias; i++){
        if(vetorSequencia[i] == padraoBuscado[0]){
            for(int j = 1, iAux = i + 1; j < 13; j++, iAux++){
                if(vetorSequencia[iAux] != padraoBuscado[j]){
                    break;
                }else if(j == 12){
                    padraoEncontrado = true;
                }
            }
        }
    }

    // Imprime resultado da busca
    if(padraoEncontrado){
        printf("Resultado: Padrao de faixa de pedestres encontrado.");
    }
    else{
        printf("Resultado: Padrao de faixa de pedestres nao encontrado.");
    }

    return 0;
}