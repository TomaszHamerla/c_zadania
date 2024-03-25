#include <stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[],int low, int high){
    int pivot = arr[high];
    int i = low -1;
    for (int j = low; j <=high-1 ; ++j) {
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}
void quickSort(int arr[],int low , int high){
    if(low<high){
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}
int binarySearch(int arr[],int left, int right,int target){
    if(right>=left){
        int mid = left + (right-left)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(arr[mid]>target){
            return binarySearch(arr,left,mid-1,target);
        }
        return binarySearch(arr,mid+1,right,target);
    }
    return -1;
}
void display(int arr[],int n){
    for (int i = 0; i < n; ++i) {
        printf("%d ",arr[i]);
    }
    printf(" \n");
}
int main(){
    int arr[]={12,11,13,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target = 13;

    display(arr,n);
    quickSort(arr,0,n-1);
    display(arr,n);

    int result = binarySearch(arr,0,n-1,target);
    printf("%d",result);
    return 0;
}