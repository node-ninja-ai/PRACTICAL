#include<stdio.h>
#include<stdlib.h>
void linear(int arr[],int n)
{
    int key;
    int flag=0;
    printf("enter the key value that u wanna to search\n");
    scanf("%d",&key);
    for(int i=0;i<n;i++)
    {
        flag=0;
        if(arr[i]==key)
        {
            printf("element is found at position %d\n",i);
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("elment is not found \n");
    }
    
}
int sentinel(int arr[],int n)
{
    int key,i=0;
    arr[n]=key;
    printf("enter the key value that u wanna to search\n");
    scanf("%d",&key);
    while(arr[i]!=key)
    {
        i++;
    }
    if(i==n) return -1;
    else return i;
}
void binary(int arr[],int n)
{
    int low=0,key;
    printf("entered your key value\n");
    scanf("%d",&key);
    int high=n-1;
    int comcount=0;
    int mid=(low+high)/2;
    while(low<=high)
    {
        comcount++;
        if(arr[mid]==key)
        {
            printf("elemnt is found at %d and their comparision is %d\n",mid+1,comcount);
            break;
        }
        if(arr[mid]<key)
        low++;
        else 
        high--;
        mid=(low+high)/2;
    }
    
}
int main()
{
    int ch,n;
    printf("enter size \n");
    scanf("%d",&n);
    int arr[n];
    printf("enter all the dta\n");
    for(int i=0;i<n;i++)
    {
         
        scanf("%d",&arr[i]);
    }
    printf("\nAll elements that u entered are\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
    while(1)
    {
        printf("1:Linear search\n2:sentinel search\n3:binary search\n4:exit\n");
        printf("enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:linear(arr,n);break;
            case 2:int pos=sentinel(arr,n); 
            if(pos==-1)
            {
                printf("element is not found\n");
            }
            else
            printf("element is found at %d\n",pos);
            
            
            break;
            case 3:binary(arr,n);break;
            case 4:exit(1);break;
            default:printf("choose your choice correctly\n");
        }
        
    }
}
