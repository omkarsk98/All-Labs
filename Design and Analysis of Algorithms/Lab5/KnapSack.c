 #include <stdio.h>
float prevMax = 9999;
void getInput(float array[], int size, char string[])
{
  printf("%s\n", string);
  for (int i = 0; i < size; i++)
  {
    printf("%d: ", i + 1);
    scanf("%f", &array[i]);
  }
}
void printArray(int array[], int size)
{
  for (int i = 0; i < size; i++)
    printf("%d: ", array[i]);
}
int getNextMax(float array[], int size)
{
  float max = 0.00;
  int maxIndex = 0;
  for (int i = 0; i < size; i++)
  {
    if (array[i] > max && array[i] < prevMax)
    {
      maxIndex = i; //stores the index of maximum value
      max = array[i];
    }
  }
  prevMax = array[maxIndex];
  return maxIndex;
}
void fillSack(float sack[], float weights[], float profitToWeight[], float capacity, int size)
{
  float sum = 0;
  int j;
  float count;
  while (sum <= capacity)
  {
    j = getNextMax(profitToWeight, size);
    count = (capacity - sum) / weights[j];
    sum = sum + weights[j];
    // check if its 1 or less than 1
    if (count > 1.00)
      count = 1.00; //adjust count if it is greater than 1
    sack[j] = count;
  }
}
void main()
{
  int objects;
  float capacity;
  printf("Capacity of sack:");
  scanf("%f", &capacity);
  printf("Number of objects:");
  scanf("%d", &objects);
  float profit[objects], weight[objects];
  float profitToWeight[objects], sack[objects];
  // put count of all objects as 0
  for (int i = 0; i < objects; i++)
    sack[i] = 0;
  // get input for profits
  getInput(profit, objects, "Input for profits");
  //get input for weights
  getInput(weight, objects, "Input for Weights");
  // calculate profit to weight ratio
  for (int i = 0; i < objects; i++)
  {
    profitToWeight[i] = profit[i] / weight[i];
  }
  //start filling up the sack
  fillSack(sack, weight, profitToWeight, capacity, objects);
  //find total profit
  float totalProfit = 0;
  for (int i = 0; i < objects; i++)
  {
    totalProfit += (profit[i]*sack[i]);
  }
  printf("Total profit is %.2f.\n",totalProfit);
}