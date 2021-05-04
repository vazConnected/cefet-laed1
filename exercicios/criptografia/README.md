# Laboratório de Algoritmos e Estruturas de Dados 1

## Descrição do exercício "Criptografia"

<p>Em grego, cryptos significa secreto, oculto. A criptografia estuda os métodos para codificar uma mensagem de modo que somente seu destinatário legítimo consiga interpretá-la. É a arte dos “códigos secretos” (Coutinho, 2015).</p>

<p>Uma das técnicas de criptografia mais simples e conhecida consite em substituir cada letra da mensagem por outra, que se apresenta no alfabeto abaixo dela um número fixo de vezes. Conta a história que Júlio César (100-44 a.C.) utilizava este código nas mensagens enviadas a seus generais.</p>

<p>A transformação pode ser representada alinhando-se dois alfabetos: o alfabeto cifrado e o alfabeto normal rotacionado à direita ou esquerda por um número de posições. Por exemplo, a seguir está uma cifra de César usando uma rotação à esquerda de três posições:</p>

```
Normal:  ABCDEFGHIJKLMNOPQRSTUVWXYZ
Cifrado: DEFGHIJKLMNOPQRSTUVWXYZABC
```

<p>Embora cifra de César seja facilmente decifrada e na prática não ofereça essencialmente nenhuma segurança na comunicação, é frequentemente incorporada como parte de esquemas mais complexos de criptografia (Wikipedia, 2019).</p>

<p>Este exercício consiste em ler uma mensagem criptografada de um arquivo texto e imprimir a mensagem descriptografada na saída padrão. A técnica de criptografia será a de códigos em bloco, que consiste em subdividir a mensagem em blocos de várias letras e embaralhar esses blocos. Antes, porém, será utilizada a cifra de César com rotação à esquerda de cinco posições.</p>

<p>Por exemplo, considere a mensagem AMO LIVROS. Para codificá-la seguiremos os seguintes passos:</p>

- Substituir os espaços pelo símbolo # e completar a mensagem com este mesmo símbolo no final, caso tenha uma quantidade ímpar de letras;
- Substituir cada letra por outra, utilizando a cifra de César com uma rotação à esquerda de cinco posições;
- Subdividir a mensagem em blocos de n letras (neste caso n=2);
- Refletir cada bloco;
- Permutar os blocos trocando o primeiro com o último, o terceiro com a antepenúltimo, e assim por diante, mas deixando os outros como estão.

<p>Aplicando isto, passo a passo, à mensagem acima, obtemos primeiro:</p>

<p><code>AMO#LIVROS</code></p>

<p>Depois usamos a cifra de César:</p>

<p><code>FRT#QNAWTX</code></p>

<p>Separamos em blocos de 2 letras:</p>

<p><code>FR-T#-QN-AW-TX</code></p>

<p>em seguida:</p>

<p><code>RF-#T-NQ-WA-XT</code></p>

<p>E, finalmente:</p>

<p><code>XT-#T-NQ-WA-RF</code></p>

<p>Que nos dá como mensagem codificada:</p>

<p><code>XT#TNQWARF</code></p>

<p>Use o método explicado para poder decodificar a mensagem contida em um arquivo texto cujo nome será lido da entrada padrão. Para simplificar, foram eliminados acentos e pontuação. As letras maiúsculas e minúsculas do texto deverão ser mantidas.</p>

<p>A saída do programa deverá seguir o padrão abaixo, mas lembre-se que o seu programa será testado com arquivos distintos:</p>

```
Digite o nome do arquivo: mensagem.txt

--------------------
Mensagem codificada:
--------------------
tinhkn#ftyH#y#wfxfitufjxmsfk#jrqjzjytrhjr#fwfiknxji#v#sjx#nhjy#w#f#jsju#t#xjcjjih#wkfw#F

----------------------
Mensagem decodificada:
----------------------
A cifra de Cesar pode ser facilmente decifrada mesmo que se tenha apenas o texto cifrado

```

<p>Referências:</p>

- Coutinho, S. C. Criptografia. 2015. Disponível em: http://www.obmep.org.br/docs/apostila7.pdf.
- Wikipedia. Cifra de César. 2019. Disponível em: https://pt.wikipedia.org/wiki/CifradeC%C3%A9sar.
