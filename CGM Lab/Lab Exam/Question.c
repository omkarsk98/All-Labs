// Write a program to implement a rectangle using bresehman's line drawing alorithm and rotate it by 45 deg.
#include <stdio.h>
#include <graphics.h>
int coordinates[][2] = {{370, 190}, {370, 140}, {470, 140}, {470, 190}};

void drawlineh(int x0, int y0, int x1, int y1)
{
  int dx, dy, p, x, y;
  dx = x1 - x0;
  dy = y1 - y0;
  x = x0;
  y = y0;
  p = 2 * dy - dx;
  while (x < x1)
  {
    if (p >= 0)
    {
      putpixel(x, y, WHITE);
      y++;
      p = p + 2 * dy - 2 * dx;
    }
    else
    {
      putpixel(x, y, WHITE);
      p = p + 2 * dy;
    }
    x++;
  }
}

void drawlinev(int x0, int y0, int x1, int y1)
{
  int dx, dy, p, x, y;
  dx = x1 - x0;
  dy = y1 - y0;
  x = x0;
  y = y0;
  p = 2 * dx - dy;
  while (y < y1)
  {
    putpixel(x, y, WHITE);
    if (p >= 0)
    {
      x++;
      p = p + 2 * dx - 2 * dy;
      y = 2 * dx - dy;
    }
    else
    {
      y++;
      p = p + 2 * dx;
    }
  }
}

void drawAxis()
{
  line(0, 240, 640, 240);
  line(320, 0, 320, 640);
}

void rotate()
{
  for (int i = 0; i < 4; i++)
  {
    coordinates[i][0] -= 320;
    coordinates[i][1] -= 240;
    coordinates[i][0] = (int)((0.741 * coordinates[i][0]) + (0.741 * coordinates[i][1]));
    coordinates[i][1] = (int)((0.741 * coordinates[i][1]) - (0.741 * coordinates[i][0]));
    coordinates[i][0] += 320;
    coordinates[i][1] += 240;
  }
}

void drawRectangle()
{
  // drawline(coordinates[0][0], coordinates[0][1], coordinates[3][0], coordinates[3][1]);
  // drawline(coordinates[1][0], coordinates[1][1], coordinates[2][0], coordinates[2][1]);
  for (int i = 0; i < 4; i++)
  {
    // if((coordinates[(i + 1) % 4][1]-coordinates[i % 4][1])/(coordinates[(i + 1) % 4][0]-coordinates[i % 4][0])<1)
    //   drawlineh(coordinates[i % 4][0], coordinates[i % 4][1], coordinates[(i + 1) % 4][0], coordinates[(i + 1) % 4][1]);
    // else
    //   drawlinev(coordinates[i % 4][0], coordinates[i % 4][1], coordinates[(i + 1) % 4][0], coordinates[(i + 1) % 4][1]);
    line(coordinates[i % 4][0], coordinates[i % 4][1], coordinates[(i + 1) % 4][0], coordinates[(i + 1) % 4][1]);
  }
}

int main()
{
  int gd = DETECT, gm;

  initgraph(&gd, &gm, NULL);
  drawAxis();
  drawRectangle();
  rotate();
  drawRectangle();
  getch();
  closegraph();
  return 0;
}