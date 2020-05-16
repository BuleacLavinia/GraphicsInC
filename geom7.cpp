#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define pi 3.14159265358979323846264338327950288

float x1,x2,yy1,yy2;
int xemax,yemax;
int xe(float x)
// normalizarea coordonatei x
{
	return((int) floor((x-x1)/(x2-x1)*xemax));
}
int ye(float y)
// normalizarea coordonatei y. Nota: y1 si y2 sunt constante in graphic.h
{
	return((int) floor((yy2-y)/(yy2-yy1)*yemax));
}

int main() {
	srand(time(0));
	int gd,gm;
	x1=-20;
	x2=20;
	yy1=-20;
	yy2=20;
	initwindow(800,800, "Pb 1 tema",200,200); //initializare fereastra grafica
	setbkcolor(0);//definire culoare de background
	cleardevice();
	setcolor(14);
	xemax=getmaxx();
	outtextxy(200,200,"Elipsa cu 50 de pct random");
	yemax=getmaxy(); //determinarea rezolutiei ferestrei
	ellipse(400, 400, 0, 360, 300, 100);
	for(int i=0; i<50; i++) {
		int num = rand() %200+400;
		int num2 = rand()%50+400;
		putpixel(num,num2,RED);
	}
	//ellipse(250, 200, 0, 360, 100, 50);
	getch();
	closegraph(); //inchidere fereastra grafica
	return 0;
}

