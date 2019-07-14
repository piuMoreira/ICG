# ICG

### Introdução
Este repositório é destinado à implementação de algorítmos de raterização. Mas o que é rasterização? 

“Approximation of mathematical ('ideal')
primitives, described in terms of vertices on a
Cartesian grid, by sets of pixels of the
appropriate intensity of gray or color.” -- Foley et. al

Implementaremos mais especificamente o Algoritmo de Bresenham; é um algoritmo incremental, ou seja, evita multiplicações e arredondamentos que deixam o trabalho da rasterização mais caro, alem disso o Algorimo de Bresenham pode ser generalizado para circulos. Abaixo é possível ver um exemplo do processo de raterização o Algoritmo de Bresenham.

![GitHub Logo](/prints/bresenham.jpg)
Format: ![Alt Text](url)


### Raterizando pontos
A raterização de um ponto na nossa implementação se dá por:

```c
void putPixel(unsigned int x, unsigned int y, int *RGBAInfo) {
    for(unsigned int i = 0; i<4; i++){
        FBptr[x*4+i + y*4*IMAGE_WIDTH] = RGBAInfo[i];
    }
}
```

Na função acima vemos que putPixel recebe dois inteiros, x e y que representam a posição em que o pixel se encontrará na tela, além disso a função também recebe um array de inteiros contendo a informações RGBA do pixel. Como a cor do pixel se dá pelo conjunto de 4 bytes cada um representando a intensidade de vermelhe, verde, azul e transparência, essa estrutura de repetição calcula o offset da posição de cada uma dessas componententes à partir do ponteiro do FrameBuffer e atribui o valor passado em RGBAInfo. Abaixo é possível ver um exemplo da utilização dessa função.

