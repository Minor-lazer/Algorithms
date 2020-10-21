#include <stdio.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;
void enqueue(int x)
{
    if ((rear + 1) % N == front)
    {
        printf("Queue is full / Overflow");
    }

    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Underflow\n");
    }
    else if (front == rear)
    {
        printf("The removed Element is %d", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("The removed Element is %d", queue[front]);
        front = (front + 1) % N;
    }
}
void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue is: ");
        while (i != rear)
        {
            printf("%d ", queue[i]);
            i = (i + 1) % N;
        }
        printf("%d ",queue[rear]);
    }
}
int main()
{
    int choice;
    do
    {
        printf("\n..................................................MENU...............................................");
        printf("\n1.To enter element in the queue...");
        printf("\n2.To remove an element from the Queue...");
        //printf("\n3.To check the first element of the queue....");
        printf("\n3.To display element of the Queue...");
        printf("\n......................\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter element you want to enter: ");
            int x;
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            printf("Element Removed\n");
            break;
        case 3:
            display();
            break;

        default:
            break;
        }
    } while (choice != 0);
}
