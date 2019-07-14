# ICG

### Introdução
Este repositório é destinado à implementação de algorítmos de raterização. Mas o que é rasterização? 

“Approximation of mathematical ('ideal')
primitives, described in terms of vertices on a
Cartesian grid, by sets of pixels of the
appropriate intensity of gray or color.” -- Foley et. al

Implementaremos mais especificamente o Algoritmo de Bresenham. Este é um algoritmo incremental para rasterização de linhas, ou seja, evita multiplicações e arredondamentos que deixam o trabalho da rasterização mais caro, além disso o Algorimo de Bresenham pode ser generalizado para círculos. Abaixo é possível ver um exemplo do processo de rasterização o Algoritmo de Bresenham.

<p align="center">
    <img src="/prints/bresenham.jpg">
</p>

### Raterizando pontos
A raterização de um ponto na nossa implementação se dá pela função abaixo:

```c
void putPixel(Ponto *p) {
    for(unsigned int i = 0; i<4; i++){
        FBptr[p->x*4+i + p->y*4*IMAGE_WIDTH] = p->cor[i];
    }
}
```

Na função acima vemos que putPixel recebe um dado do tipo Ponto, essa estrutura possui dois inteiros que repesentam a posição (x, y) do pixel, bem como um array de quatro posições chamado cor. Como a cor de cada pixel se dá pelo conjunto de 4 bytes, onde o primeiro, segundo, terceiro e quarto byte representam a intensidade de vermelho, verde, azul e o nível de transparência, respectivamente, essa estrutura de repetição calcula o offset da posição de cada uma dessas componententes a partir do ponteiro do FrameBuffer (FBptr) e atribui a cada uma delas o seu respectivo valor definido no parâmetro cor do Ponto. Abaixo é possível ver um exemplo da utilização dessa função.

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

O problema é que o Algoritmo de Bresenham consegue desenhar apenas retas que têm inclinação de 0º à 45º, ou seja, retas que estão no primeiro octante, a divisão dos octantes pode ser melhor entendida através da imagem abaixo.

<p align="center">
    <img src="/prints/primeiroOctante.jpg">
![](/prints/primeiroOctante.jpg)
</p>

Esse problema pode ser contornado pois retas que se encontram nos demais octantes podem ser reduzidos ao primeiro, ou seja, é possível fazer variações do Algorítimo de Bresenham para se poder desenharem todos os octantes. Os aspectos matemáticos dos octantes odem ser vistos abaixo.


![](/prints/octantes.png)


Com as variações implementadas é possível ter o resultado abaixo.


![](/prints/oitoOctantes.jpg)


### Desenhando Triângulos

Agora que podemos desenhar em todos os octantes, desenhar um triângulo não é mais uma tarefa difícil, como se pode ver abaixo.

```c
void drawTriangle(Ponto *p1, Ponto *p2, Ponto *p3) {
    drawLine(p1,p2);
    drawLine(p2,p3);
    drawLine(p3,p1);
}
```


![](/prints/triangulo.jpg)
