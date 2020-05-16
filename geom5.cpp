#include <stdio.h>
#include <graphics.h>
#include <math.h>

float x1,x2,yy1,yy2;
int x_max,y_max;//cord ecran
float pie=3.1415;
float theta=pie/36.f; //unghiul de rotatie, in radiani
float xa,ya,xb,yb,xc,yc;//coord. triunghiului

int xe(float x) { // normalizarea coordonatei x
	return((int) floor((x-x1)/(x2-x1)*x_max));
}
int ye(float y) { // normalizarea coordonatei y
	return((int) floor((yy2-y)/(yy2-yy1)*y_max));
}
void axe() {
	setcolor(0);
	outtextxy(xe(x2)-20,ye(0)-20,"x");
	outtextxy(xe(x2)-6,ye(0)-7,">");
	outtextxy(xe(0)-15,ye(yy2)+15,"y");
	outtextxy(xe(0)-15,ye(0)-15,"O");
	outtextxy(xe(0)-1,ye(yy2)+1,"^");
	line(xe(x1),ye(0),xe(x2),ye(0));
	line(xe(0),ye(yy1),xe(0),ye(yy2));
}
void grafic() {
	outtextxy(xe(xa)+10,ye(ya)-10,"A");
	circle(xe(xa),ye(ya),2);
	outtextxy(xe(xb)+10,ye(yb)-10,"B");
	circle(xe(xb),ye(yb),2);
	outtextxy(xe(xc)-10,ye(yc)+10,"C");
	circle(xe(xc),ye(yc),2);
	line(xe(xa),ye(ya),xe(xb),ye(yb));
	line(xe(xc),ye(yc),xe(xb),ye(yb));
	line(xe(xa),ye(ya),xe(xc),ye(yc));
}
void rot() {
	xa=xa*cos(theta)-ya*sin(theta);
	ya=xa*sin(theta)+ya*cos(theta);
	xb=xb*cos(theta)-yb*sin(theta);
	yb=xb*sin(theta)+yb*cos(theta);
	xc=xc*cos(theta)-yc*sin(theta);
	yc=xc*sin(theta)+yc*cos(theta);
}
int main() {
	printf("Limitele domeniului orizontal:\n");
	printf("x1=");
	scanf("%f",&x1); //x_1<0<x_2
    printf("x2=");
	scanf("%f",&x2);
	printf("Limitele domeniului vertical:\n");
	printf("y1=");
	scanf("%f",&yy1); //y_1<0<y_2
	printf("y2=");
	scanf("%f",&yy2);
	initwindow(800,600, "Rotatie triunghi",200,200);
	x_max=getmaxx(); //nr. maxim de pixeli pe coord. x
	y_max=getmaxy();
	float sum_t=0.f;
	xa=7;
	ya=10;//initializare coord triunghi
	xb= 10;
	yb=4;
	xc=1;
	yb=1;
	do {
		setbkcolor(RED);
		cleardevice();
		axe();
		grafic();
		delay(100);
		rot();
		sum_t=sum_t+theta;
	} while(sum_t<=2*pie);
	getchar();
	getchar();
	closegraph();
	return 0;
}

