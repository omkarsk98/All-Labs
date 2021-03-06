#include <stdio.h>
#include <graphics.h>

void bresenhamCircle(int xc, int yc, int r)
{
  int x = 0, y = r;
  int d = 3 - 2 * r;
  while (y >= x)
  {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
    x++;
    if (d > 0)
    {
      y--;
      d = d + 4 * (x - y) + 10;
    }
    else
      d = d + 4 * x + 6;
    }
}

int main()
{
  int xc = 320, yc = 240, radius = 200;
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);
  bresenhamCircle(xc, yc, radius);
  getch();
  closegraph();
  return 0;
}