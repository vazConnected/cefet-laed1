# Laboratório de Algoritmos e Estruturas de Dados 1

## Descrição do exercício "Problema da Mochila"

<p>Imagine que você acaba de ganhar um concurso cujo prêmio é escolher n itens quaisquer
em uma loja. O i-ésimo item tem valor vi reais e pesa wi quilos (vi, wi ∈ ℝ). Você poderá levar
tudo o que quiser, desde que os itens escolhidos caibam em uma mochila que pode carregar até W
quilos.</p>

<p>O objetivo é determinar o conjunto de itens que você deve pegar de forma que consiga
carregá-los todos dentro da mochila e o valor total dos itens seja maximizado.</p>

<p>Este problema é conhecido como o problema da mochila e tem inúmeras aplicações
práticas.</p>

<p>O exercício consiste na implementação de um algoritmo para verificar se uma
determinada solução apresentada na entrada é uma solução ótima, viável ou inviável para o
problema da mochila com os parâmetros fornecidos (capacidade da mochila, peso e valor dos
itens).</p>

<p>Por exemplo, suponha uma mochila com capacidade de 10 Kg e os seguintes objetos:</p>

| Peso(Kg) | Valor(R$) |
|:--------:|:---------:|
| 1 | 20 |
| 2 |  5 |
| 3 | 10 |
| 8 | 40 |
| 7 | 15 |
| 4 | 25 |

<p>Este problema possui mais de uma solução ótima, que são equivalentes:</p>

- Solução 1: valor total igual a R$ 60
  - Soma dos valores: R$ 20 + R$ 40 = R$ 60
  - Soma dos pesos: 1 Kg + 8 Kg = 9 Kg

- Solução 2: valor total igual a R$ 60
  - Soma dos valores: R$ 20 + R$ 25 + R$ 10 + R$ 5 = R$ 60 
  - Soma dos pesos: 1 Kg + 4 Kg + 3 Kg + 2 Kg = 10 Kg

<p>Há também outras soluções que são viáveis em termos de peso total, mas não são ótimas,
por exemplo:</p>

- Solução 3: valor total igual a R$ 45
  - Soma dos valores: R$ 40 + R$ 5 = R$ 45
  - Soma dos pesos: 8 Kg + 2 Kg = 10 Kg

<p>E há soluções inviáveis, cujo peso ultrapassa a capacidade total da mochila, por exemplo:</p>

- Solução 4: valor total igual a R$ 65
  - Soma dos valores: R$ 40 + R$ 25 = R$ 65
  - Soma dos pesos: 8 Kg + 4 Kg = 11 Kg

<h3>Formato de entrada dos dados<h3>

<p>A entrada do programa é um arquivo texto cujo nome deverá ser solicitado, conforme modelo a seguir:</p>

<pre><code><p>Digite o nome do arquivo: </p></code></pre>

- O arquivo texto deverá conter as informações sobre os n itens da loja, nesta ordem:
  -  na primeira linha: W (capacidade da mochila);
  -  na segunda linha: n (número de itens);
  -  nas n linhas seguintes: peso e valor dos itens, separados por um espaço em branco, cada um em uma linha;
  -  nas n linhas seguintes: a solução a ser verificada (1 para item escolhido, 0 para item ausente na mochila).

<p>Todos valores são números inteiros. Veja a seguir um exemplo de arquivo de entrada, que corresponde à Solução 1 citada anteriormente:</p>

<pre><code><p>10</p><p>6</p><p>1 20</p><p>2 5</p><p>3 10</p><p>8 40</p><p>7 15</p><p>4 25</p><p>1</p><p>0</p><p>0</p><p>1</p><p>0</p><p>0</p></code></pre>

<h3>Formato de saída dos dados</h3>

<p>O programa deverá produzir a impressão de uma mensagem na tela conforme o resultado da verificação, de acordo com o seguinte modelo (não utilize acentuação nem cedilha na saída para este exercício):</p>

<pre><code><p>Solucao otima.</p></code></pre>

<p>Ou:</p>

<pre><code><p>Solucao viavel mas nao otima.</p></code></pre>

<p>Ou:</p>

<pre><code><p>Solucao inviavel.</p></code></pre>
