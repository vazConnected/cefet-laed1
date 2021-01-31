/**
 * Autor: Pedro Vaz
 * Disciplina Laboratorio de Algoritmos e Estruturas de Dados I (LAED I)
 * 
 * Prazo para a entrega: 21/01/2021 25:55:55
 * Plataforma: run.codes
 * 
 * Titulo: Decimal para Binario
 * Descricao: O programa le um numero inteiro em decimal e, recursivamente, exibe seu binario correspondente
 * 
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void dec2bin(int dec){
    if(dec == 0 || dec < 0){
        printf("0");
        return;
    }

    // Descobrir a potencia de dois adequada para gerar o 1o digito do numero
    int potenciaDeDois = 0;
    while( true ){
        if( dec < pow(2, potenciaDeDois + 1) && dec >= pow(2, potenciaDeDois)){
            break;
        }

        potenciaDeDois++;
    }

    bool ultimoDigitoEhZero = false;

    for( ; potenciaDeDois >= 0; potenciaDeDois--){

        if( dec < pow(2, potenciaDeDois + 1) && dec >= pow(2, potenciaDeDois)){
            
            if(ultimoDigitoEhZero){
                dec2bin(dec);
                break;
            }else{
                printf("1");
                ultimoDigitoEhZero = false;

                dec -= pow(2, potenciaDeDois);
            }

        }else{
            printf("0");
            ultimoDigitoEhZero = true;
        }
    }
}

int main(){
    printf("Digite um numero inteiro: ");
    int numeroInteiro = 0;
    scanf("%d", &numeroInteiro);

    printf("Resultado: ");
    dec2bin(numeroInteiro);

    return 0;
}