#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"
#include<math.h>
#include<stdio.h>

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

typedef struct {
    unsigned int x;
    unsigned int y;
    int cor[4];
}Ponto;

void newPonto(Ponto *p, unsigned int x, unsigned int y, int *RGBAInfo) {
    p->x = x;
    p->y = y;
    for(int i = 0; i<4; i++) {
        p->cor[i] = RGBAInfo[i];
    }
}

void putPixel(Ponto *p) {
    for(unsigned int i = 0; i<4; i++){
        FBptr[p->x*4+i + p->y*4*IMAGE_WIDTH] = p->cor[i];
    }
}

void newColor(int dx, int dy, double dist_total, Ponto *inicio, Ponto *final, int *newColorr) {
    double dist_parcial;
    dist_parcial = sqrt(pow(dx, 2.0) + pow(dy, 2.0));
    double cor = dist_parcial / dist_total;
    for(unsigned int i = 0; i < 4; i++) {
        newColorr[i] = cor * inicio->cor[i] + (1 - cor) * final->cor[i];
    }
}

void drawLine(Ponto *inicio, Ponto *final) {
    int dx = final->x - inicio->x;
    int dy = final->y - inicio->y;
    int modX = abs(dx);
    int modY = abs(dy);
    int d = 2 * dy - dx;
    double dist_total = sqrt(pow(dx, 2) + pow(dy, 2));
    if(dy>=0 && dx>=0 && modX>=modY) {
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
    } else if(dy>=0 && dx>=0 && modY>=modX) {
        int inc_nordeste = dy-dx;
        int inc_norte = -dx;
        int x = inicio->x;
        int y = inicio->y;
        double dist_parcial;
        while(y < final->y){
            if(d<=0) {
                d+=inc_nordeste;
                x++;
                y++;
            } else {
                d+=inc_norte;
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
    } else if(dy>=0 && dx<=0 && modY>=modX) {
        int inc_norte = -dx;
        int inc_noroeste = -dx-dy;
        int x = inicio->x;
        int y = inicio->y;
        double dist_parcial;
        while((y < final->y)){
            if(d<=0) {
                d+=inc_norte;
                y++;                  
            } else {
                d+=inc_noroeste;
                x--;
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
    } else if(dy>=0 && dx<=0 && modX>=modY) {
        int inc_noroeste = -dx-dy;
        int inc_oeste = -dy;
        int x = inicio->x;
        int y = inicio->y;
        double dist_parcial;
        while((x > final->x)){
            if(d<=0) {
                d+=inc_noroeste;
                x--;
                y++;               
            } else {      
                d+=inc_oeste;
                x--;           
                
            }
            dx = final->x - x;
            dy = final->y - y;
            int newColorr[4];
            newColor(dx, dy, dist_total, inicio, final, newColorr);
            Ponto novoPonto;
            newPonto(&novoPonto,x,y, newColorr);
            putPixel(&novoPonto);
        }
    } else if(dy<=0 && dx<=0 && modX>=modY) {
        int inc_oeste = -dy;
        int inc_suldoeste = -dy + dx;
        int x = inicio->x;
        int y = inicio->y;
        double dist_parcial;
        while(y > final->y){
            if(d<=0) {
                d+=inc_oeste;
                x--;
            } else {
                d+=inc_suldoeste;
                x--;
                y--;
            }

            dx = final->x - x;
            dy = final->y - y;
            int newColorr[4];
            newColor(dx, dy, dist_total, inicio, final, newColorr);
            Ponto novoPonto;
            newPonto(&novoPonto,x,y, newColorr);
            putPixel(&novoPonto);
        }
    } else if(dy<=0 && dx<=0 && modY>=modX) {
        int inc_suldoeste = -dy + dx;
        int inc_sul = dx;
        int x = inicio->x;
        int y = inicio->y;
        double dist_parcial;
        while(y > final->y) {
            if(d<=0) {
                d += inc_suldoeste;
                x--;
                y--;
            } else {
                d += inc_sul;
                y--;
            }

            dx = final->x - x;
            dy = final->y - y;
            int newColorr[4];
            newColor(dx, dy, dist_total, inicio, final, newColorr);
            Ponto novoPonto;
            newPonto(&novoPonto,x,y, newColorr);
            putPixel(&novoPonto);
        }
    } else if(dy<=0 && dx>=0 && modY>=modX) {
        int inc_sul = dx;
        int inc_sudeste = dy+dx;
        int x = inicio->x;
        int y = inicio->y;
        double dist_parcial;
        while(y > final->y) {
            if(d<=0){
                d += inc_sul;
                y--;
            } else {
                d += inc_sudeste;
                x++;
                y--;
            }

            dx = final->x - x;
            dy = final->y - y;
            int newColorr[4];
            newColor(dx, dy, dist_total, inicio, final, newColorr);
            Ponto novoPonto;
            newPonto(&novoPonto,x,y, newColorr);
            putPixel(&novoPonto);
        }

    } else if(dy<=0 && dx>=0 && modX>=modY) {
        int inc_sudeste = dy+dx;
        int inc_leste = dy;
        int x = inicio->x;
        int y = inicio->y;
        double dist_parcial;
        while(x<final->x) {
            if(d<=0) {
                d += inc_sudeste;
                x++;
                y--;
            } else {
                d += inc_leste;
                x++;
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
}

void drawTriangle(Ponto *p1, Ponto *p2, Ponto *p3) {
    drawLine(p1,p2);
    drawLine(p2,p3);
    drawLine(p3,p1);
}


#endif // _MYGL_H_

