/**
 * Autor: Pedro Henrique Estevam Vaz de Melo
 * Disciplina Laboratorio de Algoritmos e Estruturas de Dados I (LAED I)
 * 
 * Prazo para a entrega: 04/02/2021 25:55:55
 * Plataforma: run.codes
 * 
 * Titulo: Jogo das caixas
 * Descricao: descobrir a jogada mais valiosa para o "jogo das caixas"
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

void imprimirResposta(int fileira, int caixa);
int algarismosEmCharParaNumeroInteiro(char* vetorDeAlgarismos, int tamanho);

int main(){
    int fileiraResposta = 1, caixaResposta = 1;

    // Entrada do nome do arquivo - VERIFICADO
    char* caminhoParaArquivo = (char*) malloc(4096 * sizeof(char));
    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", caminhoParaArquivo);
    caminhoParaArquivo = (char*) realloc(caminhoParaArquivo, strlen(caminhoParaArquivo));

    // Verificacao da existencia do arquivo - VERIFICADO
    FILE* arquivo = fopen(caminhoParaArquivo, "r");
    if(arquivo == NULL){
        imprimirResposta(fileiraResposta, caixaResposta);
        return 0;
    }

    // Capturar o altura da pilha - VERIFICADO
    char* vetorCharDeAlgarismos = (char*) malloc(sizeof(char));
    int qtdDeAlgarismos = 0;
    char charCapturado = fgetc(arquivo);
    while(charCapturado != '\n'){
        qtdDeAlgarismos++;
        vetorCharDeAlgarismos = (char*) realloc(vetorCharDeAlgarismos, qtdDeAlgarismos);
        vetorCharDeAlgarismos[qtdDeAlgarismos - 1] = charCapturado;
        charCapturado = fgetc(arquivo);
    }

    // Transformacao de algarismos para numero - VERIFICADO
    int alturaDaPilha = algarismosEmCharParaNumeroInteiro(vetorCharDeAlgarismos, qtdDeAlgarismos);

    // Alocacao de memoria da pilha - VERIFICADO
    int** pilhaDeCaixas = (int**) malloc(alturaDaPilha * sizeof(int*));
    for(int i = 0; i <= alturaDaPilha; i++){
        pilhaDeCaixas[i] = (int*) malloc( (i+1) * sizeof(int));
    }

    // Salvar pilha do arquivo na matriz "pilhaDeCaixas" - VERIFICADO
    for(int i = 0; i < alturaDaPilha; i++){
        for(int j = 0; j <= i; j++){
            fscanf(arquivo, "%d ", &pilhaDeCaixas[i][j]);
        }
    }
    
    fclose(arquivo);
    
    // Atribuindo pontuacao por fileira - VERIFICADO
    int* valorPorFileira = (int*) calloc( alturaDaPilha, sizeof(int));
    for(int fileira = 0; fileira < alturaDaPilha; fileira++){
        for(int caixa = 0; caixa <= fileira; caixa++){
            valorPorFileira[fileira] += pilhaDeCaixas[fileira][caixa];
        }
    }

    // Analisando melhor jogada - VERIFICADO
    int melhorPontuacao = valorPorFileira[0];
    for(int fileira = 1; fileira < alturaDaPilha; fileira++){
        for(int caixa = 0; caixa <= fileira; caixa++){
            int pontuacaoAtual = 0;
            // Somatorio dos valores das fileiras superiores - VERIFICADO
            for(int i = 0; i <= fileira -1; i++){
                pontuacaoAtual += valorPorFileira[i];
            }

            pontuacaoAtual += pilhaDeCaixas[fileira][caixa];
            
            if(pontuacaoAtual > melhorPontuacao){
                melhorPontuacao = pontuacaoAtual;
                fileiraResposta = fileira + 1;
                caixaResposta = caixa + 1;
            }
        }
    }

    imprimirResposta(fileiraResposta, caixaResposta);

    return 0;
}

void imprimirResposta(int fileira, int caixa){
    printf("Resposta: fileira %d, caixa %d.", fileira, caixa);
}

int algarismosEmCharParaNumeroInteiro(char* vetorDeAlgarismos, int tamanho){
    bool numeroNegativo = false;
    int resultado = 0;

    int *algarismos = (int*) malloc(tamanho * sizeof(int));

    int contadorDePosicao = 0;
    for( ; contadorDePosicao <= tamanho; contadorDePosicao++){
        if(vetorDeAlgarismos[contadorDePosicao] == '-'){
            algarismos[contadorDePosicao] = -1;
        }else if(vetorDeAlgarismos[contadorDePosicao] == '0'){
            algarismos[contadorDePosicao] = 0;
        } else if(vetorDeAlgarismos[contadorDePosicao] == '1'){
            algarismos[contadorDePosicao] = 1;
        } else if(vetorDeAlgarismos[contadorDePosicao] == '2'){
            algarismos[contadorDePosicao] = 2;
        } else if(vetorDeAlgarismos[contadorDePosicao] == '3'){
            algarismos[contadorDePosicao] = 3;
        } else if(vetorDeAlgarismos[contadorDePosicao] == '4'){
            algarismos[contadorDePosicao] = 4;
        } else if(vetorDeAlgarismos[contadorDePosicao] == '5'){
            algarismos[contadorDePosicao] = 5;
        } else if(vetorDeAlgarismos[contadorDePosicao] == '6'){
            algarismos[contadorDePosicao] = 6;
        } else if(vetorDeAlgarismos[contadorDePosicao] == '7'){
            algarismos[contadorDePosicao] = 7;
        } else if(vetorDeAlgarismos[contadorDePosicao] == '8'){
            algarismos[contadorDePosicao] = 8;
        } else if(vetorDeAlgarismos[contadorDePosicao] == '9'){
            algarismos[contadorDePosicao] = 9;
        }
    }

    contadorDePosicao = 0;
    for(int potencia = tamanho - 1; contadorDePosicao < tamanho; contadorDePosicao++, potencia--){
        if(algarismos[contadorDePosicao] == -1){
            numeroNegativo = true;
        }else{
            resultado += algarismos[contadorDePosicao] * pow(10, potencia);
        }
    }

    if(numeroNegativo){
        resultado *= (-1);
    }

    return resultado;
}

