/**
 * Autores: Pedro Vaz e Ana Julia Velasque
 * Disciplina Laboratorio de Algoritmos e Estruturas de Dados I (LAED I)
 * 
 * Prazo para a entrega: 08/04/2021 25:55:55
 * Plataforma: run.codes
 * 
 * Titulo: Projeto (Parte 3) - Busca por faixa de pedestres em uma imagem
 * Descricao: ler um arquivo que contem faixas horizontais simulando pixels de uma 
 *   imagem por linha e buscar a existencia de uma faixa de pedestres linha a linha
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/* *********************************************************************
 * Como requisito do enunciado, a implementacao da fila do livro-texto
 * do Ziviani sera utilizada. Comentarios foram feitos para indicar a
 * funcao a utilizacao da lista para esse projeto e algumas falhas ou
 * melhorias que poderiam ser feitas na lista caso a modificacao dessa
 * secao do codigo dosse permiitida.
 *
 * Codigo fonte: http://www2.dcc.ufmg.br/livros/algoritmos/implementacoes-03.php
 * *********************************************************************/

typedef struct TipoCelula *TipoApontador;

typedef struct TipoItem{
    int* sequencia; // Sequencia de segmentos encontrados em uma linha (pode haver mais de um item com a mesma chave)
    bool faixaDePedestresEncontrada;
} TipoItem;

typedef struct TipoCelula{
    TipoItem Item;
    TipoApontador Prox;
} TipoCelula;

typedef struct TipoFila{
    TipoApontador Frente, Tras;
} TipoFila;

/**
 * FFVazia: faz fila vazia
 *   - Ese procedimento nao esvazia a fila como deveria e tem funcao de
 * construtor. Nao e possivel utiliza para uma flia com itens inclusos 
 * porque a memoria dos itens associados nao e liberada
*/
void FFVazia(TipoFila *Fila){
    Fila->Frente = (TipoApontador) malloc(sizeof(TipoCelula));
    Fila->Tras = Fila->Frente;
    Fila->Frente->Prox = NULL;
} 

// Verifica se a fila esta vazia
int Vazia(TipoFila Fila){
    return (Fila.Frente == Fila.Tras); 
} 

void Enfileira(TipoItem x, TipoFila *Fila){
    Fila->Tras->Prox = (TipoApontador) malloc(sizeof(TipoCelula));
    Fila->Tras = Fila->Tras->Prox;
    Fila->Tras->Item = x;
    Fila->Tras->Prox = NULL;
} 

void Desenfileira(TipoFila *Fila, TipoItem *Item){
    TipoApontador q;
    if(Vazia(*Fila)){
        printf("Erro fila esta vazia\n"); 
        return;
    }
    q = Fila->Frente;
    Fila->Frente = Fila->Frente->Prox;
    *Item = Fila->Frente->Item;
    free(q);
} 

/**********************************************************************/

int main(){
    
    // Criando fila
    TipoFila filaDePadroes;
    FFVazia(&filaDePadroes);

    // Entrada para o nome do arquivo
    char nomeDoArquivo[30];
    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeDoArquivo);

    // Abertura do arquivo
    FILE *pont_arq;
    pont_arq = fopen(nomeDoArquivo, "r");
    if(pont_arq == NULL){
        printf("Erro ao abrir o arquivo!");\
        return 0;
    }

    // Descobrindo a quantidade de sequencias a serem analisadas
    int qtdDeSequencias = 0;
    fscanf(pont_arq,"%d", &qtdDeSequencias); // Quantidade sequencias que vamos avaliar no arquivo
    
    // Analise dos padroes das sequencias
    int *sequenciaAtual = (int*) malloc(1 * sizeof(int));
    for(int contadorDeSequencias = 0; contadorDeSequencias < qtdDeSequencias; contadorDeSequencias++){
        
        // Descobre quantos numeros ha na sequencia atual de caracteres
        int qtdNumerosSequenciaAtual = 0;
        fscanf(pont_arq,"%d", &qtdNumerosSequenciaAtual); // Quantidade de numeros da sequencia a ser analisada

        // Definindo vetor para armazenarmos as sequencias
        sequenciaAtual = (int*) realloc(sequenciaAtual, qtdNumerosSequenciaAtual*sizeof(int));
        for(int i = 0; i < qtdNumerosSequenciaAtual; i++){
            fscanf(pont_arq,"%d", &sequenciaAtual[i]);
        }

        // Encontrando a quantidade de segmentos na sequencia
        int qtdSegmentosNaSequenciaAtual = 0;
        for(int i = 0, skip = 1; i < qtdNumerosSequenciaAtual; i = i + skip){
            skip = 1;
            for(int j = i + 1; j < qtdNumerosSequenciaAtual; j++){
                if(sequenciaAtual[j] == sequenciaAtual[i]){
                    skip++;
                }
                if(sequenciaAtual[j] != sequenciaAtual[i]){
                    qtdSegmentosNaSequenciaAtual++;
                    break;
                }
            }
        }
        //qtdSegmentosNaSequenciaAtual++; // corrige erro de leitura do run.codes

        // Alocacao dinamica da vetor com os segmentos
        int *vetorDeSegmentos = (int*) malloc(qtdSegmentosNaSequenciaAtual * sizeof(int));

        int teste[6] = {0, 1, 128, 2, 255, 3}; // criando um vetor teste para realizar a comparação intercalando numero e seg. referente

        // Armazenando sequencia encontrada no vetorDeSegmentos
        int contadorVetorTeste = 0;
        for(int i = 0, contadorVetorSegmentos = 0, skip = 0; i < qtdNumerosSequenciaAtual + 1; i += skip){ 
            skip = 1;
            contadorVetorTeste = 0;

            for(int j = i + 1; j < qtdNumerosSequenciaAtual + 1; j++){
                if(sequenciaAtual[j] == sequenciaAtual[i]){
                    skip++;
                }else{
                    break;
                }
            }

            for(int k = 0; k < 6; k += 2){
                if(sequenciaAtual[i] == teste[k]){
                    contadorVetorTeste++;

                    vetorDeSegmentos[contadorVetorSegmentos] = teste[contadorVetorTeste];

                    contadorVetorSegmentos++;
                    contadorVetorTeste++;
                }
                contadorVetorTeste += 2;
            }
        }

        // Cria TipoItem e copia a sequencia encontrada
        TipoItem itemSequenciaAtual;
        itemSequenciaAtual.sequencia = (int*) malloc(qtdSegmentosNaSequenciaAtual * sizeof(int));
        for(int indiceParaCopia = 0; indiceParaCopia < qtdSegmentosNaSequenciaAtual; indiceParaCopia++){
            itemSequenciaAtual.sequencia[indiceParaCopia] = vetorDeSegmentos[indiceParaCopia];
        }

        // Identifica se o padrao da faixa de pedestres foi encontrado e armazena resultado no TipoItem
        int padraoBuscado[13] = {1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1};
        itemSequenciaAtual.faixaDePedestresEncontrada = false;
        for(int i = 0; i < qtdSegmentosNaSequenciaAtual ; i++){
            if(itemSequenciaAtual.sequencia[i] == padraoBuscado[0]){
                for(int j = 1, iAux = i + 1; j < 13; j++, iAux++){
                    if(itemSequenciaAtual.sequencia[iAux] != padraoBuscado[j]){
                        break;
                    }else if(j == 12){
                        itemSequenciaAtual.faixaDePedestresEncontrada = true;
                        break;
                    }
                }
            }
        }

        // Enfileirando numero identificador da sequencia atual
        Enfileira(itemSequenciaAtual, &filaDePadroes);
    }
    fclose(pont_arq);

    // Busca padrao da faixa de pedestres na fila
    while(!Vazia(filaDePadroes)){ // Desenfileira enquanto a fila nao esta vazia
        TipoItem itemDesenfileirado;
        Desenfileira(&filaDePadroes, &itemDesenfileirado);

        if(itemDesenfileirado.faixaDePedestresEncontrada){
            printf("Resultado: Pista com faixa de pedestres");
            return 0;
        }
    }

    // Caso o padrao da faixa de pedestres nao tenha sido encontrado em nenhum dos elementos da fila
    printf("Resultado: Pista sem faixa de pedestres");
    
    return 0;
}