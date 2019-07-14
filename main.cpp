#include "main.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************

	// Ponto p1, p2, p3, p4, p5, p6, p7, p8;
	// int Vermelho[4] = {255, 0, 0,0};
	// int Azul[4] = {0, 0, 255, 0};

	// newPonto(&p1,0,0,Azul);
	// newPonto(&p2,IMAGE_HEIGHT/2,0,Azul);
	// newPonto(&p3,IMAGE_HEIGHT,0,Azul);
	// newPonto(&p4,0,IMAGE_WIDTH/2,Azul);
	// newPonto(&p5,0,IMAGE_WIDTH,Vermelho);
	// newPonto(&p6,IMAGE_HEIGHT/2,IMAGE_WIDTH,Vermelho);
	// newPonto(&p7,IMAGE_HEIGHT,IMAGE_WIDTH,Vermelho);
	// newPonto(&p8,IMAGE_HEIGHT,IMAGE_WIDTH/2,Vermelho);

	//drawLine(&p1,&p7);
	// drawLine(&p3,&p5);
	// drawLine(&p2,&p6);
	// drawLine(&p4,&p8);

	Ponto p1, p2, p3;
	int Vermelho[4] = {255, 0, 0,0};
	int Azul[4] = {0, 0, 255, 0};
	int Verde[4] = {0, 255, 0, 0};

	newPonto(&p1, 50, IMAGE_WIDTH-100, Vermelho);
	newPonto(&p2, IMAGE_HEIGHT-50, IMAGE_WIDTH-100, Verde);
	newPonto(&p3, IMAGE_HEIGHT/2, 50, Azul);

	drawTriangle(&p1, &p2, &p3);

}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;	

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}

