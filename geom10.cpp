#include "graphics.h"
#include <math.h>
#include <stdlib.h>
#include <dos.h>
#include <windows.h>
#include <iostream>
#define pi 3.14159265359

using namespace std;

float x_1=-5, x_2=5, y_1=-5, y_2=5;
int a, b;

int xe(float x) { // normalizarea coordonatei x
	return((int)((x - x_1) / (x_2 - x_1)*a));
}
int ye(float y) { // normalizarea coordonatei y
	return((int)((y_2 - y) / (y_2 - y_1)*b));
}

int main() {
	initwindow(800, 800, "Figuri", 200, 200);
	setbkcolor(WHITE);
	cleardevice();
	setcolor(BLACK);
	outtextxy(200,200,"Sa se genereze 4 cercuri incluse in interiorul unui patrat de latura 10,");
    outtextxy(220,220,"avand centrul patratului in originea axelor de coordonate. ");
	a = getmaxx(); //nr. maxim de pixeli pe coord. x
	b = getmaxy();
    line(xe(0)-10,ye(0)+10,xe(0)+10,ye(0)+10);
    line(xe(0)+10,ye(0)+10,xe(0)+10,ye(0)-10);
    line(xe(0)+10,ye(0)-10,xe(0)-10,ye(0)-10);
    line(xe(0)-10,ye(0)-10,xe(0)-10,ye(0)+10);
    for(int i=1;i<=4;i++){
        setcolor(i);
        circle(xe(0),ye(0),i);
    }
	getch();
	closegraph();
	return 0;
}

