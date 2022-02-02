#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>

void BresenhamCircle(int xc, int yc, int r);
void EightWaySymm(int xc, int yc, int x, int y);
void flood_fill(int x, int y, int n, int o);

void main()
{
    int gd = DETECT, gm, i;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    delay(500);
    setfillstyle(1, DARKGRAY);
    floodfill(1, 1, WHITE);
    delay(500);
    outtextxy(280, 10, "RANGOLI 02");
    delay(500);
    putpixel(320, 240, getcolor());
    putpixel(321, 241, getcolor());
    putpixel(321, 239, getcolor());
    putpixel(319, 241, getcolor());
    putpixel(319, 239, getcolor());
    for (i = 1; i <= 3; i++)
        BresenhamCircle(320, 240, i);
    delay(500);
    line(320, 290, 420, 240);
    delay(500);
    line(370, 265, 370, 165);
    delay(500);
    line(370, 215, 270, 165);
    delay(500);
    line(320, 190, 220, 240);
    delay(500);
    line(270, 215, 270, 315);
    delay(500);
    line(270, 265, 370, 315);

    delay(500);
    line(420, 240, 420, 90);
    delay(500);
    line(370, 165, 220, 90);
    delay(500);
    line(270, 165, 120, 240);
    delay(500);
    line(220, 240, 220, 390);
    delay(500);
    line(270, 315, 420, 390);
    delay(500);
    line(370, 315, 520, 240);

    delay(500);
    line(420, 90, 320, 140);
    delay(500);
    line(220, 90, 220, 190);
    delay(500);
    line(120, 240, 220, 290);
    delay(500);
    line(220, 390, 320, 340);
    delay(500);
    line(420, 390, 420, 290);
    delay(500);
    line(520, 240, 420, 190);

    setfillstyle(1, RED);
    delay(500);
    floodfill(370, 290, WHITE);
    delay(500);
    floodfill(320, 165, WHITE);
    delay(500);
    floodfill(245, 240, WHITE);

    setfillstyle(1, YELLOW);
    delay(500);
    floodfill(385, 240, WHITE);
    delay(500);
    floodfill(200, 240, WHITE);
    delay(500);
    floodfill(320, 315, WHITE);

    delay(500);
    BresenhamCircle(320, 240, 210);
    delay(500);
    setfillstyle(1, BLUE);
    floodfill(320, 350, WHITE);
    floodfill(335, 240, WHITE);

    getch();
    closegraph();
}

void EightWaySymm(int xc, int yc, int x, int y)
{
    putpixel(x + xc, y + yc, getcolor());
    putpixel(x + xc, -y + yc, getcolor());
    putpixel(-x + xc, -y + yc, getcolor());
    putpixel(-x + xc, y + yc, getcolor());
    putpixel(y + xc, x + yc, getcolor());
    putpixel(y + xc, -x + yc, getcolor());
    putpixel(-y + xc, -x + yc, getcolor());
    putpixel(-y + xc, x + yc, getcolor());
}

void BresenhamCircle(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - (2 * r);
    EightWaySymm(xc, yc, x, y);
    while (x <= y)
    {
        if (d <= 0)
        {
            d = d + (4 * x) + 6;
        }
        else
        {
            d = d + (4 * x) - (4 * y) + 10;
            y--;
        }
        x++;
        EightWaySymm(xc, yc, x, y);
    }
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