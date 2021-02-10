/**
 * Autor: Pedro Vaz
 * Disciplina Laboratorio de Algoritmos e Estruturas de Dados I (LAED I)
 * 
 * Prazo para a entrega: 12/02/2021 25:55:55
 * Plataforma: run.codes
 * 
 * Titulo: Criptografia
 * Descricao: recebe um arquivo texto com a mensagem criptografada e imprime a traducao
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

void imprimirMensagem(char* stringCodificada, char* stringDecodificada, int tamanhoStringCod, int tamanhoStringDecod){
    printf("\n--------------------");
    printf("\nMensagem codificada:");
    printf("\n--------------------\n");

    for(int i = 0; i < tamanhoStringCod; i++){
        printf("%c", stringCodificada[i]);
    }

    printf("\n\n----------------------");
    printf("\nMensagem decodificada:");
    printf("\n----------------------\n");

    for(int i = 0; i < tamanhoStringDecod; i++){
        printf("%c", stringDecodificada[i]);
    }
}

char* permutarBlocos(char* string, int tamanhoDaString){
    int meiaString = tamanhoDaString / 2;
    char* stringPermutada = (char*) malloc(tamanhoDaString * sizeof(char));

    bool permutar = true;
    int i = 0, j = tamanhoDaString - 2;
    int contadorCopia = 0;
    for( ; i < meiaString && j >= meiaString; i += 2, j-=2, contadorCopia += 2){
        if(permutar){
            stringPermutada[i]   = string[j];
            stringPermutada[i+1] = string[j+1];
            stringPermutada[j]   = string[i];
            stringPermutada[j+1] = string[i+1]; 
        }else{
            stringPermutada[i]     = string[i];
            stringPermutada[i + 1] = string[i + 1];
            stringPermutada[j]     = string[j];
            stringPermutada[j + 1] = string[j + 1];
        }
        permutar = !permutar;
    }

    if(meiaString % 2 != 0){
        stringPermutada[meiaString - 1] = string[meiaString -1];
        stringPermutada[meiaString]     = string[meiaString];
    }
 
    return stringPermutada;
}

void cifraDeCesar5Direita(char* string, int tamanhoString){
    for(int i = 0; i < tamanhoString; i++){
        if(string[i] != ' '){
            if(string[i] >= 97 && string[i] <= 122){
                int marcacaoDeChar = string[i] - 5;
                if(marcacaoDeChar < 97){
                    marcacaoDeChar = 123 - abs(97 - marcacaoDeChar);
                }
                string[i] = marcacaoDeChar;
            }else if(string[i] >= 65 && string[i] <= 90){
                int marcacaoDeChar = string[i] - 5;
                if(marcacaoDeChar < 65){
                    marcacaoDeChar = 91 - abs(65 - marcacaoDeChar);
                }
                string[i] = marcacaoDeChar;
            }
        }
    }
}

int main(){
    char* caminhoParaArquivo = (char*) malloc(4096 * sizeof(char));
    
    // Entrada do nome do arquivo - VERIFICADO
    printf("Digite o nome do arquivo: ");
    scanf("%s", caminhoParaArquivo);
    caminhoParaArquivo = (char*) realloc(caminhoParaArquivo, strlen(caminhoParaArquivo));
    FILE *arquivo = fopen(caminhoParaArquivo, "r");

    if(arquivo == NULL){
        imprimirMensagem("", "", 0, 0);
        return 1;
    }

    // Capturar string codificada do arquivo - VERIFICADO
    char* stringCodificada = (char*) malloc(sizeof(char));
    int tamanhoStringCod = 0;
    char charCapturado = fgetc(arquivo);
    while(charCapturado != EOF){
        tamanhoStringCod++;
        stringCodificada = (char*) realloc(stringCodificada, tamanhoStringCod);
        stringCodificada[tamanhoStringCod - 1] = charCapturado;
        charCapturado = fgetc(arquivo);
    }

    fclose(arquivo);

    // 1a etapa de decodificacao - VERIFICADO
    char* stringDecodificada = permutarBlocos(stringCodificada, tamanhoStringCod);

    // 2a etapa de decodificacao - VERIFICADO
    for(int i = 0; i < tamanhoStringCod; i += 2){
        char aux = stringDecodificada[i];
        stringDecodificada[i] = stringDecodificada [i + 1];
        stringDecodificada[i + 1] = aux;
    }

    // 3a etapa de decodificacao - VERIFICADO
    int tamanhoStringDecod = tamanhoStringCod;
    for(int i = tamanhoStringCod - 1; stringDecodificada[i] == '#'; i--){
        tamanhoStringDecod--;
        stringDecodificada = (char*) realloc(stringDecodificada, tamanhoStringDecod);
    }
    for(int i = 0; i < tamanhoStringDecod; i++){
        if(stringDecodificada[i] == '#'){
            stringDecodificada[i] = ' ';
        }
    }

    // 4a etapa de decodificacao
    cifraDeCesar5Direita(stringDecodificada, tamanhoStringDecod);

    imprimirMensagem(stringCodificada, stringDecodificada, tamanhoStringCod, tamanhoStringDecod);
    
    return 0;
}