// Implementation of Binary search on sorted array
#include <stdio.h>

int binary_search(int a[],int size,int key)
{
    int low=0;
    int high=size-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]==key)
        {
            return mid;
        }
        else if (a[mid]<key)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}
int main()
{
    int size, target, ex;
    printf("Enter the no. of elements:");
    scanf("%d", &size);
    int a[size];
    printf("Enter Elements in the array(sorted):");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    while (1)
    {
        printf("Enter target element to be searched:");
        scanf("%d", &target);
        int position = binary_search(a, size, target);
        if (position != -1)
        {
            printf("\nElement found at index %d\n", position);
        }
        else
        {
            printf("\nElement not found.\n");
        }
        printf("To exit enter -1:");
        scanf("%d", &ex);
        if (ex == -1)
        {
            break;
        }
    }
    return 0;
}