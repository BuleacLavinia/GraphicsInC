#include "graphics.h"
#include <math.h>
#include <stdlib.h>
#include <dos.h>
#include <windows.h>
#include <iostream>

using namespace std;
#define pi 3.14159265359
float x_1=-5, x_2=5, y_1=-5, y_2=5;
int a, b;

int xe(float x) { // normalizarea coordonatei x
	return((int)((x - x_1) / (x_2 - x_1)*a));
}
int ye(float y) { // normalizarea coordonatei y
	return((int)((y_2 - y) / (y_2 - y_1)*b));
}

void parabola() {
	float theta ;
	float x,y;
	float pie=3.1415;
	float h=2*pie/4000; //,,pasul" de reprezentare
//float r=1.f;//raza cercului
	theta=0;
	while (theta<=2*pie) {
		x=theta;
		y=theta*theta;
		putpixel(xe(x),ye(y),14);
		putpixel(xe(-x),ye(y),14);
		theta=theta+h;
	}
}

void cerc() {
	float theta ;
	float x,y;
	float pie=3.14159265359;
	float h=2*pie/40000; //,,pasul" de reprezentare
//float r=1.f;//raza cercului
	theta=0;
	while (theta<=2*pie) {
		x=theta;
		y=sqrt(1-x*x);
		putpixel(xe(x),ye(y),14);
		putpixel(xe(-x),ye(y),14);
		putpixel(xe(-x),ye(-y),14);
		putpixel(xe(x),ye(-y),14);
		theta=theta+h;
	}
}

int main() {
	initwindow(800, 800, "Figuri", 200, 200);
	setbkcolor(4);
	cleardevice();
	setcolor(BLACK);
	outtextxy(200,200,"Grafic parabola si cerc: ");
	a = getmaxx(); //nr. maxim de pixeli pe coord. x
	b = getmaxy();
	parabola();
	cerc();
	getch();
	closegraph();
	return 0;
}

