#include "graphics.h"
#include <math.h>
#include <stdlib.h>
#include <dos.h>
#include <windows.h>
#include <iostream>
#include <time.h>

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

void triunghi(int num){
     int aux=rand()%200;
     line(xe(0),ye(0),num,num+aux);
     line(num,num+aux,num+aux*2,num+aux*3);
     line(num+aux*2,num+aux*3,xe(0),ye(0));
}

int main() {
    srand(time(0)); 
	initwindow(800, 800, "Pb 3 tema", 200, 200);
	setbkcolor(WHITE);
	cleardevice();
	setcolor(BLACK);
	outtextxy(200,200,"Sa se genereze aleator 3 triunghiuri, colorate diferit, cu varfurile"); 
    outtextxy(220,220,"in interiorul unui cerc cu centrul in originea sistemului de coordonate si raza 5.");
	a = getmaxx(); //nr. maxim de pixeli pe coord. x
	b = getmaxy();
	circle(xe(0),ye(0),5);
	for(int i=0;i<3;i++){
        int num = rand() % 200;
        int colour = 15;
        while(colour==15)
             colour = rand()%14 + 1;
        setcolor(colour); 
        triunghi(num);
    }
	getch();
	closegraph();
	return 0;
}

