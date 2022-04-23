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

void readTable(char* fname){
    unsigned short* buffer = readHeader(fname);
    for(int i=0;i<256;i++){
        freq[i] = (int) buffer[i];
    }
}

void writeTable(char* fname){
    unsigned short* buffer = (unsigned short*)malloc(sizeof(unsigned short)*256);
    for(int i=0;i<256;i++){
        buffer[i] = (unsigned short)freq[i];
    }
    FILE* iter= fopen(fname,"wb");
    fwrite(buffer,sizeof(unsigned short),256*sizeof(unsigned short),iter);
    fclose(iter);
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
