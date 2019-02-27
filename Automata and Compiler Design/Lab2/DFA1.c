/*
  Write a C Program for L = {awa: w belongs to {a,b}*}
*/

#include <stdio.h>
int main()
{
  int current_state = 0, i;
  char input[20];
  printf("Input:");
  scanf("%s", input);
  for (i = 0; input[i] != '\0'; i++) 
  {
    /* reject if input contains values other then 0 or 1 */
    if (input[i] != 'a' && input[i] != 'b') // reject if input has value other than 0 or 1
    {
      printf("Input should contain only a or b\n");
      return -1; // error
    }
    /* for current state 0
    go to state 1 for next value as a
    go to state 3 for next value as b*/
    if (current_state == 0)
    {
      if (input[i] == 'a')
        current_state = 1;
      else
        current_state = 3;
    }
    /* for current state 1
    go to state 2 for next value as a
    remain at state 1 for next value as b*/
    else if(current_state==1)
    {
      if (input[i] == 'a')
        current_state = 2;
      else
        current_state = 1;
    }
    /* for current state 2
    go to state 1 for next value as b
    remain at state 2 for next value as a*/
    else if(current_state==2)
    {
      if (input[i] == 'a')
        current_state = 2;
      else
        current_state = 1;
    }
    /* for current state 3
    remain at state 3 for next value as a or b*/
    else {
      if(input[i]=='a' || input[i]=='b')
        current_state = 3;
    }
  }
  if (current_state == 2) //if current state is ending where it should end
    printf("Accepted\n");
  else // else reject
    printf("Not Accepted\n");
  return 1; //no error
}