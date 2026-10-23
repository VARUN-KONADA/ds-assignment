/*A company stores employee IDs in ascending order. Write a C program that accepts n employee 
IDs, searches for a required ID using Binary Search, displays its position when found, reports 
when it is absent, and counts the number of comparisons. Test the program for both successful 
and unsuccessful searches. */

// assuming users gives input in ascending order
#include <stdio.h>
int main()
{
    int n, find;
    int count = 0;
    // get no.of IDs
    printf("Enter number of employee IDs : ");
    scanf("%d",&n);
    int  id[n];

    // get all IDs
    printf("Enter employee IDs : \n");
    for(int i = 0; i < n; i++ )
        scanf("%d",&id[i]);
    
    // checking if its in ascending order or not
    for(int i = 0; i < n - 1; i++)
    {
        if(id[i] > id[i+1])
        {
            printf("IDs entered are not in ascending order");
            return 1;
        }
    }
    
    printf("Enter employee ID to search : ");
    scanf("%d",&find);

    // search using binary search and count comparisons
    int mid,top,bottom;
    top = n-1;
    bottom = 0;
    
    while(top >= bottom)
    {
        count++;
        mid = (top + bottom)/2;
        if(id[mid] == find)
        {    
            printf("ID found at %d !\n",mid + 1);
            printf("Number of comparisons it took : %d",count);
            break;
        }
        else if(id[mid] > find)
            top = mid - 1;
        else if(id[mid] < find)
            bottom = mid + 1;
    }
    // print postion if exists or report 
    if(top < bottom)
    {
        printf("ID not found !\n");
        printf("Number of comparisons it took : %d",count);
    }

    return 0;
}
