#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <dos.h>

void EightWaySymm(int xc, int yc, int x, int y);
void BresenhamCircle(int xc, int yc, int r);
void flood_fill(int x, int y, int n, int o);
void draw_square(int square[5][2]);
void rotate_square_x(int *sq, int dis);
void rotate_square_y(int *sq, int dis);
void rotate_square_x2(int *sq, int dis);
void rotate_square_y2(int *sq, int dis);
void reflect_square_x(int *sq);
void reflect_square_y(int *sq);
void reflect_square_x2(int *sq);
void copy_square(int *sq, int square[5][2]);
int calculate_distance(int x1, int y1, int x2, int y2);

void main()
{
    int gd = DETECT, gm, diagonal_distance, i;
    int square[5][2] = {{320, 240}, {320 + 100, 240}, {320 + 100, 240 + 100}, {320, 240 + 100}, {320, 240}};
    int sq_rotated[5][2] = {0};
    diagonal_distance = calculate_distance(square[0][0], square[0][1], square[2][0], square[2][1]);

    initgraph(&gd, &gm, "C:\\TC\\BGI");
    delay(500);
    setfillstyle(1, DARKGRAY);
    floodfill(1, 1, WHITE);
    delay(500);
    outtextxy(280, 10, "RANGOLI 01");
    delay(500);

    // 1st square
    draw_square(square);
    delay(500);
    // 2nd square
    copy_square(&sq_rotated[0][0], square);
    rotate_square_x(&sq_rotated[0][0], diagonal_distance);
    draw_square(sq_rotated);
    delay(500);
    // 3rd square
    reflect_square_x(&square[0][0]);
    draw_square(square);
    delay(500);
    // 4th square
    copy_square(&sq_rotated[0][0], square);
    rotate_square_y(&sq_rotated[0][0], diagonal_distance);
    draw_square(sq_rotated);
    delay(500);
    // 5th square
    reflect_square_y(&square[0][0]);
    draw_square(square);
    delay(500);
    // 6th square
    copy_square(&sq_rotated[0][0], square);
    rotate_square_x2(&sq_rotated[0][0], diagonal_distance);
    draw_square(sq_rotated);
    delay(500);
    // 7th square
    reflect_square_x2(&square[0][0]);
    draw_square(square);
    delay(500);
    // 8th square
    copy_square(&sq_rotated[0][0], square);
    rotate_square_y2(&sq_rotated[0][0], diagonal_distance);
    draw_square(sq_rotated);
    delay(500);

    // Filling objects
    setfillstyle(1, MAGENTA);
    floodfill(330, 290, WHITE);
    delay(500);
    setfillstyle(1, LIGHTMAGENTA);
    floodfill(380, 250, WHITE);
    delay(500);
    setfillstyle(1, CYAN);
    floodfill(410, 230, WHITE);
    delay(500);
    setfillstyle(1, LIGHTCYAN);
    floodfill(330, 190, WHITE);
    delay(500);
    setfillstyle(1, GREEN);
    floodfill(310, 220, WHITE);
    delay(500);
    setfillstyle(1, LIGHTGREEN);
    floodfill(270, 230, WHITE);
    delay(500);
    setfillstyle(1, RED);
    floodfill(230, 250, WHITE);
    delay(500);
    setfillstyle(1, LIGHTRED);
    floodfill(310, 280, WHITE);
    delay(500);
    setfillstyle(1, BLUE);
    floodfill(410, 330, WHITE);
    floodfill(410, 150, WHITE);
    floodfill(230, 150, WHITE);
    floodfill(230, 330, WHITE);
    floodfill(430, 240, WHITE);
    floodfill(330, 130, WHITE);
    floodfill(210, 240, WHITE);
    floodfill(310, 350, WHITE);

    // Outside circle
    delay(500);
    BresenhamCircle(320, 240, 200);
    delay(500);
    setfillstyle(1, LIGHTBLUE);
    floodfill(420, 345, WHITE);
    delay(500);

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

void copy_square(int *sq, int square[5][2])
{
    int i, j;
    for (i = 0, j = 0; i < 10; i++)
    {
        if (i % 2 == 0)
            *(sq + i) = square[j][0];
        else
        {
            *(sq + i) = square[j][1];
            j++;
        }
    }
}

void rotate_square_x(int *sq, int dis)
{
    *(sq + 2) = *(sq) + (dis / 2);
    *(sq + 3) = *(sq + 1) - (dis / 2);
    *(sq + 4) = *(sq) + dis;
    *(sq + 5) = *(sq + 1);
    *(sq + 6) = *(sq + 2);
    *(sq + 7) = *(sq + 3) + dis;
}

void rotate_square_y(int *sq, int dis)
{
    *(sq + 2) = *sq - (dis / 2);
    *(sq + 3) = *(sq + 1) - (dis / 2);
    *(sq + 4) = *(sq);
    *(sq + 5) = *(sq + 1) - dis;
    *(sq + 6) = *(sq + 2) + dis;
    *(sq + 7) = *(sq + 3);
}

void rotate_square_x2(int *sq, int dis)
{
    *(sq + 2) = *(sq) - (dis / 2);
    *(sq + 3) = *(sq + 1) + (dis / 2);
    *(sq + 4) = *(sq)-dis;
    *(sq + 5) = *(sq + 1);
    *(sq + 6) = *(sq + 2);
    *(sq + 7) = *(sq + 3) - dis;
}

void rotate_square_y2(int *sq, int dis)
{
    *(sq + 2) = *sq + (dis / 2);
    *(sq + 3) = *(sq + 1) + (dis / 2);
    *(sq + 4) = *(sq);
    *(sq + 5) = *(sq + 1) + dis;
    *(sq + 6) = *(sq + 2) - dis;
    *(sq + 7) = *(sq + 3);
}

void reflect_square_x(int *sq)
{
    *(sq + 2) = *(sq + 2) - 100;
    *(sq + 3) = *(sq + 3) - 100;
    *(sq + 5) = *(sq + 5) - 200;
    *(sq + 6) = *(sq + 6) + 100;
    *(sq + 7) = *(sq + 7) - 100;
}

void reflect_square_y(int *sq)
{
    *(sq + 2) = *(sq + 2) - 100;
    *(sq + 3) = *(sq + 3) + 100;
    *(sq + 4) = *(sq + 4) - 200;
    *(sq + 6) = *(sq + 6) - 100;
    *(sq + 7) = *(sq + 7) - 100;
}

void reflect_square_x2(int *sq)
{
    *(sq + 2) = *(sq + 2) + 100;
    *(sq + 3) = *(sq + 3) + 100;
    *(sq + 5) = *(sq + 5) + 200;
    *(sq + 6) = *(sq + 6) - 100;
    *(sq + 7) = *(sq + 7) + 100;
}

void draw_square(int square[5][2])
{
    int i;
    for (i = 0; i < 4; i++)
        line(square[i][0], square[i][1], square[i + 1][0], square[i + 1][1]);
}

int calculate_distance(int x1, int y1, int x2, int y2)
{
    return ceil(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}