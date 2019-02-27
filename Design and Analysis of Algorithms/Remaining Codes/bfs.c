#include <stdio.h>
#include <stdlib.h>

#define MAX 100

#define initial 1
#define waiting 2
#define visited 3

int n;
int adj[MAX][MAX];
int state[MAX];
void create_graph();
void BF_Traversal();
void BFS(int v);

int queue[MAX], front = -1, rear = -1;
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();

int main()
{
    create_graph();
    BF_Traversal();
    return 0;
}

void BF_Traversal()
{
    int v;

    for (v = 0; v < n; v++)
        state[v] = initial;

    printf("Enter Start Vertex for BFS: \n");
    scanf("%d", &v);
    BFS(v);
}

void BFS(int v)
{
    int i;

    insert_queue(v);
    state[v - 1] = waiting;

    while (!isEmpty_queue())
    {
        v = delete_queue();
        printf("%d ", v);
        state[v - 1] = visited;

        for (i = 0; i < n; i++)
        {
            if (adj[v - 1][i] == 1 && state[i] == initial)
            {
                insert_queue(i + 1);
                state[i] = waiting;
            }
        }
    }
    printf("\n");
}

void insert_queue(int vertex)
{
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else
    {
        if (front == -1)
            front = 0;
        rear = rear + 1;
        queue[rear] = vertex;
    }
}

int isEmpty_queue()
{
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}

int delete_queue()
{
    int delete_item;
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        exit(1);
    }

    delete_item = queue[front];
    front = front + 1;
    return delete_item;
}

void create_graph()
{
    int count, max_edge, origin, destin;

    printf("Enter number of vertices : ");
    scanf("%d", &n);
    max_edge = n * (n - 1);

    for (count = 1; count <= max_edge; count++)
    {
        printf("Enter edge %d( -1 -1 to quit ) : ", count);
        scanf("%d %d", &origin, &destin);

        if ((origin == -1) && (destin == -1))
            break;

        if (origin > n || destin > n || origin <= 0 || destin <= 0)
        {
            printf("Invalid edge!\n");
            count--;
        }
        else
        {
            adj[origin - 1][destin - 1] = 1;
        }
    }
}
/* 
Sample Input: 
5
1 2
1 4
4 5
5 3
-1 -1
1

Output:
1 2 4 5 3
*/