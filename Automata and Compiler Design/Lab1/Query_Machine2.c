#include <stdio.h>
int main()
{
  int i, current_state = 0;
  char input[10];
  printf("Input:");
  scanf("%s", input);
  for (i = 0; input[i] != '\0'; i++)
  {
    /* reject if input has a value other then 0 or 1 */
    if (input[i] != '0' && input[i] != '1')
    {
      printf("Input should contain only 0 or 1\n");
      return -1; // error
    }
    /* for current state 0
    goto to state 1 for next value as 0
    goto to state 3 for next value as 1*/
    if (current_state == 0) 
    {
      if (input[i] == '0')
        current_state = 1;
      else
        current_state = 3;
    }
    /* for current state 1
    goto to state 1 for next value as 0
    goto to state 2 for next value as 1 */
    else if (current_state == 1)
    {
      if (input[i] == '0')
        current_state = 1;
      else
        current_state = 2;
    }
    /* for current state 2
    goto to state 1 for next value as 0
    goto to state 2 for next value as 1*/
    else if (current_state == 2)
    {
      if (input[i] == '0')
        current_state = 1;
      else
        current_state = 2;
    }
    /* for current state 3
    goto to state 1 for next value as 0
    goto to state 2 for next value as 1*/
    else if (current_state == 3)
    {
      if (input[i] == '0')
        current_state = 1;
      else
        current_state = 2;
    }
  }
  if (current_state == 2)
    printf("Input Accepted\n");
  else
    printf("Input Not Accepted\n");
}