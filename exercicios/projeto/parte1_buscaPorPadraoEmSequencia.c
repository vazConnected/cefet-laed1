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
#include <stdbool.h>

int main(){

    // Entrada para o arquivo
    char caminhoParaArquivo[30];
    printf("Digite o nome do arquivo: ");
    scanf("%s", caminhoParaArquivo);

    // Verificacao da entrada para o arquivo
    FILE *ponteiroArquivo = fopen(caminhoParaArquivo, "r");
    if(ponteiroArquivo == NULL){
        printf("Erro ao abrir o arquivo!");
        return 0;
    }

    // Descobre quantidade de elementos e aloca memória de arrays
    int qtdElementos;
    fscanf(ponteiroArquivo,"%d", &qtdElementos);
    int vetor[qtdElementos+1], vetorAux[qtdElementos+1], recebe;

    // Salva elementos do arquivo na memoria
    for(int i = 0; i < qtdElementos; i++){
        fscanf(ponteiroArquivo,"%d", &recebe);
        vetor[i] = recebe;
        vetorAux[i] = recebe;
    }
    fclose(ponteiroArquivo);

    // Descobre quantidade de colunas
    int colunas = 0;
    for(int i = 0, skip = 1; i < qtdElementos; i += skip){
        skip = 1;
        for(int j = i + 1; j < qtdElementos; j++){
            if(vetor[j] == vetor[i]){
                skip++;
            }else{
                skip++;
                break;
            }
        }
    }
    // colunas++; // Corrige erro de leitura do runCodes
    
    // Alocacao dinamica da matriz
    int **matriz = (int**) malloc(2 * sizeof(int*));
    matriz[0] = (int*) malloc(colunas * sizeof(int));
    matriz[1] = (int*) malloc(colunas * sizeof(int));
    
    // Mapeia vetor auxiliar - numeros repetidos são sobrescritos com -1
    for(int i = 0; i < qtdElementos + 1; i++){
		for(int j = 0; j < qtdElementos + 1; j++){
		    if( (i != j) &&  (vetorAux[i] == vetorAux[j]) ){
				vetorAux[i]--;
			}
		}
	}

    // Ordenana vetor auxiliar
    for (int i = 0; i < qtdElementos+1; i++){
        for (int j = 0; j < qtdElementos+1; j++){
            if (vetorAux[i] < vetorAux[j]){
                int tmpVetorAux = vetorAux[i];
                vetorAux[i] = vetorAux[j];
                vetorAux[j] = tmpVetorAux;
            }
        }
    }

    // Descobre a quantidade de segmentos e ordenana-os em forma crescente
    int teste[1000], tamanhoVetorTeste = 0; 
    for(int i = 0, indiceVetorTeste = 0, segmento = 0; i < qtdElementos+1; i++){
        if(vetorAux[i] != -1){
            segmento++;

            teste[indiceVetorTeste] = vetorAux[i];
            tamanhoVetorTeste++;
            indiceVetorTeste++;

            teste[indiceVetorTeste] = segmento;
            indiceVetorTeste++;
            tamanhoVetorTeste++;
        }
    }

    // Descobre a quantiadade de elementos repetidos por sequencia
    int contadorColuna = 0, somatorioElementos;
    for(int i = 0; i < qtdElementos + 1; i += somatorioElementos){
        somatorioElementos = 1;
        for(int j = i + 1; j < qtdElementos + 1; j++){
            if(vetor[j] == vetor[i]){
                somatorioElementos++;
            }else{
                matriz[1][contadorColuna] = somatorioElementos;
                contadorColuna++;
                break;
            }
        }
    }
    // matriz[1][contadorColuna] = somatorioElementos - 1; // Corrige erro de leitura do runCodes

    for(int i = 0, skip = 0, coluna = 0; i < qtdElementos + 1; i += skip){ 
        int indiceVetorTeste = 0;
        skip = 1;
        
        for(int j = i + 1; j < qtdElementos + 1; j++){
            if(vetor[j] == vetor[i]){
                skip++;
            }else{ // transicao encontrada
                break;
            }
        }

        for(int k = 0; k < tamanhoVetorTeste; k += 2){
            if(vetor[i] == teste[k]){
                indiceVetorTeste++;
                matriz[0][coluna] = teste[indiceVetorTeste];
                coluna++;
                indiceVetorTeste++;
            }
            indiceVetorTeste += 2;
        }
    }
    
    // Verifica se o padrão buscado foi encontrado
    int padraoBuscado[5] = {1, 3, 2, 3, 1};
    bool padraoEncontrado = false;
    for(int i = 0; i < colunas ; i++){
        if(matriz[0][i] == padraoBuscado[0]){
            for(int j = 1, iAux = i+1; j < 5; j++, iAux++){
                if(matriz[0][iAux] != padraoBuscado[j]){
                    break;
                }else if(j == 4){
                    padraoEncontrado = true;
                }
            }
        }
    }

    // Imprime resultado da busca
    if(padraoEncontrado){
        printf("Resultado: Padrao encontrado.");
    }else{
        printf("Resultado: Padrao nao encontrado.");
    }
    
    return 0;
}