#include <stdio.h>
#include <graphics.h>
void makeEllipse(int xradius, int yradius, int xcentre, int ycentre)
{
  float x = 0, y = yradius, p1;
  // p1 is the decision parameter for 1:30 to 3:00
  float p0 = (yradius * yradius) - (xradius * xradius * yradius) + ((xradius * xradius) / 4);
  float dx = 2 * yradius * yradius * x;
  float dy = 2 * xradius * xradius * y;
  while (dx < dy)
  {
    putpixel(xcentre + x, ycentre + y, WHITE);
    putpixel(xcentre - x, ycentre + y, WHITE);
    putpixel(xcentre + x, ycentre - y, WHITE);
    putpixel(xcentre - x, ycentre - y, WHITE);

    if (p0 < 0)
    {
      x++;
      dx = dx + (2 * yradius * yradius);
      p0 = p0 + dx + (yradius * yradius);
    }
    else
    {
      x++;
      y--;
      dx = dx + (2 * yradius * yradius);
      dy = dy - (2 * xradius * xradius);
      p0 = p0 + dx - dy + (yradius * yradius);
    }
  }

  p1 = ((yradius * yradius) * ((x + 0.5) * (x + 0.5))) + ((xradius * xradius) * ((y - 1) * (y - 1))) - (xradius * xradius * yradius * yradius);
  while (y >= 0)
  {

    putpixel(xcentre + x, ycentre + y, WHITE);
    putpixel(xcentre - x, ycentre + y, WHITE);
    putpixel(xcentre + x, ycentre - y, WHITE);
    putpixel(xcentre - x, ycentre - y, WHITE);

    if (p1 > 0)
    {
      y--;
      dy = dy - (2 * xradius * xradius);
      p1 = p1 + (xradius * xradius) - dy;
    }
    else
    {
      y--;
      x++;
      dx = dx + (2 * yradius * yradius);
      dy = dy - (2 * xradius * xradius);
      p1 = p1 + dx - dy + (xradius * xradius);
    }
  }
}
void main()
{
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);
  int xc = 320, yc = 240, xradius = 200, yradius = 150;
  makeEllipse(xradius, yradius, xc, yc);
  getch();
  closegraph();
}