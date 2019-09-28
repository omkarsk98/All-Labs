
#include <stdio.h>
// #include <conio.h>
#include <graphics.h>
layout() /*LAYOUT OF THE GAME*/
{
  setbkcolor(WHITE);
  setcolor(RED);
  line(300, 200, 450, 200);
  line(300, 250, 450, 250);
  line(400, 150, 400, 300);
  line(350, 150, 350, 300);
  return 0;
}
void main()
{
  int gd = DETECT, d = 0, ans = 1, aa = 20, choice, count = 0, dec = 1;
  int counting1 = 0, counting2 = 0, counting3 = 0, counting4 = 0, counting5 = 0, counting6 = 0, counting7 = 0, counting8 = 0, count1 = 0, count4 = 0, count5 = 0, count6 = 0, count7 = 0, count8 = 0, count2 = 0, count3 = 0;
  int gm;
  initgraph(&gd, &gm, "C://turboC3//BGI");
  cleardevice();
  layout();
  while (d == 0)
  {
    choice = getch();
    /*this if else statement is used not to use any other keys except 0-9*/
    if (choice > 48 && choice < 58)
    {
      dec = 1;
    }
    /*the choice variable will convert choice value to ascii value and mark x or 0 in following places*/
    switch (choice)
    {
    case 49:
    {
      if (ans == 1)
      {
        outtextxy(325, 175, "X");
        counting1++; /*count1-8 and counting1-8 variables are used to confirm whether any x or 0 are completed*/
        counting4++;
        counting7++;
      }
      else
      {
        outtextxy(325, 175, "0");
        count1++;
        count4++;
        count7++;
      }
      break;
    }
    case 50:
    {
      if (ans == 1)
      {
        outtextxy(375, 175, "X");
        counting1++;
        counting5++;
      }
      else
      {
        outtextxy(375, 175, "0");
        count1++;
        count5++;
      }
      break;
    }
    case 51:
    {
      if (ans == 1)
      {
        outtextxy(425, 175, "X");
        counting1++;
        counting6++;
        counting8++;
      }
      else
      {
        outtextxy(425, 175, "0");
        count1++;
        count6++;
        count8++;
      }
      break;
    }
    case 52:
    {
      if (ans == 1)
      {
        outtextxy(325, 225, "X");
        counting4++;
        counting2++;
      }
      else
      {
        outtextxy(325, 225, "0");
        count4++;
        count2++;
      }
      break;
    }
    case 53:
    {
      if (ans == 1)
      {
        outtextxy(375, 225, "X");
        counting7++;
        counting8++;
        counting2++;
        counting5++;
      }
      else
      {
        outtextxy(375, 225, "0");
        count7++;
        count8++;
        count2++;
        count5++;
      }
      break;
    }
    case 54:
    {
      if (ans == 1)
      {
        outtextxy(425, 225, "X");
        counting2++;
        counting6++;
      }
      else
      {
        outtextxy(425, 225, "0");
        count2++;
        count6++;
      }
      break;
    }
    case 55:
    {
      if (ans == 1)
      {
        outtextxy(325, 275, "X");
        counting4++;
        counting3++;
        counting8++;
      }
      else
      {
        outtextxy(325, 275, "0");
        count4++;
        count3++;
        count8++;
      }
      break;
    }
    case 56:
    {
      if (ans == 1)
      {
        outtextxy(375, 275, "X");
        counting3++;
        counting5++;
      }
      else
      {
        outtextxy(375, 275, "0");
        count3++;
        count5++;
      }
      break;
    }
    case 57:
    {
      if (ans == 1)
      {
        outtextxy(425, 275, "X");
        counting7++;
        counting3++;
        counting6++;
      }
      else
      {
        outtextxy(425, 275, "0");
        count7++;
        count3++;
        count6++;
      }
      break;
    }
    default:
    {
      outtextxy(300, 50, "please enter correct number");
      count--;
      dec = 0;
    }
    }
    aa = aa + 20;
    count++; /*count variable is used to count the iteration of loop*/
    /*THIS IF-ELSE STATEMENT IS USED TO DECIDE THE WINNER BY COUNTING THE COUNTING AND COUNT VARIABLE*/
    if (counting1 == 3 || counting2 == 3 || counting3 == 3 || counting4 == 3 || counting5 == 3 || counting6 == 3 || counting7 == 3 || counting8 == 3)
    {
      outtextxy(500, 200, "X WINS!!");
      getch();
      cleardevice();
      exit(0);
    }
    if (count1 == 3 || count2 == 3 || count3 == 3 || count4 == 3 || count5 == 3 || count6 == 3 || count7 == 3 || count8 == 3)
    {
      outtextxy(500, 200, "0 WINS!!");
      getch();
      cleardevice();
      exit(0);
    }
    if (dec == 1)
    { /*THIS IF ELSE USED TO INSTRUCT WHO'S CHANCE TO PLAY*/
      if (ans == 1)
      {
        outtextxy(50, aa, "0-CHANCE");
      }
      else
      {
        outtextxy(50, aa, "X-CHANCE");
      }
    }
    if (count % 2 != 0)
    {
      ans = 0;
    } /*THIS IF ELSE USED TO SWITCH USER BETWEEN X AND 0*/
    else
    {
      ans = 1;
    }
    if (count == 9)
    {
      outtextxy(300, 70, "GAME DRAW!!!");
      d = 1; /*here d=1 is used to exit the main loop*/
    }
  }
  getch();
  closegraph();
}