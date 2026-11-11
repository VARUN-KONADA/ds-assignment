/*Extend a Binary Search Tree program to support deletion. The program should create a BST, 
delete a user-specified node, correctly handle nodes with zero, one and two children, and display 
inorder traversal before and after deletion. Test the program separately for all three deletion cases. */

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
node* searcher(node* parent,int value);
int exitcode();
void freenode(node* parent);
int inputvalue();
void deletenode(node* parent,int value);
node* findparent(node* found,int *pos);

int main()
{
int choice = 0;
int value;
    while(choice != 7)
    {
        printf("\n--------MENU--------\n");
        printf("1.insert\n");
        printf("2.inorder display\n");
        printf("3.preorder display\n");
        printf("4.postorder display\n");
        printf("5.search\n");
        printf("6.delete\n");
        printf("7.exit\n");
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

            case 6: value = inputvalue();
                    deletenode(root, value);
                    break;

            case 7: return exitcode();
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
    node* found = searcher(parent,value);
    if(found != NULL)
        printf("value %d found !\n",value);
    else
        printf("value %d not found !\n",value);
}

node* searcher(node* parent,int value)
{
    if(parent == NULL)
        return NULL;
    else if(parent -> value == value)
        return parent;
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


// deletion code
void deletenode(node* prnt,int value)
{
    node* found = searcher(prnt,value);
    if(found == NULL)
        printf("value %d not found !\n",value);
    else
    {
        //if node is root
        if(found == root)
        {
            // 0 child 
            if(found -> left == NULL && found -> right == NULL)
            {
                free(found);
                root = NULL;
            }
            // 1 child
            else if(found -> left == NULL || found -> right == NULL)
            {
                node* child = (found -> left != NULL) ? found -> left : found -> right;
                free(found);
                root = child;
            }
            //2 children
            else 
            {
                //find the inorder successor (smallest in the right subtree)
                node* successor = found -> right;
                while(successor -> left != NULL)
                    successor = successor -> left;
                found -> value = successor -> value;
                deletenode(found -> right, successor -> value);
            }
        }
        //if node is not root
        else
        {
            int pos;
            node* parent = findparent(found,&pos);
            // 0 child 
            if(found -> left == NULL && found -> right == NULL)
            {
                // no children
                if(pos == 0)
                    parent -> left = NULL;
                else
                    parent -> right = NULL;
                free(found);
            }
            // 1 child
            else if(found -> left == NULL || found -> right == NULL)
            {
                node* child = (found -> left != NULL) ? found -> left : found -> right;
                if(pos == 0)
                    parent -> left = child;
                else
                    parent -> right = child;
                free(found);
            }
            //2 children
            else 
            {
                //find the inorder successor (smallest in the right subtree)
                node* successor = found -> right;
                while(successor -> left != NULL)
                    successor = successor -> left;
                found -> value = successor -> value;
                deletenode(found -> right, successor -> value);
            }
        }
    }
}

node* findparent(node* found,int *pos)
{
    node* parent = root;
    while(parent != NULL)
    {
        if(parent -> left == found)
        {
            *pos = 0;
            return parent;
        }
        else if(parent -> right == found)
        {
            *pos = 1;
            return parent;
        }
        else if(found -> value < parent -> value)
            parent = parent -> left;
        else
            parent = parent -> right;
    }
    return NULL;
}

/*
1. check if node exists 
2. if not print not found 
3. if found check if it has 0 / 1/2 child nodes 
4. if 0 free the node
5. if 1 attach its child to its parent
6. if 2 swap largest in left subtree or smallest in right subtree and delete swapped element
*/
