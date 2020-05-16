#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define pi 3.14159265358979323846264338327950288

int main() {
	srand(time(0));
	int gd,gm,aux=40;
	initwindow(800,800, "Pb 2 tema",200,200); //initializare fereastra grafica
	setbkcolor(0);//definire culoare de background
	cleardevice();
	setcolor(14);
	outtextxy(500,500,"8 triunghiuri aleatoare");
	for(int i=0; i<8; i++) {
		int x = rand()%aux+20;
		aux+=50;
		int culoare = rand()%14;
		setcolor(culoare);
		line(i+aux,i+200,i+200,i+40);
		line(i+200,i+40,i+40,i+215);
		line(i+40,i+215,i+aux,i+200);
	}
	getch();
	closegraph(); //inchidere fereastra grafica
	return 0;
}

