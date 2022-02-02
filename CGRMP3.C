#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <dos.h>

void flood_fill(int x, int y, int n, int o);

void main()
{
	int gd = DETECT, gm, xc, yc, a = 200, b = 75, c = 1;
	int i, j, k;
	double rad1, rad2, x[10], y[10], angle1 = 0, angle2 = 0, pi = 3.141592654;
	char ch;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	delay(500);
	setfillstyle(1, DARKGRAY);
	floodfill(1, 1, WHITE);
	delay(500);
	outtextxy(280, 10, "RANGOLI 03");
	xc = 320;
	yc = 240;
	for (j = 0; j < 1440; j++)
	{
		for (k = 0; k < 8; k++)
		{
			rad1 = (pi * angle1) / 180;
			rad2 = (pi * angle2) / 180;
			x[k] = a * cos(rad1) * cos(rad2) - b * sin(rad1) * sin(rad2);
			y[k] = a * sin(rad1) * cos(rad2) + b * cos(rad1) * sin(rad2);
			circle(xc, yc, 5);
			setfillstyle(1, WHITE);
			floodfill(xc, yc, WHITE);
			circle(xc + x[k], yc - y[k], c);
			setfillstyle(1, WHITE);
			floodfill(xc + x[k], yc - y[k], WHITE);
			angle1 += 40.0;
		}
		angle2 += 0.25;
		delay(1);
	}
	getch();
	closegraph();
}

void flood_fill(int x, int y, int n, int o)
{
	if (getpixel(x, y) == o)
	{
		putpixel(x, y, n);
		flood_fill(x + 1, y, n, o);
		flood_fill(x - 1, y, n, o);
		flood_fill(x, y + 1, n, o);
		flood_fill(x, y - 1, n, o);
		flood_fill(x + 1, y + 1, n, o);
		flood_fill(x - 1, y - 1, n, o);
		flood_fill(x + 1, y - 1, n, o);
		flood_fill(x - 1, y + 1, n, o);
	}
}