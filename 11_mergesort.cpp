#include <stdio.h>
void merge(int a[],int m,int b[],int n,int ans[],int size){
    int i =0, j = 0,k = 0;
    while(i < m && j<n){
        if(a[i] <= b [j]){
            ans[k]= a[i];
            i++,k++;
        }
        else {
            ans[k] = b[j];
            j++,k++;
        }
    }
    while(i < m){
        ans[k] = a[i];
        i++,k++;
    }
    while(j < n){
        ans[k] = b[j];
        j++,k++;
    }
    return;
}
void mergeSort(int arr[],int n){
    int size = n;
    if(size<2) return;
    int mid = size/2;
    int a[mid],b[size-mid];
    for(int i =0;i<size;i++){
        if(i<mid) a[i] = arr[i];
        else b[i-mid]   =  arr[i];
    }
    mergeSort(a,mid);
    mergeSort(b,size-mid);
    merge(a,mid,b,size-mid,arr,size);
    return;
}
    
int main() {
  int n;
  printf("Enter the size of array :\n ");
  scanf("%d",&n);
  int arr[n];
  printf("Enter the elements of  array:\n ");
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  mergeSort(arr,n);
  printf("Your sorted array : \n");
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
  return 0;
}