#define CAP 256
//table
int freq[CAP];
//default all values to 0
void clean(){
    memset(freq, 0, sizeof(freq));
}
//hash function
int hash(char ch){
    return (int)ch;
}
//insert a string into freq
void insert(char str[])
{
    int n = strlen(str);
    clean();
    for (int i = 0; i < n; i++){
        freq[hash(str[i])]+=1; 
    }
}

int SIZE = 0;
typedef struct countC
{
    int charecter;
    int count;
}countC;
void setSize(){
    int s =0;
    for(int i=0;i<256;i++){
        if(freq[i]!=0){
            s++;
        }
    }
    SIZE = s;
}
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

//debug the hashtable
void debugTable(){
    printf("\nchar\tcount\n");
    for(int i=0;i<CAP;i++){
        if(freq[i]!=0){
            printf("%d\t%d\n",i,freq[i]);
        }
    }
}