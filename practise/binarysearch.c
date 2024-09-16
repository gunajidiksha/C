#include<stdio.h>

int binsrc(int x[] , int low , int high , int key){
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(x[mid]==key){
            return mid;
        }else if(x[mid]<key){
            low=mid+1;
        }else{
            high=mid-1;
        }                           
    }
    return -1;
}

int main()
{
    int a[20] , n , key , succ;
    printf("Enter number of elements : ");
    scanf("%d" , &n);

    printf("Enter elements in ascending order : \n");
    for(int i=0 ; i<n ; i++){
        scanf("%d" , &a[i]);
    }

    printf("Enter key element to be searched : ");
    scanf("%d" , &key);

    succ= binsrc(a,0,n-1,key);
    if(succ>=0){
        printf("Element found at position %d\n", succ+1);
    }else{
        printf("Element not found!\n");
    }
    return 0;
}