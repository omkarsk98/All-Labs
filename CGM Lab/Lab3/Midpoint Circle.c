#include <stdio.h>
#include <graphics.h>
void makeCircle(int x, int y, int radius)
{
  int p = 1 - radius;
  int xk = 0, yk = radius;
  while (yk >= xk)
  {
    putpixel(x + xk, y - yk, WHITE); // 1st octant
    putpixel(x + yk, y - xk, WHITE); // 2nd octant
    putpixel(x + yk, y + xk, WHITE); // 3rd octant
    putpixel(x + xk, y + yk, WHITE); // 4th octant
    putpixel(x - xk, y + yk, WHITE); // 5th octant
    putpixel(x - yk, y + xk, WHITE); // 6th octant
    putpixel(x - yk, y - xk, WHITE); // 7th octant
    putpixel(x - xk, y - yk, WHITE); // 8th octant
    if (p < 0)
    {
      xk++;
      p = p + 2 * xk + 1;
    }
    else
    {
      xk++;
      yk--;
      p = p + 2 * xk - 2 * yk + 1;
    }
  }
}
void main()
{
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);
  int xc = 320, yc = 240, radius = 200;
  makeCircle(xc, yc, radius);
  getch();
  closegraph();
}