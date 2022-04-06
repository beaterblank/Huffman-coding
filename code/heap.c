#include "arrify.c"

void swap(countC* arr,int i,int j){
    countC temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void heapify(countC* arr,int i)
{
    int smallest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2;
    if (l < SIZE && arr[l].count < arr[smallest].count)smallest = l;
    if (r < SIZE && arr[r].count < arr[smallest].count)smallest = r;
    if (smallest != i) {
        swap(arr,i,smallest);
        heapify(arr,smallest);
    }
}
void buildHeap(countC* arr)
{
    int startIdx = (SIZE / 2) - 1;

    for (int i = startIdx; i >= 0; i--) {
        heapify(arr,i);
    }
}
countC getMin(countC* arr){
    SIZE = SIZE - 1;
    countC temp = arr[0];
    arr[0]=arr[SIZE];
    buildHeap(arr);
    return temp;
}

void debugHeap(countC* arr){
    printf("\nchar\tcount\n");
    for(int i=0;i<SIZE;i++){
        printf("%d\t%d\n",arr[i].charecter,arr[i].count);
    }
}