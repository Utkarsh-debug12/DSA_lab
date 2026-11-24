#include <stdio.h>
void merge(int a[],int m,int b[],int n,int ans[],int size){
    int i =0, j = 0,k = 0;
    while(i < m && j < n){
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
int main() {
  int m,n;
  printf("Enter the size of first and second array :\n ");
  scanf("%d %d",&m,&n);
  int a[m],b[n],ans[m+n];
  printf("Enter the elements of first array:\n ");
  for(int i=0;i<m;i++){
    scanf("%d",&a[i]);
  }
  printf("Enter the elements of second array: \n");
  for(int i=0;i<n;i++){
    scanf("%d",&b[i]);
  }
  merge(a,m,b,n,ans,m+n);
  printf("Your merged array : \n");
  for(int i=0;i<n+m;i++){
    printf("%d ",ans[i]);
  }
  return 0;
}