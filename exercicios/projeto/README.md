# Laboratório de Algoritmos e Estruturas de Dados 1

## Descrição das etapas do projeto

<details>
    <summary>Projeto Parte 1</summary>
    <h3>Busca de Padrão em Lista</h3>
    <p>Uma imagem digital é uma matriz de elementos, podendo ter duas ou mais dimensões, em que cada elemento é um pixel com uma cor ou tom de cinza. Cada cor pode ser representada por um número (tom de cinza) ou por uma tupla (por exemplo, quando utiliza-se o sistema de cores RGB, que é a sigla para <em>Red Green Blue</em>, a representação da cor será uma tripla com três valores).</p>
    <p>Nesta primeira etapa do projeto, não será necessário trabalhar diretamente com imagens digitais, mas vamos tomá-las como exemplo para explicar o problema a ser resolvido. Considere as seguintes imagens de uma pista em miniatura:</p>
    <!-- imagens aqui !-->
    <p>Quando a pista é percorrida com uma câmera e as imagens de cada instante são obtidas, surgem visões diferentes da pista, principalmente nas curvas, em que pode ocorrer cortes na visão da pista. Observe, por exemplo, a sequência de imagens a seguir:</p>
    <!-- imagens aqui !-->
    <p>Nessa sequência de imagens, a partir da primeira, é possível ver que há uma curva próxima e, à medida que se caminha na pista e a curva se aproxima, a câmera captura cada vez menos as bordas da pista (que são as linhas brancas) devido ao seu campo de visão e ao seu movimento. Na última imagem da sequência, é possível ver somente a borda direita, ou seja, parte da pista foi cortada.</p>
    <p>Imagine agora que a pista foi colorida de vermelho. Se fizermos um corte na imagem e tormarmos apenas uma linha (desenhada em amarelo nas imagens abaixo), veremos que, quando a imagem da pista aparece sem cortes (primeira imagem), as cores que aparecem na altura da linha são preto, branco, vermelho, branco e preto, da esquerda para a direita.</p>
    <!-- imagens aqui !-->
    <p>Quando a imagem da pista aparece com cortes, outras possibilidades são possíveis, por exemplo, na segunda imagem temos a seguinte sequência de cores na altura da linha amarela: vermelho, branco e preto, da esquerda para a direita.</p>
    <p>O objetivo da primeira parte do projeto é, dada uma linha da imagem, buscar pelo padrão de sequência de cores que indica que a pista está sendo vista por completo (da borda esquerda até a borda direita).</p>
    <p>No exercício de programação “Análise de segmentos com elementos iguais”, foi fornecido um arquivo com os valores (“cores”) dos elementos de uma linha e foi realizada a análise dos tipos dos segmentos e a contagem do número de elementos do respectivo segmento.</p>
    <p>Se considerarmos o seguinte mapeamento dos valores do vetor para os números inteiros (o mapeamento será sempre o mesmo no projeto,  independentemente dos valores dos elementos fornecidos): 0(preto) = 0; 128(vermelho*) = 1; 255(branco) = 3.</p>
    <p>(*) Observação: na verdade o valor 128 representa um tom de cinza mas que no exemplo será entendido como a cor vermelha para simplificar.</p>
    <p>Então o padrão da pista completa que estamos buscando é a seguinte sequência dos tipos dos segmentos: 1 3 2 3 1.</p>
    <p>Que representam as cores: preto, branco, vermelho, branco e preto. A sequência dos tipos dos segmentos foi parte da saída do exercício de programação citado e, portanto, o código entregue poderá ser aproveitado na solução desta parte do projeto.</p>
    <p>Se eu já tenho um programa que imprime a sequência dos tipos dos segmentos, o que devo fazer então? Você deverá verificar se o padrão “1 3 2 3 1” está presente em alguma parte dessa sequência. Por exemplo, considere a sequência dos tipos dos segmentos:</p>
    <p>| 1 | | 3 | | <em>1</em> | | <em>3</em> | | <em>2</em> | | <em>3</em> | | <em>1</em> | | 3 | | 1 | </p>
    <p>Nesse exemplo há o padrão da pista completa em uma parte da sequência (colorido em amarelo). No exemplo a seguir não há o padrão de pista completa:</p>
    <p>| 1 | | 3 | | 1 | | 3 | | 1 |</p>
    <p>Há várias outras possibilidades de sequências em que o padrão pode ou não estar presente. O padrão será considerado presente na sequência somente se a sub-sequência “1 3 2 3 1” for encontrada nesta ordem.</p>
    <h3>Formato de Entrada de Dados</h3>
    <p>Os valores dos pixels (elementos) da linha da imagem serão fornecidos em um arquivo texto com o seguinte formato: <u>na primeira linha o valor de N</u> e <u>na linha seguinte os N valores</u> dos elementos separados por um espaço em branco. Todos valores são números inteiros. Esse formato é igual ao do exercício de programação “Análise de segmentos com elementos iguais”.</p>
    <p>O programa deverá solicitar o nome do arquivo de entrada.</p>
    <h3>Formato de Saída de Dados</h3>
    <p>O programa deverá produzir a impressão na tela conforme o modelo a seguir, de acordo com o resultado encontrado (não utilize acentuação nem cedilha na saída para esse programa):</p>
    <code><p>Digite o nome do arquivo: teste.txt</p>
    <p>Resultado: Padrao encontrado.</p></code>
    <p>Ou:</p>
    <code><p>Digite o nome do arquivo: teste.txt</p>
    <p>Resultado: Padrao nao encontrado.</p></code>
</details>

<details>
    <summary>Projeto Parte 2</summary>
    <h3>Busca de Padrão em Sequência – Faixa de Pedestres</h3>
    <p>Na primeira etapa do projeto, foi implementada a busca pelo padrão da pista em uma linha da imagem (desenhada em amarelo na imagem de exemplo abaixo). Esse padrão é uma sequência de cores que indica que a pista está sendo vista por completo (da borda esquerda até a borda direita). A sequência de cores que aparecem na altura da linha amarela é: preto, branco, vermelho, branco e preto.</p>
    <!-- imagens aqui !-->
    <p>O objetivo da segunda parte do projeto é, dada uma linha da imagem, identificar o padrão de uma faixa de pedestres como, por exemplo, da imagem a seguir:</p>
    <!-- imagens aqui !-->
    <p>Nesse exemplo há o padrão da faixa de pedestres em uma parte da sequência. Esse padrão é mostrado abaixo:</p>
    </p>| ... | | 1 | | 3 | | 1 | | 3 | | 1 | | 3 | | 1 | | 3 | | 1 | | 3 | | 1 | | 3 | | 1 | | ... |</p>
    <p>Há várias possibilidades de sequências em que o padrão pode ou não estar presente. O padrão será considerado presente na sequência somente se a sub-sequência “1 3 1 3 1 3 1 3 1 3 1 3 1” for encontrada nesta ordem</p>
    <p>Para a implementação da Parte II, o código da Parte I poderá ser utilizado.</p>
    <h3>Formato de Entrada de Dados</h3>
    <p>Os valores dos pixels (elementos) da linha da imagem serão fornecidos em um arquivo texto com o seguinte formato: <u>na primeira linha o valor de N</u> e <u>na linha seguinte os N valores</u> dos elementos separados por um espaço em branco. Todos valores são números inteiros. Esse formato é igual ao do exercício de programação “Análise de segmentos com elementos iguais”.</p>
    <p>O programa deverá solicitar o nome do arquivo de entrada.</p>
    <h3>Formato de Saída de Dados</h3>
    <p>O programa deverá produzir a impressão na tela conforme o modelo a seguir, de acordo com o resultado encontrado (não utilize acentuação nem cedilha na saída para esse programa):</p>
    <code><p>Digite o nome do arquivo: teste.txt</p>
    <p>Resultado: Padrao de faixa de pedestres encontrado.</p></code>
    <p>Ou:</p>
    <code><p>Digite o nome do arquivo: teste.txt</p>
    <p>Resultado: Padrao de faixa de pedestres nao encontrado.</p></code>
</details>

<details>
    <summary>Projeto Parte 3</summary>
    <h3>Detecção de faixa de pedestres em uma imagem da pista</h3>
    <p>Na segunda etapa do projeto, foi implementada a identificação do padrão de uma faixa de pedestres dada uma linha da imagem. Considere que agora não há apenas um, mas L linhas selecionadas na imagem, como mostrado na figura abaixo, em que cada linha está colorida de azul.</p>
    <!-- imagens aqui !-->
    <p>O objetivo da terceira etapa do projeto é realizar a detecção de faixa de pedestres em uma imagem da pista de forma simples, considerado as informações de vários perfis (linhas) da imagem. Dessa forma, cada perfil da imagem deverá ser analisado e o resultado (Pista normal, Faixa de pedestres ou Padrão não identificado) deverá ser armazenado em uma estrutura de dados do tipo lista. </p>
    <p>Para armazenar o resultado da análise de cada perfil em uma lista, utilize uma das implementações do livro texto do Ziviani para o tipo abstrato de dados Lista (por meio de arranjo ou apontadores), disponíveis em: <a href="http://www2.dcc.ufmg.br/livros/algoritmos/implementacoes-03.php">DCC UFMG</a>.</p>
    <p>Cada item da lista, que representa um perfil, deverá conter: um campo Chave (número inteiro que será atribuído sequencialmente a cada perfil lido do arquivo) e um campo Resultado (Pista normal, Faixa de pedestres ou Padrão não identificado).</p>
    <p>É obrigatório utilizar as funções da implementação do Ziviani e não é permitido alterá-las, com exceção da função main e das definições solicitadas neste enunciado. Funções adicionais poderão ser criadas, se necessário.</p>
    <p>Cada grupo deverá escolher qual método será utilizado para realizar a detecção de faixa de pedestres (por exemplo, pode ser considerado que há faixa de pedestres se em pelo menos um perfil for detectado o padrão da faixa). Lembrem-se de levar em consideração que há perfis diversos na imagem, alguns somente com o padrão da pista completa, outros com falhas devido à iluminação ou movimento do robô, etc.</p>
    <!-- imagens aqui !-->
    <p>Para a implementação da Parte III, o código da Parte II poderá ser utilizado.</p>
    <h3>Formato de Entrada de Dados</h3>
    <p>Os valores dos N pixels (elementos) dos L perfis da imagem serão fornecidos em um arquivo texto com o seguinte formato: na primeira linha o valor de L e nas linhas seguintes: o valor de N e na próxima linha os N valores dos elementos do perfil separados por um espaço em branco. Todos valores são números inteiros.</p>
    <p>O programa deverá solicitar o nome do arquivo de entrada.</p>
    <h3>Formato de Saída de Dados</h3>
    <p>O programa deverá produzir a impressão na tela conforme o modelo a seguir, de acordo com o resultado encontrado (não utilize acentuação nem cedilha na saída para esse programa):</p>
    <code><p>Digite o nome do arquivo: teste.txt</p>
    <p>Resultado: Pista sem faixa de pedestres.</p></code>
    <p>Ou:</p>
    <code><p>Digite o nome do arquivo: teste.txt</p>
    <p>Resultado: Pista com faixa de pedestres.</p></code>
</details>