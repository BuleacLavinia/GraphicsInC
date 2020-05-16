#include <iostream>
#include <time.h>
#include <graphics.h>

int main() {
	initwindow(800,600, "Tema 2",200,200);
	setbkcolor(3); //setbkcolor(CYAN);
	cleardevice(); //stabileste culoarea ecranului
	setcolor(7);
	outtextxy(100,100,"Desenati un cerc centrat în mijlocul ferestrei grafice.");
	outtextxy(120,120,"Plasati 3 triunghiuri de coordonate arbitrare în interiorul acestuia,");
	outtextxy(140,140,"schimbând culorile de desenare ale acestora.");
	setcolor(4);
	circle(400,300,200);

	srand (time(NULL));
	int colour=7;
	while(colour==7)
		colour = rand() % 14 + 1;
	setcolor(colour);
	line(200,300,300,400);
	line(300,400,250,380);
	line(250,380,200,300);

	colour=7;
	while(colour==7)
		colour = rand() % 14 + 1;
	setcolor(colour);
	line(320,410,410,256);
	line(410,256,256,380);
	line(256,380,320,410);

	colour=7;
	while(colour==7)
		colour = rand() % 14 + 1;
	setcolor(colour);
	line(310,380,380,290);
	line(380,290,290,222);
	line(290,222,310,380);

	getch(); //astepta o tasta
	closegraph();
	return 0;
}

