# Laboratório de Algoritmos e Estruturas de Dados 1

## Descrição do exercício "Jogo das Caixas"

<p>Este jogo consiste de uma pilha de caixas de determinado valor em que cada fileira contém uma caixa a mais que a fileira anterior. O competidor deve escolher uma caixa e seu prêmio será a soma dos valores da caixa escolhida mais os valores de todas as caixas das fileiras acima dela, ou seja, todas as caixas das fileiras acima serão incluídas no cálculo também, sejam positivas ou negativas. Se o competidor fizer uma escolha ruim, o valor poderá ser negativo e não haverá prêmio.</p>

<!-- imagens aqui !-->

<p>Por exemplo, para a seguinte configuração de caixas, a segunda caixa da terceira fileira deverá ser escolhida para obter o maior prêmio, cujo valor é igual a 17.</p>

<p>Para este exercício, o programa deverá determinar qual caixa deverá ser escolhida para maximizar o valor do prêmio.</p>

<p>Os valores das caixas serão fornecidos em um arquivo cujo formato segue a seguinte descrição: na primeira linha, há um número inteiro N representando o número de fileiras da pilha de caixas. As linhas seguintes contêm, cada uma, os valores das caixas de cada fileira separados por espaços. A primeira fileira é a mais ao topo e, em cada fileira, a primeira caixa é a mais à esquerda.</p>

<p>Arquivo de entrada:</p>

```
N (altura da pilha de caixas, que é o número de fileiras)
Valores das caixas da primeira fileira separados por espaços
Valores das caixas da segunda fileira separados por espaços
```
<p>O nome do arquivo de entrada deverá ser solicitado pelo programa. A saída do programa deverá seguir o modelo abaixo:</p>

```
Digite o nome do arquivo de entrada: teste.txt
Resposta: fileira 3, caixa 2.
```

<p>Observações importantes:</p>

1. Todos os valores das caixas são números inteiros.
2. Quaisquer valores de N e das caixas podem ser fornecidos.
3. Considere que a altura máxima das pilhas fornecidas nos testes é de 20 caixas.
4. Não utilize acentuação na saída do programa.
5. O exercício é individual e deve apresentar uma solução original.
