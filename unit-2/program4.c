/*A service centre uses a fixed-size request buffer in which released positions must be reused. 
Write a C program to implement a Circular Queue using an array with insertion, deletion, display, 
overflow and underflow operations. Demonstrate that positions freed after deletion can be reused 
for new requests. */

#include <stdio.h>

#define SIZE 5
int buffer[SIZE];
int front = -1;
int rear = -1;


void enqueue();
void dequeue();
void display();
int isoverflow();
int isunderflow();

int main()
{
    int choice = 0;
    while(choice != 4)
    {
        printf("-----MENU-----\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("--------------\n");
        printf("enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
                break;
            default:
                printf("Invalid choice given !\n\n");
        }

    }

}

void enqueue()
{
    int value;
    printf("Enter value to insert :");
    scanf("%d",&value);
    if(isoverflow())
        printf("request buffer is overflowed!\n\n");
    else
    {
        if(front == -1)
            front++;
        rear = (rear + 1) % SIZE;
        buffer[rear] = value;
        printf("%d added successfully!\n\n",value);
    }
}

void dequeue()
{
    int value;
    if(isunderflow())
        printf("request buffer is underflowed!\n\n");
    else
    {
        value = buffer[front];
        buffer[front] = 0;

        if(front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
        
        printf("deleted %d !\n\n",value);
    }
}

void display()
{
    int temp = front;
    
    if(isunderflow())
        printf("buffer is empty!\n\n");
    else
    {
        do
        {
            if(buffer[temp] == 0)
                printf(" (empty) ");
            else
                printf(" %d ",buffer[temp]);

            temp = (temp + 1) % SIZE;
        }
        while((temp) % SIZE != front);
        printf("\n\n");

    }
}

int isoverflow()
{
    if((rear + 1) % SIZE == front)
        return 1;
    else
        return 0;
}

int isunderflow()
{
    if(front == -1)
        return 1;
    else
        return 0;
}