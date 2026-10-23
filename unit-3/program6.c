/*Develop a C program for a Doubly Linked List representing a sequence of web pages visited by a 
user. The program should insert a new page, move forward and backward, delete a specified 
page, and display the pages from first-to-last and last-to-first while handling beginning and end 
conditions correctly. */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int page;
    struct Node* prev;
    struct Node* next;
}node;

node* head = NULL;
node* tail = NULL;
node* current = NULL;

void createpage();
node* createnode();
void moveforward();
void movebackward();
void deletepage();
void displayftl();
void displayltf();
int exitcode();

int main()
{
    int choice = 0;
    while(choice != 7)
    {
        printf("\n--------------MENU--------------\n");
        printf("1.create a new page\n");
        printf("2.move forward\n");
        printf("3.move backward\n");
        printf("4.delete page\n");  
        printf("5.display from first to last\n");  
        printf("6.display from last to first\n"); 
        printf("7.exit\n");   
        printf("--------------------------------\n");
        printf("enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: createpage();
                    break;
            case 2: moveforward();
                    break;
            case 3: movebackward();
                    break;
            case 4: deletepage();
                    break;
            case 5: displayftl();
                    break;
            case 6: displayltf();
                    break;
            case 7: return exitcode();
            default: printf("invalid choice !\n");
        }
    }

}

void createpage()
{
    printf("note that page is create after the current page and will the current page !!\n");
    node* newNode = createnode();
    if(current == NULL)
    {
        head = tail = current = newNode;
    }
    else if(current == tail)
    {
        newNode -> prev = tail;
        tail -> next = newNode;
        current = tail = newNode;
    }
    else
    {
        newNode -> next = current -> next;
        newNode -> prev = current;
        current -> next = newNode;
        newNode -> next -> prev = newNode;
    }
}

node* createnode()
{
    int value;
    node* newNode = (node*) malloc(sizeof(node));
    printf("enter the value of page : ");
    scanf("%d",&value);
    newNode -> page = value;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}

void moveforward()
{
    if(current == tail)
    {
        printf("cant move more further , this is the last page!");
    }
    else
    {
        current = current -> next;
        printf("current page %d",current -> page);
    }
}

void movebackward()
{
    if(current == head)
    {
        printf("cant move more backward , this is the first page!");
    }
    else
    {
        current = current -> prev;
        printf("current page %d",current -> page);
    }
}

void deletepage()
{
    int value;
    node* temp = head;
    if(current == NULL)
        printf("there are no pages!\n");

    else
    {
        printf("enter the value to delete : ");
        scanf("%d",&value);

        while(temp != NULL && temp -> page != value)
        {
            temp = temp -> next;
        }
        if(temp == NULL)
            printf("value %d not found !\n",value);
        else
        {
            if(head == temp && current == temp && tail == temp)
            {
                head = tail = current = NULL;
                free(temp);
            }
            else if(head == temp )
            {
                if(current == temp)
                    current = current -> next;
                    
                head = head -> next;
                head -> prev = NULL;
                free(temp);
            }
            else if(tail == temp )
            {
                if(current == temp)
                    current = current -> prev;
                    
                tail = tail -> prev;
                tail -> next = NULL;
                free(temp);
            }
            else if(current == temp)
            {
                current = current -> prev;
                temp -> prev -> next = temp -> next;
                temp -> next -> prev = temp -> prev;
                free(temp);
            }
            else
            {
                temp -> prev -> next = temp -> next;
                temp -> next -> prev = temp -> prev;
                free(temp);
            }
        }
    }
}

void displayftl()
{
    node* temp = head;
    if(current == NULL)
    {
        printf("list is empty!");
    }
    else
    {
        printf("displaying from first to last \n");
        while(temp != NULL)
        {
            printf(" %d ",temp -> page);
            temp = temp -> next;
        }
    }
}

void displayltf()
{
    node* temp = tail;
    if(current == NULL)
    {
        printf("list is empty!");
    }
    else
    {
        printf("displaying from last to first \n");
        while(temp != NULL)
        {
            printf(" %d ",temp -> page);
            temp = temp -> prev;
        }
    }
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