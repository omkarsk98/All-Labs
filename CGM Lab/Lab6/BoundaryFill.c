/* 
  boundary color as white-->15
  fill color as light grey-->7
*/
#include <stdio.h>
#include <graphics.h>
void boundaryFill(int x, int y, int fillColor, int boundaryColor)
{
  if (getpixel(x, y) != fillColor && getpixel(x, y) != boundaryColor)
  {
    putpixel(x, y, fillColor);
    boundaryFill(x + 1, y, fillColor, boundaryColor);
    boundaryFill(x, y + 1, fillColor, boundaryColor);
    boundaryFill(x - 1, y, fillColor, boundaryColor);
    boundaryFill(x, y - 1, fillColor, boundaryColor);
  }
}
void main(){
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);
  int x = 320, y = 240, radius = 200;
  circle(x,y,radius);
  boundaryFill(x, y, 7, 15);
  getch();
  closegraph();
}