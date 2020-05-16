#include "graphics.h"
#include <math.h>
#include <stdlib.h>
#include <dos.h>
#include <windows.h>
#include <iostream>
#include <time.h>
#define pi 3.14159265359

using namespace std;

float x_1=-40, x_2=40, y_1=-40, y_2=40;
int a, b;

int xe(float x) { // normalizarea coordonatei x
	return((int)((x - x_1) / (x_2 - x_1)*a));
}
int ye(float y) { // normalizarea coordonatei y
	return((int)((y_2 - y) / (y_2 - y_1)*b));
}

int main() {
    srand(time(0)); 
	initwindow(800, 800, "Figuri", 200, 200);
	setbkcolor(WHITE);
	cleardevice();
	setcolor(RED);
	outtextxy(200,200,"Sa se genereze aleator 5 patrate cu latura 1,");
    outtextxy(220,220,"avand in varfurile lor cate un cerc cu raza de 5 pixeli.");
	a = getmaxx(); //nr. maxim de pixeli pe coord. x
	b = getmaxy();
	int num=0;
	setcolor(RED);
	for(int i=0;i<5;i++){
    num = rand()%350;
    line(num-1,num+1,num+1,num+1);
    line(num+1,num+1,num+1,num-1);
    line(num+1,num-1,num-1,num-1);
    line(num-1,num-1,num-1,num+1);
    circle(num-1,num+1,5);
    circle(num+1,num+1,5);
    circle(num+1,num-1,5);
    circle(num-1,num-1,5);
    }
	getch();
	closegraph();
	return 0;
}

