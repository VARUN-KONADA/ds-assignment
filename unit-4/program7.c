/*A system stores unique integer identification numbers using a Binary Search Tree. Write a C 
program to insert n values, display inorder, preorder and postorder traversals, search for a 
specified value, and report whether it exists. Use the output to explain why inorder traversal 
produces sorted values. */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* right;
    struct Node* left;
}node;
node* root = NULL;

node* insert(node* parent,int value);
void inorder(node* parent);
void preorder(node* parent);
void postorder(node* parent);
void search(node* parent,int value);
int searcher(node* parent,int value);
int exitcode();
void freenode(node* parent);
int inputvalue();

int main()
{
int choice = 0;
int value;
    while(choice != 6)
    {
        printf("\n--------MENU--------\n");
        printf("1.insert\n");
        printf("2.inorder display\n");
        printf("3.preorder display\n");
        printf("4.postorder display\n");
        printf("5.search\n");
        printf("6.exit\n");
        printf("---------------------\n\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: value = inputvalue();
                    root = insert(root,value);
                    break;

            case 2: printf("\ninorder: ");
                    inorder(root);
                    printf("\n");
                    break;

            case 3: printf("\npreorder: ");
                    preorder(root);
                    printf("\n");
                    break;

            case 4: printf("\npostorder: ");
                    postorder(root);
                    printf("\n");
                    break;

            case 5: value = inputvalue();
                    search(root, value);
                    break;
            case 6: return exitcode();
            default: printf("enter a valid choice!");
        }
    }
    
}

node* insert(node* parent,int value)
{
    if(parent == NULL)
    {
        parent = (node*) malloc(sizeof(node));
        parent -> value = value;
        parent -> right = NULL;
        parent -> left = NULL;
    }
    else if(value > parent -> value)
        parent -> right = insert(parent -> right, value);
    else if(value < parent -> value)
        parent -> left = insert(parent -> left, value);
    
    return parent;
}

void inorder(node* parent)
{
    if(parent == NULL)
        return;
    inorder(parent -> left);
    printf(" %d ",parent -> value);
    inorder(parent -> right);
}

void preorder(node* parent)
{
    if(parent == NULL)
        return;
    printf(" %d ",parent -> value);
    preorder(parent -> left);
    preorder(parent -> right);
}

void postorder(node* parent)
{
    if(parent == NULL)
        return;
    postorder(parent -> left);
    postorder(parent -> right);
    printf(" %d ",parent -> value);
}

void search(node* parent,int value)
{
    int found = searcher(parent,value);
    if(found)
        printf("value %d found !\n",value);
    else
        printf("value %d not found !\n",value);
}

int searcher(node* parent,int value)
{
    if(parent == NULL)
        return 0;
    else if(parent -> value == value)
        return 1;
    else if( parent -> value < value)
        return searcher(parent -> right, value);

    return searcher(parent -> left, value);
}

int exitcode()
{
    printf("exiting code....\n");
    freenode(root);
    return 0;
}

void freenode(node* parent)
{
    if(parent == NULL)
        return;
    freenode(parent -> left);
    freenode(parent -> right);
    free(parent);
}

int inputvalue()
{
    int value;
    printf("enter the value :");
    scanf("%d",&value);
    return value;
}