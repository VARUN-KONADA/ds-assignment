/*A department maintains student roll numbers dynamically. Write a C program using a Singly 
Linked List to create the list, insert at the beginning and end, search for a specified roll number, 
delete a specified roll number, and display the updated list after each operation. Handle the case 
when a requested roll number is not available. */


#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* next;
}node;
node* head = NULL;

void insertBeginning();
void insertEnd();
void delete();
void search();
void display();
int exitcode();
int main()
{
    int choice = 0;
    while(choice != 6)
    {
        printf("\n-----MENU-----\n");
        printf("1.insert at beginning\n");
        printf("2.insert at end\n");
        printf("3.search\n");
        printf("4.delete\n");
        printf("5.display\n");
        printf("6.exit\n");
        printf("---------------\n\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: insertBeginning();
                    break;
            case 2: insertEnd();
                    break;
            case 3: search();
                    break;
            case 4: delete();
                    break;
            case 5: display();
                    break;
            case 6: return exitcode();
            default: printf("enter a valid choice!");
        }
    }
    
}

void insertBeginning()
{
    int value;
    node* newNode = (node*) malloc(sizeof(node));
    printf("enter the value to insert : ");
    scanf("%d",&value);
    newNode -> value = value;
    newNode -> next = head;
    head = newNode;
    display();
}

void insertEnd()
{
    int value;
    node* temp = head;
    node* newNode = (node*) malloc(sizeof(node));
    printf("enter the value to insert : ");
    scanf("%d",&value);
    newNode -> value = value;
    if(head == NULL)
        head = newNode;
    else
    {
        while(temp -> next != NULL)
            temp = temp -> next;
        temp -> next = newNode;
    }

    newNode -> next = NULL;
    display();
}

void search()
{
    int value;
    node* temp = head;
    if(head == NULL)
        printf("list is empty!\n");
    else
    {
        printf("enter the value to search : ");
        scanf("%d",&value);
        while(temp != NULL)
        {
            if(temp -> value == value)
            {
                printf("value %d found !\n",value);
                return;
            }
            temp = temp -> next;
        }
        printf("value %d not found !\n",value);
    }
}

void delete()
{
    int value;
    node* temp = head;
    if(head == NULL)
        printf("list is empty!\n");

    else
    {
        printf("enter the value to delete : ");
        scanf("%d",&value);

        if(head -> value == value)
        {
            temp = head;
            head = head -> next;
            free(temp);
            display();
            return;
        }
        while(temp != NULL && temp -> next -> value != value)
        {
            temp = temp -> next;
        }
        if(temp == NULL)
            printf("value %d not found !\n",value);
        else
        {
            node* found = temp -> next;
            temp -> next = found -> next;
            free(found);
            display();
        }
    }
}

void display()
{
    if(head == NULL)
    {
        printf("list is empty!\n");
        return;
    }
    node* temp = head;
    printf("current roll numbers in list: ");

    while(temp != NULL)
    {
        printf(" %d ",temp -> value);
        temp = temp -> next;
    }
    printf("\n\n");
    
}

int exitcode()
{
    node* temp;
    while(head != NULL)
    {
        temp = head;
        head = head -> next;
        free(temp);
    }
    return 0;
}