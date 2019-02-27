// Design a DFA that accepts the string of ps and qs and has ppqq.
#include <stdio.h>
#include <stdlib.h>
int main()
{
  int final_state = 5, current_state = 1;
  char input[20];
  printf("Input:");
  scanf("%s", input);
  for (int i = 0; input[i] != '\0'; i++)
  {
    if (input[i] != 'p' && input[i] != 'q')
    {
      printf("Only ps and qs allowed.\n");
      exit(-1);
    }
    if (current_state == 1) //for state 1
    {
      if (input[i] == 'p')
        current_state = 2;
      else
        current_state = 1;
    }
    else if (current_state == 2) //for state 2
    {
      if (input[i] == 'p')
        current_state = 3;
      else
        current_state = 1;
    }
    else if (current_state == 3) //for state 3
    {
      if (input[i] == 'p')
        current_state = 3;
      else
        current_state = 4;
    }
    else if (current_state == 4) //for state 4
    {
      if (input[i] == 'p')
        current_state = 2;
      else
        current_state = 5;
    }
    else if (current_state == 5) //for state 5
    {
      if (input[i] == 'p')
        current_state = 5;
      else
        current_state = 5;
    }
  }
  if (current_state == final_state)
    printf("Input is accepted.\n");
  else
    printf("Input is rejected.\n");
}