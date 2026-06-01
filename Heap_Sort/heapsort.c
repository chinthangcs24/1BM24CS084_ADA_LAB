void heapify(int a[],int n,int p){
    int c, item;
    item = a[p];
    c=2*p+1;
    while(c<=n-1){
        if(c+1<=n-1){
            if(a[c]<a[c+1]){
                c++;
            }
        }
        if(item<a[c]){
            a[p] = a[c];
            p = c;
            c = 2*p+1;
        }else{
            break;
        }
    }
    a[p] = item;
}
void build_heap(int a[],int n){
    int i;
    for(i=(n-1)/2;i>=0;i--){
        heapify(a,n,i);
    }
}
void heap_sort(int a[],int n){
    int i,temp;
    build_heap(a,n);
    for(i=n-1;i>0;i--){
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a,i,0);
    }
}
#include <stdio.h>
#include <time.h>
int main(){
    int n,i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    clock_t start = clock();
    heap_sort(a,n);
    clock_t end = clock();
    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Sorted array: ");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\nTime taken: %.6f seconds\n", timeTaken);
    return 0;
}