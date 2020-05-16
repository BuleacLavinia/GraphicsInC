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
void grafic() {
	float theta ;
	float x,y;
	float pie=3.1415;
	float h=2*pie/4000; 
	theta=0;
	while (theta<=(1.5)*pie) {
		x=theta;
		y=sin(theta)*cos(theta);
		putpixel(xe(x),ye(y),14);
		theta=theta+h;
	}
}
int main() {
	initwindow(800, 600, "AXE", 200, 200);
	setbkcolor(4);
	cleardevice();
	setcolor(YELLOW);
	outtextxy(200,200,"Grafic sin(th)*cos(th): ");
	a = getmaxx(); //nr. maxim de pixeli pe coord. x
	b = getmaxy();
	grafic();
	getch();
	closegraph();
	return 0;
}

