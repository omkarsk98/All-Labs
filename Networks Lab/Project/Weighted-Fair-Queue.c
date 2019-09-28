#include <stdio.h>
#include <stdbool.h>
int remaining; // to mantain the count of packets that are not completely sent.
int getMin(int array[], int size)
{
  /* returns index of the smallest packet */
  int min = 10000;
  int minIndex = 0;
  for (int i = 0; i < size; i++)
  {
    if (array[i] < min && array[i] != 0)
    {
      min = array[i];
      minIndex = i;
    }
  }
  return minIndex;
}

void sendPackets(int packets[], int priorities[], int size, int std_packet_size)
{
  /* decrement the packet size according to the priorities in order to completely send the packet which is least remaining in terms of its size */
  for (int i = 0; i < size; i++)
  {
    // dont print it if its already printed previously
    bool print = true;
    if (packets[i] == 0)
    {
      /* not to print the packet if its already empty and adjust the count of remaining packets */
      print = false;
      remaining++;
    }
    // get packets int terms of sizes according to its priority
    packets[i] = packets[i] - (priorities[i] * std_packet_size);
    if (packets[i] <= 0)
    {
      /* set the value of packet size to 0 if it becomes negative, because packet size cannot be negative */
      if (print)
      {
        /* print the packet if it has git empty just now */
        if (remaining > 1)
          printf("%d,\t", i + 1);
        else
          printf("%d\n", i + 1);
      }
      packets[i] = 0;
      remaining--;
    }
  }
}

void printStats(int packets[], int size, int priorities[])
{
  /* 
    This function will print the stats of the packets remaining.
    This function was just for debugging. Not used otherwise.
  */
  printf("\n-------------------------------------\n");
  printf("No.\tPacketSize\t Priority\n");
  for (int i = 0; i < size; i++)
  {
    printf("%d \t %d \t\t %d\n", i + 1, packets[i], priorities[i]);
  }
}

void main()
{
  int senders = 6, smallest_packet;
  remaining = senders;
  int packets[6] = {10, 6, 4, 20, 30, 5}; // sizes of individual packets
  int priorities[6] = {2, 1, 1, 3, 4, 1}; // priorities of individual packets
  printStats(packets, senders, priorities);
  printf("\nSending Packets as follows:\n");
  while (remaining > 0)
  {
    /* keep sending the packets till no packet is remaining */
    smallest_packet = packets[getMin(packets, senders)];
    sendPackets(packets, priorities, senders, smallest_packet);
  }
  // printf("\n");
}