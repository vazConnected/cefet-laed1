# Laboratório de Algoritmos e Estruturas de Dados 1

## Descrição do exercício "Análise de Segmentos"
<p>Para este problema, considere um vetor com N elementos inteiros, por exemplo:</p>

```
0 0 0 128 128 0 0 255 255 255 255
```

<p>Podemos agrupar os valores iguais em segmentos, como mostra a figura a seguir:</p>

<!-- imagens aqui !-->

<p>O segmento será classificado conforme o valor dos seus elementos, fazendo-se um mapeamento dos valores em ordem crescente para os números positivos. No exemplo anterior, o mapeamento seria:</p>

```
0   -> 1
128 -> 2
255 -> 3
```

<p>Resultando na seguinte classificação dos segmentos do vetor:</p>

<!-- imagens aqui !-->

<p>Nesse exemplo, N=11. Observe que a soma total do número de elementos deve ser igual a N.</p>

<p>O objetivo do programa será produzir uma matriz com 2 linhas e K colunas, <u>alocada dinamicamente</u>, de forma que a primeira linha contenha informações sobre o tipo dos segmentos e a segunda linha contenha o número de elementos do respectivo segmento, na ordem em que aparecem no vetor.</p>

<p>No exemplo deste problema, o número K = 4 e a matriz possui os seguintes valores:</p>

<!-- imagens aqui !-->

<p>Os elementos do vetor serão fornecidos em um arquivo texto com o seguinte formato: na primeira linha o valor de N e na linha seguinte os N valores dos elementos do vetor separados por um espaço em branco.</p>

<p>A saída deverá seguir o modelo abaixo:</p>

```
Digite o nome do arquivo: teste.txt
Matriz:
1 2 1 3
3 2 2 4
```

<p>Observações Importantes:</p>

- Todos os valores fornecidos no arquivo são números inteiros;
- Para os testes, considere quaisquer valores de N, de K, dos elementos do vetor e do total de elementos em cada segmento;
- O exercício é individual e deve apresentar uma solução original.