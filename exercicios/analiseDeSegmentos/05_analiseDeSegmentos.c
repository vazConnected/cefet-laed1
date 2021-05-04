/**
 * Autor: Pedro Vaz
 * Disciplina Laboratorio de Algoritmos e Estruturas de Dados I (LAED I)
 * 
 * Prazo para a entrega: 05/03/2021 25:55:55
 * Plataforma: run.codes
 * 
 * Titulo: Analise de segmentos com elementos iguais
 * Descricao: ler um arquivo contendo uma sequencia de inteiros, identificar
 *   segmentos de repeticao e atribuir um ID baseado no conteudo desse segmento
 *   (IDs atribuidos em ordem crescente do valor do elemento do segmento).
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(){

    // Entrada do nome do arquivo - VERIFICADO
    char* caminhoParaArquivo = (char*) malloc(1024 * sizeof(char));
    printf("Digite o nome do arquivo: ");
    scanf("%s", caminhoParaArquivo);
    caminhoParaArquivo = (char*) realloc(caminhoParaArquivo, strlen(caminhoParaArquivo));

    // Salvar sequencia de numeros do arquivo para um vetor de int - VERIFICADO
    int* sequenciaNoArquivo = (int*) malloc(sizeof(int));
    int qtdDeElementos = 0, numeroAtual;

    FILE* arquivo = fopen(caminhoParaArquivo, "r");
    while(!feof(arquivo)){
        qtdDeElementos++;
        sequenciaNoArquivo = (int*) realloc(sequenciaNoArquivo, sizeof(int*) * qtdDeElementos);
        fscanf(arquivo, "%d", &numeroAtual);
        sequenciaNoArquivo[qtdDeElementos - 1] = numeroAtual;
    }
    fclose(arquivo);

    // Identifica a quantidade de segmentos na sequencia - VERIFICADO
    int qtdSegmentos = 1;
    for(int i = 1; i < qtdDeElementos; i++){
        if(sequenciaNoArquivo[i-1] != sequenciaNoArquivo[i]){
            qtdSegmentos++;
        }
    }

    // Aloca matriz de segmentos - VERIFICADO
    int** matrizSegmentoValor = (int**) malloc(2 * sizeof(int*));
    matrizSegmentoValor[0] = (int*) calloc(qtdSegmentos, sizeof(int));
    matrizSegmentoValor[1] = (int*) calloc(qtdSegmentos, sizeof(int));
    
    // Preenche matriz de segmentos sem definir ID - VERIFICADO
    matrizSegmentoValor[0][0] = sequenciaNoArquivo[0];
    matrizSegmentoValor[1][0] = 1;
    int segmentosRegistradosNaMatriz = 1;
    for(int i = 1; i < qtdDeElementos; i++){
        if(sequenciaNoArquivo[i] == sequenciaNoArquivo[i - 1]){
            matrizSegmentoValor[1][segmentosRegistradosNaMatriz - 1]++;
        }else{
            matrizSegmentoValor[0][segmentosRegistradosNaMatriz] = sequenciaNoArquivo[i];
            matrizSegmentoValor[1][segmentosRegistradosNaMatriz] = 1;
            segmentosRegistradosNaMatriz++;
        }
    }
    // matrizSegmentoValor[1][segmentosRegistradosNaMatriz - 1]--; // Fix: erro de leitura do runCodes

    // Vetor com elementos sem repeticoes - VERIFICADO
    int* elementosSingulares = (int*) malloc(qtdSegmentos * sizeof(int));
    elementosSingulares[0] = matrizSegmentoValor[0][0];
    int tamanhoVetorElementosSingulares = 1;
    for(int i = 1; i < qtdSegmentos; i++){
        bool semRepeticoes = true;
        for(int j = 0; j < tamanhoVetorElementosSingulares; j++){
            if(matrizSegmentoValor[0][i] == elementosSingulares[j]){
                semRepeticoes = false;
                break;
            }
        }
        if(semRepeticoes){
            elementosSingulares[tamanhoVetorElementosSingulares] = matrizSegmentoValor[0][i];
            tamanhoVetorElementosSingulares++;
        }
    }
    elementosSingulares = (int*) realloc(elementosSingulares, tamanhoVetorElementosSingulares);
    
    // Ordena numeros no vetor sem repeticoes - VERIFICADO
    for(int i = 0; i < tamanhoVetorElementosSingulares - 1; i++){
        for(int j = i + 1; j < tamanhoVetorElementosSingulares; j++){
            if(elementosSingulares[i] > elementosSingulares[j]){
                int temporario = elementosSingulares[i];
                elementosSingulares[i] = elementosSingulares[j];
                elementosSingulares[j] = temporario;
            }
        }
    }

    // Atribui ID aos segmentos - VERIFICADO
    for(int contMatriz = 0; contMatriz < segmentosRegistradosNaMatriz; contMatriz++){
        for(int contElemSingulares = 0; contElemSingulares < tamanhoVetorElementosSingulares; contElemSingulares++){
            if(matrizSegmentoValor[0][contMatriz] == elementosSingulares[contElemSingulares]){
                matrizSegmentoValor[0][contMatriz] = contElemSingulares + 1;
                break;
            }
        }
    }
    
    // Imprime matriz de segmentos - VERIFICADO
    printf("Matriz:");
    for(int i = 0; i < 2; i++){
        printf("\n");
        for(int j = 0; j < qtdSegmentos; j++){
            printf("%d ", matrizSegmentoValor[i][j]);
        }
    }

    return 0;
}