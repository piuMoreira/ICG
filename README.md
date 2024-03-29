# ICG

### Introdução

Este repositório é destinado a implementação de um algoritmo para rasterização passado como primeiro trabalho da disciplina de Introdução À Computação Gráfica ministrada pelo Profº Christian A. Pagot no semestre 2019.1 da Universidade Federal da Paraíba. Mas o que é rasterização? 

“Approximation of mathematical ('ideal')
primitives, described in terms of vertices on a
Cartesian grid, by sets of pixels of the
appropriate intensity of gray or color.” -- Foley et. al

Implementaremos mais especificamente o Algoritmo de Bresenham. Este é um algoritmo incremental para rasterização de linhas, ou seja, evita multiplicações e arredondamentos que deixam o trabalho da rasterização mais caro, além disso ele também pode ser generalizado para círculos. Abaixo é possível ver um exemplo do processo de rasterização o Algoritmo de Bresenham.

<p align="center">
    <img src="/prints/bresenham.jpg">
</p>

### Rasterizando Pontos
A rasterização de um ponto na nossa implementação se dá pela função abaixo:

```c
void putPixel(Ponto *p) {
    for(unsigned int i = 0; i<4; i++){
        FBptr[p->x*4+i + p->y*4*IMAGE_WIDTH] = p->cor[i];
    }
}
```

Na função acima vemos que putPixel recebe um dado do tipo Ponto, essa estrutura possui dois inteiros que repesentam a posição (x, y) do pixel, bem como um array de quatro posições chamado cor. Como a cor de cada pixel se dá pelo conjunto de 4 bytes, onde cada um representa a intensidade de vermelho, verde, azul e o nível de transparência, respectivamente, essa estrutura de repetição calcula o offset da posição de cada uma dessas componentes do pixel a partir do ponteiro do FrameBuffer (FBptr) e atribui a cada uma delas o seu respectivo valor definido no parâmetro cor do Ponto. Abaixo é possível ver um exemplo da utilização dessa função.

<p align="center">
    <img src="/prints/putPixel.jpg">
</p>

### Rasterizando Linhas

O Algoritmo de Bresenham é um algoritmo incremental, ou seja, ele faz adições de inteiros para calcular os locais onde deve desenhar os pontos afim de se obter a representação da primitiva matemática através de pixels. O código do algoritmo é apresentado abaixo.

```c
void drawLine(Ponto *inicio, Ponto *final) {
    int dx = final->x - inicio->x;
    int dy = final->y - inicio->y;
    int d = 2 * dy - dx;
    double dist_total = sqrt(pow(dx, 2) + pow(dy, 2));
    int inc_leste = dy;
    int inc_nordeste = dy-dx;    
    int x = inicio->x;
    int y = inicio->y;
        while(x < final->x) {
            if(d<=0) {
                d+=inc_leste;
                x++;
            } else {
                d+=inc_nordeste;
                x++;
                y++;
            }
            dx = final->x - x;
            dy = final->y - y;
            int newColorr[4];
            newColor(dx, dy, dist_total, inicio, final, newColorr);
            Ponto novoPonto;
            newPonto(&novoPonto,x,y, newColorr);
            putPixel(&novoPonto);
            }
}
```

O problema é que o Algoritmo de Bresenham consegue desenhar apenas retas que têm inclinação de 0º à 45º, ou seja, retas que estão no primeiro octante. Uma reta criada a partir do algoritmo na sua forma original pode ser vista abaixo.

<p align="center">
    <img src="/prints/primeiroOctante.jpg">
</p>

Esse problema pode ser contornado pois retas que se encontram nos demais octantes podem ser reduzidos ao primeiro, ou seja, é possível fazer variações do Algorítimo de Bresenham para se poder rasterizar retas em todos os octantes. A posição dos octantes pode ser vista na imagem abaixo.

<p align="center">
    <img src="/prints/octantes.png">
</p>

Com as variações implementadas é possível ter o resultado abaixo.

<p align="center">
    <img src="/prints/oitoOctantes.jpg">
</p>

### Desenhando Triângulos

Agora que podemos desenhar em todos os octantes, desenhar um triângulo não é mais uma tarefa difícil, como se pode ver abaixo.

```c
void drawTriangle(Ponto *p1, Ponto *p2, Ponto *p3) {
    drawLine(p1,p2);
    drawLine(p2,p3);
    drawLine(p3,p1);
}
```
<p align="center">
    <img src="/prints/triangulo.jpg">
</p>

### Conclusão

Com base no que foi apresentado, destacamos a importância deste algoritmo para a área da computação gráfica por possibilitar a rasterização de primitivas matemáticas através de operações computacionalmente mais baratas dos que os métodos utilizados até então. Durante sua implementação encontramos dificuldades para organizar o código de maneira legível e bem estruturada, visto que são oito octantes e por isso é preciso generalizar o código para cada um deles. Além disso tivemos que buscar informações sobre a interpolação de cores para deixar as retas com esse efeito que é visto acima.

### Bibliografia

<ul>
    <li>Slides utilizados pelo professor durante as aulas.</li>
    <li>http://letslearnbits.blogspot.com/2014/10/icgt1-interpolacao-de-cores.html</li>
    <li>https://medium.com/@raullesteves/github-como-fazer-um-readme-md-bonit%C3%A3o-c85c8f154f8</li>
</ul>
