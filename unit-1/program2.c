/*A teacher wants to arrange student marks in ascending order and also measure how much 
rearrangement is necessary. Write a C program using Insertion Sort that accepts n marks, displays 
the array after every pass, counts the total number of element shifts, and displays the final sorted 
list and shift count. */

// take input marks array of n
// apply insertion sort and display every pass 
// display shift count

#include <stdio.h>
#include <stdlib.h>

void printarray(int* marks, int n);

int main()
{
    int n, key, shifts = 0;
    printf("enter number of students: ");
    scanf("%d",&n);

    int* marks = (int*) malloc(sizeof(int)*n);
    if(marks == NULL)
        {
            printf("memory not allocated !");
            return 1;
        }

    printf("\nenter marks of students: ");
    for(int i =0; i < n; i++)
        scanf("%d",&marks[i]);

    printf("\noriginal array: ");
    printarray(marks,n);

    //insertion sort
    for(int i = 1; i < n; i++)
    {
        key = marks[i];
        int j = i - 1;
        while(j >= 0 && marks[j] > marks[i])
        {
            marks[j + 1] = marks[j];
            j--;
            shifts++;
        }
        marks[j + 1] = key;
        
        printf("\nmarks in %d pass: ",i);
        printarray(marks,n);
    }

    printf("\n\nfinal list of marks : ");
    printarray(marks,n);
    printf("\ntotal shifts : %d\n",shifts);

    return 0;
}

void printarray(int* marks, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ",marks[i]);
    }
}