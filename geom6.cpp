#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>
float x1,x2,yy1,yy2, alfa=3.1415/4;
int x_max,y_max;
int xe(float x) { // normalizarea coordonatei x
	return((int) floor((x-x1)/(x2-x1)*x_max));
}
int ze(float z) { // normalizarea coordonatei y
	return((int) floor((yy2-z)/(yy2-yy1)*y_max));
}
void axe() {
	setcolor(RED);
	line(xe(0),ze(0),xe(x2),ze(0));
	line(xe(0),ze(0),xe(0),ze(yy2));
	line(xe(0),ze(0),xe(0+x1*cos(alfa)),ze(0+x1*sin(alfa)));
	outtextxy(xe(0)-15,ze(0)-15,"O");
	outtextxy(xe(x2)-20,ze(0)-20,"x");
	outtextxy(xe(x2)-6,ze(0)-7,">");
	outtextxy(xe(0)+15,ze(yy2)+5,"z");
	outtextxy(xe(0)-1,ze(yy2)+1,"^");
	outtextxy(xe(x1*cos(alfa)),ze(x1*sin(alfa)),"y");
}
void grafic() {
	float t,h;
	float x,y,z;
	float pie=3.1415;
	t=-10;
	h=pie/300;
	while (t<=+15) {
		x=cos(t);
		y=sin(t);
		z=sin(x*x+y*y);
		putpixel(xe(x-y*cos(alfa) ),ze(z-y*sin(alfa)),RED);
		t=t+h;
	}
	t=0;
}
int main() {
	int gd,gm;
	printf("Limitele domeniului orizontal:\n");
	printf("x1=");
	scanf("%f",&x1);
	printf("x2=");
	scanf("%f",&x2);
	yy1=x1;
	yy2=x2;
	initwindow(800,800, "3D",200,200);
	setbkcolor(7);
	cleardevice();
	x_max=getmaxx();
	y_max=getmaxy();
	axe();
	setcolor(RED);
	grafic();
	getchar();
	getchar();
	closegraph();
	return 0;
}

