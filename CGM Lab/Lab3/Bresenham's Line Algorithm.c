#include <stdio.h>
#include <graphics.h>

void drawline(int x0, int y0, int x1, int y1)
{
  int dx, dy, p, x, y;
  dx = x1 - x0;
  dy = y1 - y0;
  if((dy/dx)>=1) {
    printf("Slope is greater than 1");
    return;
  }
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

int main()
{
  int error, x0, y0, x1, y1;
  int gd = DETECT, gm;

  initgraph(&gd, &gm, NULL);

  x0 = 2, y0 = 3, x1 = 400, y1 = 350;
  drawline(x0, y0, x1, y1);
  printf("\nPress any key to exit...");
  getch();
  closegraph();
  return 0;
}