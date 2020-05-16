#include <graphics.h>

int main() {
	initwindow(800,600, "Pb 1",200,200);
	setbkcolor(4); //setbkcolor(CYAN);
	cleardevice(); //stabileste culoarea ecranului
	setcolor(0);
	outtextxy(100,100,"Modificati programul astfel încât sã afiseze o linie si un cerc.");
	line(100,200,300,280);
	circle(200,200,20);
	getch(); //astepta o tasta
	closegraph();
	return 0;
}

