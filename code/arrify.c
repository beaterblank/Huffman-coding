#include "countC.c"
#include "hashtable.c"
//global size variable to keep track of minheap size
int SIZE = 0;
//reset size
void setSize(){
    int s =0;
    for(int i=0;i<256;i++){
        if(freq[i]!=0){
            s++;
        }
    }
    SIZE = s;
}
//convert the hashtable into usable array
countC* arrify(){
    setSize();
    countC* arr = (countC*)malloc(sizeof(countC)*SIZE);
    int top = -1;
    for(int i=0;i<256;i++){
        if(freq[i]!=0){
            countC temp;
            temp.charecter = i;
            temp.count = freq[i];
            arr[++top]=temp;
        }
    }
    return arr;
}
//swap contents of array
void swap(countC* arr,int i,int j){
    countC temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}