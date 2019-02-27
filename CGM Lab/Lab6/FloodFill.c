/* 
  boundary color as white-->15
  fill color as light grey-->7
*/
#include <stdio.h>
#include <graphics.h>
void floodFill(int x, int y, int oldColor, int newColor)
{
  if (getpixel(x, y) == oldColor)
  {
    putpixel(x, y, newColor);
    floodFill(x + 1, y, oldColor, newColor);
    floodFill(x - 1, y, oldColor, newColor);
    floodFill(x, y + 1, oldColor, newColor);
    floodFill(x, y - 1, oldColor, newColor);
  }
}
void main()
{
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);
  int x = 320, y = 240, radius = 200;
  circle(x, y, radius);
  floodFill(x, y, 0, 7);
  getch();
  closegraph();
}