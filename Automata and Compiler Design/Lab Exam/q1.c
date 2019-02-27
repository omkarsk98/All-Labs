// Design a DFA that accepts the string of 0s and 1s and the number is divisible by 5.
#include <stdio.h>
#include <stdlib.h>
int main()
{
  int final_state = 0, current_state = 0;
  char input[20];
  printf("Input:");
  scanf("%s", input);
  for (int i = 0; input[i] != '\0'; i++)
  {
    if (input[i] != '0' && input[i] != '1')
    {
      printf("Only 0s and 1s allowed.\n");
      exit(-1);
    }
    if (current_state == 0) //for state 0
    {
      if (input[i] == '0')
        current_state = 0;
      else
        current_state = 1;
    }
    else if (current_state == 1) //for state 1
    {
      if (input[i] == '0')
        current_state = 2;
      else
        current_state = 3;
    }
    else if (current_state == 2) //for state 2
    {
      if (input[i] == '0')
        current_state = 4;
      else
        current_state = 0;
    }
    else if (current_state == 3) //for state 3
    {
      if (input[i] == '0')
        current_state = 1;
      else
        current_state = 2;
    }
    else if (current_state == 4) //for state 4
    {
      if (input[i] == '0')
        current_state = 3;
      else
        current_state = 4;
    }
  }
  if (current_state == final_state)
    printf("Input is accepted.\n");
  else
    printf("Input is rejected.\n");
}