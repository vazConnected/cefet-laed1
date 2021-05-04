# Laboratório de Algoritmos e Estruturas de Dados 1

## Descrição dos exercícios da etapa de introdução/revisão da disciplina

<details>
    <summary>Digitos</summary>
    <p>A função a seguir recebe como parâmetro um número inteiro N e retorna o número de dígitos de N:</p>
    <pre><code>var s = "JavaScript syntax highlighting";<br>alert(s);</code></pre>
    <p>Reescreva a função Digitos tornando-a recursiva.</p>
    <p>Não será permitido utilizar variáveis globais, vetores, listas ou qualquer outra estrutura de dados para armazenar o resultado. O protótipo da função deverá, obrigatoriamente, ser:</p>
    <pre><code>int Digitos(int N);</code></pre>
    <p>O programa deverá conter, além da função recursiva, uma função principal (main) para realização de testes, com o formato de saída de acordo com o exemplo a seguir:</p>
    <pre><code>Digite um numero inteiro: 12345<br>Resultado: 5</code></pre>
</details>

<details>
    <summary>Decimal para Binário</summary>
    <p>Um problema típico em computação consiste em converter um número da sua forma decimal para a forma binária. Por exemplo, o número 12 tem a sua representação binária igual a 1100. A forma mais simples de fazer isso é usando o método das divisões sucessivas: divide-se o número sucessivamente por 2, onde o resto da i-ésima divisão vai ser o dígito i do número binário (da direita para a esquerda).</p>
    <p>Por exemplo:</p>
    <pre><code><p>12/2 = 6 resto 0</p><p>6/2  = 3 resto 0</p><p>3/2  = 1 resto 1</p><p>1/2  = 0 resto 1<p></code></pre>
    <p>Resultado: 12 = 1100 (restos tomados de baixo para cima)</p>
    <p>Escreva uma função recursiva que, dado um número decimal, imprima a sua representação binária corretamente. O protótipo da função deverá, obrigatoriamente, ser:</p>
    <pre><code><p>void dec2bin(int dec);</p></code></pre>
    <p>Não será permitido utilizar variáveis globais, vetores, listas ou qualquer outra estrutura de dados para armazenar o número em binário, pois este será impresso à medida que for sendo calculado dentro da função.</p>
    <p>O programa deverá conter, além da função recursiva, uma função principal (main) para realização de testes, com o formato de saída de acordo com o exemplo a seguir:</p>
    <pre><code><p>Digite um numero inteiro: 34</p><p>Resultado: 100010</p></code></pre>
</details>

<details>
    <summary>Potência</summary>
    <p>Implemente uma função recursiva que, dados dois números inteiros x e n, calcula o valor de x^n.</p>
    <p>Não será permitido utilizar variáveis globais, vetores, listas ou qualquer outra estrutura de dados para armazenar o resultado. O protótipo da função deverá, obrigatoriamente, ser:</p>
    <pre><code><p>int mult(int base, int exp);</p></code></pre>
    <p>O programa deverá conter, além da função recursiva, uma função principal (main) para realização de testes, com o formato de saída de acordo com o exemplo a seguir:</p>
    <pre><code><p>Digite a base e o expoente inteiros: 2 8</p><p>Resultado: 256</p></code></pre>
</details>

<details>
    <summary>Máximo Divisor Comum (MDC)</summary>
    <p>Implemente uma função recursiva que, dados dois números inteiros a e b, calcula o Máximo Divisor Comum (MDC) entre eles.</p>
    <p>Não será permitido utilizar variáveis globais, vetores, listas ou qualquer outra estrutura de dados para armazenar o resultado. O protótipo da função deverá, obrigatoriamente, ser:</p>
    <pre><code><p>int mdc(int a, int b);</p></code></pre>
    <p>O programa deverá conter, além da função recursiva, uma função principal (main) para realização de testes, com o formato de saída de acordo com o exemplo a seguir:</p>
    <pre><code><p>Digite dois numeros inteiros: 25 10</p><p>Resultado: 5</p></code></pre>
</details>