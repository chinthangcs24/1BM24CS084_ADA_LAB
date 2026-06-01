#include<stdio.h>
#include <time.h>

void mergeSort(int arr[], int n);
void merge(int arr[],int a[], int al, int b[], int bl);
void main(){
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = 7;
    
    clock_t start = clock();
    mergeSort(arr,7);
    clock_t end = clock();
    
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by mergeSort: %f seconds\n", time_taken);
    
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void mergeSort(int arr[], int n){
    if(n==1) return;
    int al = n/2;
    int bl = n-al;
    int a[al];
    int b[bl];
    for(int i=0;i<al;i++){
        a[i] = arr[i];
    }
    for(int i=0;i<bl;i++){
        b[i] = arr[al+i];
    }
    mergeSort(a,al);
    mergeSort(b,bl);
    merge(arr,a,al,b,bl);
    
}
void merge(int arr[],int a[], int al, int b[], int bl){
    int i=0;
    int j=0;
    int k=0;
    while(i<al && j<bl){
        if(a[i]<b[j]){
            arr[k++] = a[i++];
        }
        else{
            arr[k++] = b[j++];
        }
    }
    while(i<al){
        arr[k++] = a[i++];
    }
    while(j<bl){
        arr[k++] = b[j++];
    }
}